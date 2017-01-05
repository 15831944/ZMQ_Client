#include "ForEachUtil.h"
#include "zmq_client/SystemPropertyKey.h"

using namespace ZMQ_API;
using namespace ZMQ_IMPL;

void ForEachUtil::map(Message& msg, const Properties& mapProperty, handler phandler)
{
	if (mapProperty.size() != 0)
	{
		Properties::const_iterator it = mapProperty.begin();
		for (; it != mapProperty.end(); ++it)
		{
			phandler(msg, it->first, it->second);
		}
	}
}

// void ForEachUtil::map(MQMessage& msg, const Properties& mapProperty, mqHandler phandler)
// {
// 
// }

void ForEachUtil::UserHandler(Message& msg, const std::string& strKey, const std::string& strValue)
{
	if (!SystemPropertyKey::instance().containApiKey(strKey))
	{
		msg.putProperty(strKey, strValue);
	}
}

void ForEachUtil::SystemHandler(Message& msg, const std::string& strKey, const std::string& strValue)
{
	if (!SystemPropertyKey::instance().containIntraImplKey(strKey) && !SystemPropertyKey::instance().containIntraMapImplKey(strKey))
	{
		msg.putProperty(strKey, strValue);
	}
}
