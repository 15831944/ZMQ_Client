#include <iostream>
#include <unistd.h>
#include "zmq_client/GeneralDefine.h"
#include "zmq_client/MQClientApiException.h"
#include "zmq_client/MQClientFactoryImpl.h"
#include "zmq_client/OrderConsumer.h"
#include "zmq_client/ProduceResult.h"
#include "zmq_client/MQMessage.h"
#include "OrderMsgListenerImpl.h"

using namespace std;
using namespace ZMQ_API;
using namespace ZMQ_IMPL;


int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Need params, Usage:Topic NameSrv(ip:port) [-t]\n"
			<< "-t : message tags, eg: tag1\\|\\|tag2\n";

		return 0;
	}

	MQClientFactoryImpl factory;

	Properties properties;
	properties[Consumer_Id] = "CID_Order_001";
	properties[Consumer_Worker_Size] = "10";
	properties[Namesrv_Addr] = argv[2];

	MessageListenerOrderly* pLis = new OrderMsgListenerImpl;

	OrderConsumer* consumer = factory.createOrderConsumer(properties);

	string strTags = "*";
	if (argv[3]!=NULL)
	{
		strTags = argv[4];
	}
	consumer->subscribe(argv[1], pLis, strTags);
	consumer->start();

	while (true)
	{
		sleep(3);

	}
	
	return 0;
}