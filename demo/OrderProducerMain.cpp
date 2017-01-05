#include <stdio.h>    
#include <sys/time.h> 
#include <iostream>
#include <string.h>
#include "zmq_client/GeneralDefine.h"
#include "zmq_client/MQClientApiException.h"
#include "zmq_client/MQClientFactoryImpl.h"
#include "zmq_client/OrderProducer.h"
#include "zmq_client/ProduceResult.h"
#include "zmq_client/MQMessage.h"
#include "zmq_client/StringConvert.h"

using namespace std;
using namespace ZMQ_API;
using namespace ZMQ_IMPL;
int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cout << "Need params, Usage:Topic NameSrv(ip:port) [-t|-k|-s|-i]\n"
			<< "-t : message tags\n"
			<< "-k : message keys, eg: key1\\|key2\n"
			<< "-s : message body size\n"
			<< "-i : hash value for select mq id.\n";
		return 0;
	}

	OrderProducer* producer = NULL;

	try
	{
		MQClientFactoryImpl factory;

		Properties properties;
		properties[Producer_Id] = "PID_001";
		properties[Namesrv_Addr] = argv[2];

		string strHash = "mykey";
		string strTag, strKey;
		for (int i = 3; i < argc; i += 2)
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
			else if (strcmp(argv[i], "-i") == 0)
			{
				strHash = argv[i + 1];
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

		producer = factory.createOrderProducer(properties);

		producer->start();

		string strBody;
		for (int i = 0; i < 10; i++)
		{
			strBody = string("order msg ") + StringConvert::IntToString(i+1);
			MQMessage msg(argv[1], strTag, strKey, strBody);

			ProduceResult result = producer->send(msg, strHash);
			if (result.getStatus() ==  PRS_SEND_OK)
			{
				cout << "send success: msg body =" << strBody << endl;
			}
			else
			{
				cout << "send fail: msg body =" << strBody << endl;
			}
			
		}
	}
	catch (MQClientApiException& e)
	{
		cout << e.what();
	}

	if (NULL != producer)
	{
		producer->shutdown();
		
	}

	return 0;
}