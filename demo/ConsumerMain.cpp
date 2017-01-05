#include <iostream>
#include <unistd.h>
#include <string.h>
#include "zmq_client/GeneralDefine.h"
#include "zmq_client/MQClientFactoryImpl.h"
#include "zmq_client/Consumer.h"
#include "zmq_client/ProduceResult.h"
#include "zmq_client/MQMessage.h"
#include "ConcurrentMsgListenerImpl.h"

using namespace std;
using namespace ZMQ_API;
using namespace ZMQ_IMPL;

int main(int argc, char* argv[])
 {

	if (argc < 3)
	{
		cout << "Need params, Usage:Topic NameSrv(ip:port) [-m|-t]\n"
			<< "-m : consumer model, 1-broadcast, 0-cluster\n"
			<< "-t : message tags, eg: tag1\\|\\|tag2\n";
			 
		return 0;
	}

	MQClientFactoryImpl factory;

	Properties properties;
	properties[Consumer_Id] = "CID_001";
	properties[Consumer_Worker_Size] = "5";
	properties[Namesrv_Addr] = argv[2];

	string strTag = "*";
	for (int i = 3; i < argc; i+=2)
	{
		if (strcmp(argv[i], "-m") ==0 )
		{
			properties[Consumer_Message_Model] = (argv[i +1][0] == '1' ? Consumer_Broadcast_Model_Value : Consumer_Cluster_Model_Value);
		}
		else if (strcmp(argv[i], "-t") == 0)
		{
			strTag = argv[i + 1];
		}
	}
	

	Consumer* consumer = factory.createConsumer(properties);

	MessageListenerConcurrently* pLis = new ConcurrentMsgListenerImpl;//Ïû·Ñ¼àÌýÆ÷

	consumer->subscribe(argv[1], pLis, strTag);
	consumer->start();

	while (true)
	{
		sleep(3);

	}

	delete pLis;

	return 0;
}
