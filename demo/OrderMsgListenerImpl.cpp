#include "OrderMsgListenerImpl.h"
#include <iostream>
#include <stdio.h>

using namespace std;

ConsumeOrderlyStatus OrderMsgListenerImpl::consumeMessage(std::list<MessageExt*>& msgs, ConsumeOrderlyContext& context)
{
	cout << "consume order msg begin..." << endl;
	list<MessageExt*>::iterator it = msgs.begin();
	for (; it != msgs.end(); ++it)
	{
		MessageExt* msg = *it;

		char szOut[128] = { 0 };
		sprintf(szOut, "msg mqid = %d, topic = %s, body = %s, tags = %s\n", context.messageQueue.getQueueId(), msg->getTopic().c_str(), msg->getBody(), msg->getTags().c_str());
		cout << szOut;

	}

	cout << "consume order msg end..." << endl <<endl;

	return SUCCESS;
}
