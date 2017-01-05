#ifndef _ORDER_CONSUMER_H_
#define _ORDER_CONSUMER_H_

#include <string>
#include "GeneralDefine.h"
#include "Manageable.h"
#include "MessageListener.h"

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

					//顺序消费者：同一个队列消息将由一个线程进行处理，多个队列的消息将由多个线程并发处理
					class OrderConsumer : public ZMQ_API::Manageable
					{
					public:
						virtual void registerMessageListener(MessageListenerOrderly* pListener) = 0;
						virtual void subscribe(const std::string& topic) = 0;
						virtual void subscribe(const std::string& topic, MessageListenerOrderly* handler, const std::string& subexpression = "*") = 0;
						virtual void unsubscribe(const std::string& topic) = 0;
					};

				}
			}
		}
	}
}


#endif


