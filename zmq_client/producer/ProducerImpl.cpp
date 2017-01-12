#include "ProducerImpl.h"
#include <string>
#include "zmq_client/MQClientApiException.h"
#include "zmq_client/StringConvert.h"
#include "../common/MessageMapper.h"
#include "zmq_client/GeneralDefine.h"

using namespace ZMQ_API;
using namespace ZMQ_IMPL;

ProducerImpl::ProducerImpl(Properties properties) : m_bStartedFlag(false)
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


void ProducerImpl::start()
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

void ProducerImpl::shutdown()
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

bool ProducerImpl::isStarted()
{
	return m_bStartedFlag;
}

bool ProducerImpl::isShutdown()
{
	return !m_bStartedFlag;
}

ProduceResult ProducerImpl::send(const MQMessage& message)
{
	try 
	{
		Message msg = MessageMapper::map(message);
		msg.putProperty("P_ID", m_producer.getProducerGroup());
		msg.putProperty("P_IP", m_producer.getClientIP());

		SendResult sendResult = m_producer.send(msg);

		return MessageMapper::map(sendResult);
	}
	CATCH_ZMQ_IMPL
}

void ProducerImpl::sendOneway(const MQMessage& message)
{
	try
	{
		Message msg = MessageMapper::map(message);

		m_producer.sendOneway(msg);
	}
	CATCH_ZMQ_IMPL
}
