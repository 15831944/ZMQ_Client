#include "ConsumerImpl.h"
#include "MessageListener.h"
#include "ConsumeType.h"
#include "zmq_client/GeneralDefine.h"
#include "zmq_client/StringConvert.h"


using namespace ZMQ_API;
using namespace ZMQ_IMPL;


ConsumerImpl::ConsumerImpl( Properties properties) :m_bStartedFlag(false)
{
	this->m_consumer.setConsumerGroup(properties[Consumer_Id]);

	if (properties[Consumer_Message_Model] == Consumer_Broadcast_Model_Value)
	{
		this->m_consumer.setMessageModel(BROADCASTING);
	}
	else
	{
		this->m_consumer.setMessageModel(CLUSTERING);
	}

// 	std::string consumeTimeoutValue = properties[Consumer_Timeout];
// 	if (!consumeTimeoutValue.empty())
// 	{
// 		this->m_consumer.setConsumeTimeout(StringConvert::StringToInt(consumeTimeoutValue));
// 	}

	std::string consumerWorkerSize = properties[Consumer_Worker_Size];
	if (!consumerWorkerSize.empty())
	{
		int nWorkerSize = StringConvert::StringToInt(consumerWorkerSize);
		m_consumer.setConsumeThreadMin(nWorkerSize);
		m_consumer.setConsumeThreadMax(nWorkerSize);
	}

	this->m_consumer.setNamesrvAddr(properties[Namesrv_Addr]);
}

void ConsumerImpl::start()
{
	try
	{
		if (!m_bStartedFlag)
		{
			m_consumer.start();
			m_bStartedFlag = true;
		}
	}
	CATCH_ZMQ_IMPL

}

void ConsumerImpl::shutdown()
{
	try
	{
		if (m_bStartedFlag)
		{
			m_consumer.shutdown();
			m_bStartedFlag = false;
		}
	}
	CATCH_ZMQ_IMPL
}

bool ConsumerImpl::isStarted()
{
	return m_bStartedFlag;
}

bool ConsumerImpl::isShutdown()
{
	return !m_bStartedFlag;
}

void ConsumerImpl::subscribe(const std::string& topic, MessageListenerConcurrently* handler, const std::string& subexpression/* = "*"*/)
{
	try 
	{
		registerMessageListener(handler);
		m_consumer.subscribe(topic, subexpression);
	}
	CATCH_ZMQ_IMPL
}


void ConsumerImpl::unsubscribe(const std::string& topic)
{
	if (!topic.empty())
	{
		m_consumer.unsubscribe(topic);
	}
}

void ConsumerImpl::registerMessageListener(MessageListenerConcurrently* pListener)
{
	if (pListener != NULL)
	{
		m_consumer.registerMessageListener(pListener);
	}
}

void ConsumerImpl::subscribe(const std::string& topic)
{
	m_consumer.subscribe(topic, "*");
}
