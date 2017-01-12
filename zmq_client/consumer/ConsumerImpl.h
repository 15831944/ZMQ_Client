#ifndef _CONSUMER_IMPL_H_
#define _CONSUMER_IMPL_H_

#include "zmq_client/Consumer.h"
#include "DefaultMQPushConsumer.h"
#include "zmq_client/ProduceResult.h"
#include "zmq_client/MQMessage.h"
#include "zmq_client/Properties.h"

class MessageListener;

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
					class ConsumerImpl : public ZMQ_API::Consumer
					{
					public:
						ConsumerImpl(ZMQ_API::Properties properties);
						void start();
						void shutdown();
						bool isStarted();
						bool isShutdown();
					    void registerMessageListener(MessageListenerConcurrently* pListener);
						void subscribe(const std::string& topic);
						void subscribe(const std::string& topic, MessageListenerConcurrently* handler, const std::string& subexpression = "*");
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