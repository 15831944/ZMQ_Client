#include <iostream>
#include <string.h>
#include "zmq_client/GeneralDefine.h"
#include "zmq_client/MQClientApiException.h"
#include "zmq_client/MQClientFactoryImpl.h"
#include "zmq_client/Producer.h"
#include "zmq_client/ProduceResult.h"
#include "zmq_client/MQMessage.h"

using namespace std;
using namespace ZMQ_API;
using namespace ZMQ_IMPL;


int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Need params, Usage:Topic NameSrv(ip:port) [-t|-k|-s]\n"
			<< "-t : message tags\n"
			<< "-k : message keys, eg: key1\\|key2\n"
			<< "-s : message body size.\n";
		return 0;
	}

	Producer* producer = NULL;
	try
	{
		MQClientFactoryImpl factory;
		Properties properties;
		properties[Producer_Id] = "PID_001";
		properties[Namesrv_Addr] = argv[2];

		string strTag, strKey;
		for (int i = 3; i < argc; i+=2)
		{
			if (strcmp(argv[i], "-t") == 0)
			{
				strTag = argv[i + 1];
			}
			else if (strcmp(argv[i], "-k") == 0)
			{
				strKey = argv[i + 1];
			}
			else if (strcmp(argv[i], "-s") == 0)
			{
				properties[Producer_Max_Message_Size] = argv[i + 1];
			}
		}
	
		if (!strKey.empty())
		{
			for (int i = 0; i < strKey.size(); ++i)
			{
				if (strKey.at(i) == '|')
				{
					strKey[i] = ' ';
				}
			}
		}

		producer = factory.createProducer(properties);

		producer->start();

		MQMessage msg(argv[1], strTag, strKey, "hello zmq!");

		ProduceResult result = producer->send(msg);
		if (result.getStatus() == PRS_SEND_OK)
		{
			cout << "send message success : ";
		}

		cout << result.toString() << endl;
	}
	catch (MQClientApiException& e)
	{
		cout << e.what() << endl;
	}

	if (NULL != producer)
	{
		producer->shutdown();
		
	}

	return 0;
}
