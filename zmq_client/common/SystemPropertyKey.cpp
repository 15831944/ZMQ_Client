#include "zmq_client/SystemPropertyKey.h"
#include "zmq_client/MQClientApiException.h"
#include "zmq_client/GeneralDefine.h"

using namespace ZMQ_API;

bool SystemPropertyKey::m_isInit = false;

SystemPropertyKey& SystemPropertyKey::instance()
{
	static SystemPropertyKey systemProperty;
	if (!m_isInit)
	{
		systemProperty.init();
	}

	return systemProperty;
}


void SystemPropertyKey::init()
{

	SystemKeySet.insert(PROPERTY_KEYS);
	SystemKeySet.insert(PROPERTY_TAGS);
	SystemKeySet.insert(PROPERTY_RELIABLE_LEVEL);
	SystemKeySet.insert(PROPERTY_DELAY_TIME_LEVEL);
	SystemKeySet.insert(PROPERTY_RECONSUMETIMES);

	IntraMapSystemKeySet.insert(PROPERTY_INTRA_KEYS);
	IntraMapSystemKeySet.insert(PROPERTY_INTRA_TAGS);
	IntraMapSystemKeySet.insert(PROPERTY_INTRA_RELIABLE_LEVEL);
	IntraMapSystemKeySet.insert(PROPERTY_INTRA_DELAY_TIME_LEVEL);

	IntraSystemKeySet.insert(PROPERTY_RETRY_TOPIC);
	IntraSystemKeySet.insert(PROPERTY_REAL_TOPIC);
	IntraSystemKeySet.insert(PROPERTY_REAL_QUEUE_ID);
	IntraSystemKeySet.insert(PROPERTY_TRANSACTION_PREPARED);
	IntraSystemKeySet.insert(PROPERTY_PRODUCER_GROUP);
	IntraSystemKeySet.insert(PROPERTY_MIN_OFFSET);
	IntraSystemKeySet.insert(PROPERTY_MAX_OFFSET);
	IntraSystemKeySet.insert(PROPERTY_BUYER_ID);
	IntraSystemKeySet.insert(PROPERTY_ORIGIN_MESSAGE_ID);
	IntraSystemKeySet.insert(PROPERTY_TRANSFER_FLAG);
	IntraSystemKeySet.insert(PROPERTY_CORRECTION_FLAG);
	IntraSystemKeySet.insert(PROPERTY_MQ2_FLAG);

	m_isInit = true;

}

bool SystemPropertyKey::containApiKey(const std::string& key)
{

	if (SystemKeySet.count(key) >= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool SystemPropertyKey::containIntraMapImplKey(const std::string& key)
{
	if (IntraMapSystemKeySet.count(key) >= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool SystemPropertyKey::containIntraImplKey(const std::string& key)
{
	if (IntraSystemKeySet.count(key) >= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

