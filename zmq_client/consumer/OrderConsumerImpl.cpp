
#include "OrderConsumerImpl.h"
#include "MessageListener.h"
#include "ConsumeType.h"
#include "zmq_client/StringConvert.h"


using namespace ZMQ_API;
using namespace ZMQ_IMPL;

OrderConsumerImpl::OrderConsumerImpl(Properties properties) :m_bStartedFlag(false)
{
	this->m_consumer.setConsumerGroup(properties[Consumer_Id]);

// 	String suspendTimeMillis = properties.getProperty(PropertyKey.Consumer_SuspendTimeMillis);
// 	if (null != suspendTimeMillis) {
// 		this.consumer.setSuspendCurrentQueueTimeMillis(Long.parseLong(suspendTimeMillis));
// 	}
	std::string consumerWorkerSize = properties[Consumer_Worker_Size];
	if (!consumerWorkerSize.empty())
	{
		this->m_consumer.setConsumeThreadMin(StringConvert::StringToInt(consumerWorkerSize));
		this->m_consumer.setConsumeThreadMax(StringConvert::StringToInt(consumerWorkerSize));
	}

	this->m_consumer.setNamesrvAddr(properties[Namesrv_Addr]);

}

void OrderConsumerImpl::start() 
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

void OrderConsumerImpl::shutdown()
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

bool OrderConsumerImpl::isStarted()
{
	return m_bStartedFlag;
}

bool OrderConsumerImpl::isShutdown()
{
	return !m_bStartedFlag;
}


void OrderConsumerImpl::subscribe(const std::string& topic, MessageListenerOrderly* handler, const std::string& subexpression)
{
	try
	{
		registerMessageListener(handler);
		m_consumer.subscribe(topic, subexpression);
	}
	CATCH_ZMQ_IMPL
}

void OrderConsumerImpl::unsubscribe(const std::string& topic)
{
	if (!topic.empty())
	{
		m_consumer.unsubscribe(topic);
	}
}

void OrderConsumerImpl::registerMessageListener(MessageListenerOrderly* pListener)
{
	if (pListener != NULL)
	{
		m_consumer.registerMessageListener(pListener);
	}
}

void OrderConsumerImpl::subscribe(const std::string& topic)
{
	m_consumer.subscribe(topic, "*");
}
