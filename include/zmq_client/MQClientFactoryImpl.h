#ifndef _MQ_CLIENT_FACTORY_IMPL_H_
#define _MQ_CLIENT_FACTORY_IMPL_H_

#include "Properties.h"
#include "GeneralDefine.h"
#include "zmq_client/Producer.h"
#include "zmq_client/OrderProducer.h"
#include "zmq_client/Consumer.h"
#include "zmq_client/OrderConsumer.h"
#include "zmq_client/MQClientFactory.h"

namespace com
{
	namespace ztesoft
	{
		namespace mq
		{
			namespace client
			{
				namespace impl
				{
					class MQClientFactoryImpl : public ZMQ_API::MQClientFactory
					{
					public:

						ZMQ_API::Producer* createProducer(const ZMQ_API::Properties& properties);
						ZMQ_API::OrderProducer* createOrderProducer(const ZMQ_API::Properties& properties);

						ZMQ_API::Consumer* createConsumer(const ZMQ_API::Properties& properties);
						ZMQ_API::OrderConsumer* createOrderConsumer(const ZMQ_API::Properties& properties);
						ZMQ_API::OrderConsumer* createOrderConsumer(ZMQ_API::Properties& properties, unsigned int consumeWorkerSize);
					private:
						void validateParam(const ZMQ_API::Properties& properties, const std::string strPropertyKey);
					
					};

				}
			}
		}
	}
}

#endif




