#ifndef _MSG_LISTENER_ORDER_IMPL_H_
#define _MSG_LISTENER_ORDER_IMPL_H_

#include "MessageListener.h"

class OrderMsgListenerImpl :public MessageListenerOrderly
{
public:
	ConsumeOrderlyStatus consumeMessage(std::list<MessageExt*>& msgs, ConsumeOrderlyContext& context);

};

#endif