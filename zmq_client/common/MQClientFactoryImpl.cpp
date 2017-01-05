#include "zmq_client/MQClientFactoryImpl.h"
#include "zmq_client/MQClientApiException.h"
#include "zmq_client/StringConvert.h"
#include <new>
#include "../producer/ProducerImpl.h"
#include "../producer/OrderProducerImpl.h"
#include "../consumer/ConsumerImpl.h"
#include "../consumer/OrderConsumerImpl.h"

using namespace ZMQ_API;
using namespace ZMQ_IMPL;

Producer* MQClientFactoryImpl::createProducer(const Properties& properties)
{
    validateParam(properties, Namesrv_Addr);
	validateParam(properties, Producer_Id);

	Producer* producer = new (std::nothrow) ProducerImpl(properties);
	return producer;
}

OrderProducer* MQClientFactoryImpl::createOrderProducer(const Properties& properties)
{
	validateParam(properties, Namesrv_Addr);
	validateParam(properties, Producer_Id);

	OrderProducer* producer = new (std::nothrow) OrderProducerImpl(properties);
	return producer;
}

Consumer* MQClientFactoryImpl::createConsumer(const Properties& properties)
{
	validateParam(properties, Namesrv_Addr);
	validateParam(properties, Consumer_Id);

	Consumer* consumer = new (std::nothrow) ConsumerImpl(properties);
	return consumer;
}

OrderConsumer* MQClientFactoryImpl::createOrderConsumer(const Properties& properties)
{
	validateParam(properties, Namesrv_Addr);
	validateParam(properties, Consumer_Id);

	OrderConsumer* consumer = new (std::nothrow) OrderConsumerImpl(properties);
	return consumer;
}

OrderConsumer* MQClientFactoryImpl::createOrderConsumer(Properties& properties, unsigned int consumeWorkerSize)
{
	validateParam(properties, Namesrv_Addr);
	validateParam(properties, Consumer_Id);
	properties[Consumer_Worker_Size] = StringConvert::IntToString(consumeWorkerSize);

	OrderConsumer* consumer = new (std::nothrow) OrderConsumerImpl(properties);
	
	return consumer;
}

void MQClientFactoryImpl::validateParam(const Properties& properties, const std::string strPropertyKey)
{
	if (properties.find(strPropertyKey) == properties.end())
	{
		throw MQClientApiException(strPropertyKey + " is required");
	}
}
