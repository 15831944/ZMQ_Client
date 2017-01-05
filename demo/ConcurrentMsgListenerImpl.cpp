#include "ConcurrentMsgListenerImpl.h"
#include <iostream>
#include <stdio.h>

using namespace std;

ConcurrentMsgListenerImpl::ConcurrentMsgListenerImpl()
{

}


ConsumeConcurrentlyStatus ConcurrentMsgListenerImpl::consumeMessage(std::list<MessageExt*>& msgs, ConsumeConcurrentlyContext& context)
{
	cout << "consume concurrent msg begin..." << endl;
	list<MessageExt*>::iterator it = msgs.begin();
	for (; it != msgs.end(); ++it)
	{
		MessageExt* msg = *it;

		char szOut[128] = { 0 };
		printf("msg mqid = %d, topic = %s, body = %s, tags = %s\n", context.messageQueue.getQueueId(), msg->getTopic().c_str(), msg->getBody(), msg->getTags().c_str());
		
	}
	cout << "consume concurrent msg end..." << endl<<endl;


	return CONSUME_SUCCESS;
}
