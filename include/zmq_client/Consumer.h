#ifndef _CONSUMER_H
#define _CONSUMER_H

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
					//并发消费：同一个队列的一个批次的消息，会启动多个线程并发处理【不适合计费场景】
					class Consumer :public ZMQ_API::Manageable
					{
					public:
						virtual void registerMessageListener(MessageListenerConcurrently* pListener) = 0;
						virtual void subscribe(const std::string& topic) = 0;
						virtual void subscribe(const std::string& topic, MessageListenerConcurrently* handler, const std::string& subexpression = "*") = 0;
						virtual void unsubscribe(const std::string& topic) = 0;
					};
				}
			}
		}
	}
}

#endif

