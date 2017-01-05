#include "zmq_client/MQMessage.h"
#include <stdio.h>
#include "zmq_client/Properties.h"
#include "zmq_client/StringConvert.h"
#include "zmq_client/SystemPropertyKey.h"
#include "zmq_client/MQClientApiException.h"
#include "zmq_client/GeneralDefine.h"

using namespace ZMQ_API;

MQMessage::MQMessage()
{
	
}


MQMessage::MQMessage(const std::string& topic, const std::string& body)
{
	init(topic, "", "", body, true);
}


MQMessage::MQMessage(const std::string& topic, const std::string& tags, const std::string& body)
{
	init(topic, tags, "", body, true);
}


MQMessage::MQMessage(const std::string& topic, const std::string& tags, const std::string& keys, const std::string& body)
{
	init(topic, tags, keys, body, true);
}

MQMessage::MQMessage(const std::string& topic, const std::string& tags, const std::string& keys, const std::string& body, bool isReliable)
{
	init(topic, tags, keys, body, isReliable);
}


void MQMessage::init(const std::string& topic, const std::string& tags, const std::string& keys, const std::string& body, bool isReliable)
{
	this->topic = topic;
	this->body = body;

	if (tags.length() > 0)
		this->setTags(tags);

	if (keys.length() > 0)
		this->setKeys(keys);

	setReliableLevel(isReliable);
}


std::string MQMessage::getTopic()
{
	return topic;
}


void MQMessage::setTopic(const std::string& topic)
{
	this->topic = topic;
}

std::string MQMessage::getBody()
{
	return body;
}


void MQMessage::setBody(const std::string& body)
{
	this->body = body;
}


std::string MQMessage::getTags()
{
	return systemProperties[PROPERTY_TAGS];
}


void MQMessage::setTags(const std::string& tags)
{
	systemProperties[PROPERTY_TAGS] = tags;
	
}


std::string MQMessage::getKeys()
{
	
	return systemProperties[PROPERTY_KEYS];
}


void MQMessage::setKeys(const std::string& keys)
{
	
	systemProperties[PROPERTY_KEYS] = keys;
}


void MQMessage::setKeys(std::vector<std::string> keys)
{
	std::string strKeyTmp;
	for (int i = 0; i < keys.size(); ++i)
	{
		strKeyTmp += keys.at(i);
		strKeyTmp += KEY_SEPARATOR;
	}

	this->setKeys(strKeyTmp.substr(0, strKeyTmp.length() - 2));
}


int MQMessage::getDelayTimeLevel()
{
	return StringConvert::StringToInt(systemProperties[PROPERTY_DELAY_TIME_LEVEL]);

}


void MQMessage::setDelayTimeLevel(int level)
{
	std::string strValue = StringConvert::IntToString(level);
	systemProperties[PROPERTY_DELAY_TIME_LEVEL] = strValue;
}


bool MQMessage::getReliableLevel()
{
	return StringConvert::StringToBool(systemProperties[PROPERTY_RELIABLE_LEVEL]);

}


void MQMessage::setReliableLevel(bool isReliable)
{
	systemProperties[PROPERTY_RELIABLE_LEVEL] = StringConvert::BoolToString(isReliable);

}


int MQMessage::getReconsumeTimes()
{
	return StringConvert::StringToInt(systemProperties[PROPERTY_RECONSUMETIMES]);
}


void MQMessage::setReconsumeTimes(int value)
{
	systemProperties[PROPERTY_RECONSUMETIMES] = StringConvert::IntToString(value);
}


Properties MQMessage::getUserProperty()
{
	return this->userProperties;
}


std::string MQMessage::getUserProperty(const std::string& name)
{

	return userProperties[name];
}


void MQMessage::putUserProperty(const std::string& name, const std::string& value)
{
	if (SystemPropertyKey::instance().containApiKey(name))
	{
		char szMsg[128] = { 0 };
		sprintf(szMsg, "The Property<%s> is used by system, input another please", name.c_str());
		throw MQClientApiException(szMsg);
	}

	userProperties[name] = value;
}


std::string MQMessage::getSystemProperty(const std::string& name)
{
	return userProperties[name];
}


Properties MQMessage::getSystemProperty()
{
	return this->systemProperties;
}


void MQMessage::putSystemProperty(const std::string& name, const std::string& value)
{
	systemProperties[name] = value;
}
