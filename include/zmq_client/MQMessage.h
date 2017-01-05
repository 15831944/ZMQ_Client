#ifndef _MQ_MESSAGE_H_
#define _MQ_MESSAGE_H_

#include <string>
#include <map>
#include <vector>


namespace com
{
	namespace ztesoft
	{
		namespace mq
		{
			namespace client
			{
				namespace api
				{

					/**
					* This class is represent as the mq message to send.
					*
					* @author chen.si
					*
					*/

					class MQMessage {
					private:
						/**
						* The topic for the message.
						*/
						std::string topic;

						/**
						* The message body.
						*/
						std::string body;

						/**
						* The properties in user level.
						*/
						std::map<std::string, std::string> userProperties;

						/**
						* The properties in system level.
						*/
						std::map<std::string, std::string> systemProperties;

					public:
						/**
						* Default constructor.
						*/
						MQMessage();
					
						/**
						* Creates the instance.
						*
						* @param topic
						*            the topic of the message
						* @param body
						*            the body data of the message
						*/
						MQMessage(const std::string& topic, const std::string& body);
						

						/**
						* Creates the instance.
						*
						* @param topic
						*            the topic of the message
						* @param tags
						*            the tags of the message
						* @param body
						*            the body data of the message
						*/
						MQMessage(const std::string& topic, const std::string& tags, const std::string& body);
					
						/**
						* Creates the instance.
						*
						* @param topic
						*            the topic of the message
						* @param tags
						*            the tags of the message
						* @param keys
						*            the keys of the message
						* @param body
						*            the body data of the message
						*/
						MQMessage(const std::string& topic, const std::string& tags, const std::string& keys, const std::string& body);
					

						/**
						* Creates the instance.
						*
						* @param topic
						*            the topic of the message
						* @param tags
						*            the tags of the message
						* @param keys
						*            the keys of the message
						* @param body
						*            the body data of the message
						*
						* @param isReliable
						*            whether the message is reliable, if true, wait for the message to finish storing
						*/
						MQMessage(const std::string& topic, const std::string& tags, const std::string& keys, const std::string& body, bool isReliable);
				
						void init(const std::string& topic, const std::string& tags, const std::string& keys, const std::string& body, bool isReliable);

						std::string getTopic();
				
						void setTopic(const std::string& topic);
					
						std::string getBody();
					
						void setBody(const std::string& body);
						

						/**
						* Gets the tags.
						*
						* @return
						*/
						std::string getTags();
					
						/**
						* Sets the tags.
						* @param tags
						*/
						void setTags(const std::string& tags);
					
						/**
						* Gets the keys.
						* @return
						*/
						std::string getKeys();
					
						/**
						* Sets the keys.
						* @param keys
						*/
						void setKeys(const std::string& keys);
					

						/**
						* Sets the keys.
						* @param keys
						*/
						void setKeys(std::vector<std::string> keys);
						

						/**
						* Gets the delay time level.
						* @return
						*/
						int getDelayTimeLevel();
					
						/**
						* Sets the delay time level.
						* @param level
						*/
						void setDelayTimeLevel(int level);
					

						/**
						* Gets the reliable level.
						* @return whether the message is reliable, if true, wait for the message to finish storing
						*/
						bool getReliableLevel();
					
						/**
						* Sets the reliable level.
						* @param isReliable
						*/
						void setReliableLevel(bool isReliable);
					

						/**
						* Gets the reconsume times.
						* @return
						*/
						int getReconsumeTimes();
						

						/**
						* Sets the reconsume times.
						* @param value
						*/
						void setReconsumeTimes(int value);
						

						/**
						* Gets the user properties.
						*
						* <p>
						* Note that the map is not thread-safe.
						*
						* @return
						*/
						std::map<std::string, std::string> getUserProperty();
					
						/**
						* Gets the user property by the name.
						* @param name
						* @return
						*/
						std::string getUserProperty(const std::string& name);
					

						/**
						* Puts the user property with name and value.
						* @param name
						* @param value
						*/
						void putUserProperty(const std::string& name, const std::string& value);
					

						/**
						* Gets the system property by name.
						* @param name
						* @return
						*/
						std::string getSystemProperty(const std::string& name);
					

						/**
						* Gets the system properties.
						* @return
						*/
						std::map<std::string, std::string> getSystemProperty();
						

						/**
						* Puts the system property.
						* @param name
						* @param value
						*/
						void putSystemProperty(const std::string& name, const std::string& value);
						
					
					};

				}
			}
		}
	}
}


#endif 

