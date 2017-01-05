#ifndef _ORDER_CONSUMER_IMPL_H_
#define _ORDER_CONSUMER_IMPL_H_

#include <string>
#include "zmq_client/OrderConsumer.h"
#include "DefaultMQPushConsumer.h"
#include "zmq_client/ProduceResult.h"
#include "zmq_client/MQMessage.h"
#include "zmq_client/Properties.h"


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
					class OrderConsumerImpl : public ZMQ_API::OrderConsumer
					{
					public:
						OrderConsumerImpl(ZMQ_API::Properties& properties);
						void start();
						void shutdown();
						bool isStarted();
						bool isShutdown();
						void registerMessageListener(MessageListenerOrderly* pListener);
						void subscribe(const std::string& topic);
						void subscribe(const std::string& topic, MessageListenerOrderly* handler, const std::string& subexpression = "*");
						void unsubscribe(const std::string& topic);
					private:
						bool m_bStartedFlag;
						DefaultMQPushConsumer m_consumer;
					};

				}
			}
		}
	}
}



#endif