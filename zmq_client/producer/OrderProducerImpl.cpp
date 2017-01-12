
#include "OrderProducerImpl.h"
#include "zmq_client/MQClientApiException.h"
#include "zmq_client/StringConvert.h"
#include "../common/MessageMapper.h"
#include "MessageQueueSelector.h"
#include "zmq_client/GeneralDefine.h"

using namespace ZMQ_API;
using namespace ZMQ_IMPL;


OrderProducerImpl::OrderProducerImpl(Properties properties) : m_bStartedFlag(false)
{
	std::string strProducerID = (properties[Producer_Id].empty() ? "__DEFAULT_ZMQ_PRODUCER_GROUP__" : properties[Producer_Id]);
	this->m_producer.setProducerGroup(strProducerID);
	
	std::string sendTimeout = (properties[Producer_Send_Timeout].empty() ? "5000" : properties[Producer_Send_Timeout]);
	this->m_producer.setSendMsgTimeout(StringConvert::StringToInt(sendTimeout));

	std::string strMaxMsgSize = properties[Producer_Max_Message_Size];
	if (!strMaxMsgSize.empty())
	{
		this->m_producer.setMaxMessageSize(StringConvert::StringToInt(strMaxMsgSize));
	}
	
	this->m_producer.setNamesrvAddr(properties[Namesrv_Addr]);

}

void OrderProducerImpl::start()
{
	try
	{
		if (!m_bStartedFlag)
		{
			m_producer.start();
			m_bStartedFlag = true;
		}
	}
	CATCH_ZMQ_IMPL

}

void OrderProducerImpl::shutdown()
{
	try
	{
		if (m_bStartedFlag)
		{
			m_producer.shutdown();
			m_bStartedFlag = false;
		}
	}
	CATCH_ZMQ_IMPL
}

bool OrderProducerImpl::isStarted()
{
	return m_bStartedFlag;
}

bool OrderProducerImpl::isShutdown()
{
	return !m_bStartedFlag;
}

ProduceResult OrderProducerImpl::send(const MQMessage& message, const std::string& shardingKey)
{
	try 
	{
		Message msg = MessageMapper::map(message);

		SelectMessageQueueByHash selector;
		
		SendResult sendResult = this->m_producer.send(msg, &selector, const_cast<char *>(shardingKey.c_str()));

		return MessageMapper::map(sendResult);
	}
	CATCH_ZMQ_IMPL
}
