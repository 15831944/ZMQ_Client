#ifndef _MESSAGE_MAPPER_H_
#define _MESSAGE_MAPPER_H_

#include "zmq_client/GeneralDefine.h"
#include "Message.h"
#include "zmq_client/ProduceResult.h"
#include "zmq_client/MQMessage.h"
#include "SendResult.h"

namespace com
{
	namespace ztesoft
	{
		namespace mq
		{
			namespace client
			{
				namespace impl
				{
					class MessageMapper
					{
					public:
						static Message map(ZMQ_API::MQMessage message);
						//static ZMQ_API::MQMessage map(Message message);
						static  ZMQ_API::ProduceResult map(SendResult sendResult);
						static void mapProduceResult(SendResult& sendResult, ZMQ_API::ProduceResult& result);
					};
				}
			}
		}
	}
}

#endif

