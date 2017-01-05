#ifndef _PROPERTIES_H_
#define _PROPERTIES_H_

#include <string>
#include <map>

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
					typedef std::map<std::string, std::string> Properties;

/*****************************************Property Key*******************************************/

					/**
					* 定义 Producer 和 Consumer 使用到的属性定义（包括属性名和一些属性值）
					*/
					static const std::string Access_Key = "AccessKey";
					static const std::string Secret_Key = "SecretKey";
					/**
					* The key of producer id.
					*
					* <p>Producer_Id is required and can be treated as producer group.
					*
					*/
					static const std::string Producer_Id = "ProducerId";

					/**
					* The key of timeout for producer to send message in milliseconds.
					*
					* <p>Producer_Send_Timeout is optional and is 5000 by default.
					*/
					static const std::string Producer_Send_Timeout = "ProducerSendTimeout";

					/**
					* The key of maximum size of message to send.
					*
					* <p>Producer_Max_Message_Size is optional and is 2MB by default.
					*/
					static const std::string Producer_Max_Message_Size = "ProducerMaxMessageSize";

					/**
					* The key of Consumer_Id id.
					*
					* <p>Consumer_Id is required and can be treated as consumer group.
					*
					*/
					static const std::string Consumer_Id = "ConsumerId";

					/**
					* The key of Consumer_Message_Model id.
					*
					* <p>Consumer_Message_Model is optional and is CLUSTERING by default.
					*
					*/
					static const std::string Consumer_Message_Model = "ConsumerMessageModel";

					/**
					* The key of timeout for consumer to consume a message.
					*/
					static const std::string Consumer_Timeout = "ConsumerTimeout";

					/**
					* The key of the time suspended if an order message is failed.
					*/
					static const std::string Consumer_SuspendTimeMillis = "ConsumerSuspendTimeMillis";

					/**
					* The optional value of <code>Consumer_Message_Model</code>
					*/
					static const std::string Consumer_Cluster_Model_Value = "CLUSTERING";

					/**
					* The optional value of <code>Consumer_Message_Model</code>
					*/
					static const std::string Consumer_Broadcast_Model_Value = "BROADCASTING";

					/**
					* The key of size for consumer thread pool.
					*
					* <p>Consumer_Worker_Size is optional and is min20 and max64 by default.
					*/
					static const std::string Consumer_Worker_Size = "ConsumerWorkerSize";

					/**
					* The key of address for name server.
					*
					* <p>Namesrv_Addr is required.
					*/
					static const std::string Namesrv_Addr = "NamesrvAddr";

/*****************************************System Property Key*******************************************/
					/**
					* The name of keyword for messages.
					*/
					static const std::string PROPERTY_KEYS = "__KEYS";

					/**
					* The name of tags for message.
					*/
					static const std::string PROPERTY_TAGS = "__TAGS";

					/**
					* The name of reliable for message.
					*/
					static const std::string PROPERTY_RELIABLE_LEVEL = "__RELIABLE";

					/**
					* The name of delay level for message.
					*/
					static const std::string PROPERTY_DELAY_TIME_LEVEL = "__DELAY";

					/**
					* The name of reconsume times for message.
					*/
					static const std::string PROPERTY_RECONSUMETIMES = "__RECONSUMETIMES";

					/**
					* The separator for the multiple keys.
					*/
					static const std::string KEY_SEPARATOR = " ";
					static const std::string PROPERTY_INTRA_TRACE_KEY = "__MSG_TRACE_ID";
					static const std::string PROPERTY_INTRA_TRACERPC_KEY = "__MSG_TRACERPC_ID";
					static const std::string PROPERTY_INTRA_KEYS = "KEYS";
					static const std::string PROPERTY_INTRA_TAGS = "TAGS";
					static const std::string PROPERTY_INTRA_RELIABLE_LEVEL = "WAIT";
					static const std::string PROPERTY_INTRA_DELAY_TIME_LEVEL = "DELAY";
					static const std::string PROPERTY_RETRY_TOPIC = "RETRY_TOPIC";
					static const std::string PROPERTY_REAL_TOPIC = "REAL_TOPIC";
					static const std::string PROPERTY_REAL_QUEUE_ID = "REAL_QID";
					static const std::string PROPERTY_TRANSACTION_PREPARED = "TRAN_MSG";
					static const std::string PROPERTY_PRODUCER_GROUP = "PGROUP";
					static const std::string PROPERTY_MIN_OFFSET = "MIN_OFFSET";
					static const std::string PROPERTY_MAX_OFFSET = "MAX_OFFSET";
					static const std::string PROPERTY_BUYER_ID = "BUYER_ID";
					static const std::string PROPERTY_ORIGIN_MESSAGE_ID = "ORIGIN_MESSAGE_ID";
					static const std::string PROPERTY_TRANSFER_FLAG = "TRANSFER_FLAG";
					static const std::string PROPERTY_CORRECTION_FLAG = "CORRECTION_FLAG";
					static const std::string PROPERTY_MQ2_FLAG = "MQ2_FLAG";

				}
			}
		}
	}
}

#endif