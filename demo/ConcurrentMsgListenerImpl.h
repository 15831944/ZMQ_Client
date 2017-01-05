#ifndef _MSG_LISTENER_CONCURRENT_IMPL_H_
#define _MSG_LISTENER_CONCURRENT_IMPL_H_

#include "MessageListener.h"

class ConcurrentMsgListenerImpl :public MessageListenerConcurrently
{
public:
	ConcurrentMsgListenerImpl();
	
	ConsumeConcurrentlyStatus consumeMessage(std::list<MessageExt*>& msgs, ConsumeConcurrentlyContext& context);
};


#endif

