#ifndef _ORDER_PRODUCER_H_
#define _ORDER_PRODUCER_H_

#include "GeneralDefine.h"
#include "MQMessage.h"
#include "Manageable.h"


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
					/** 顺序消息发送者

					Producer 将根据应用层指定的字段，计算哈希值，然后会队列数取模，以确定消息发送到哪个队列
					这样，该字段相同的消息将按序发送到相同的队列上
					*/
					class OrderProducer : public ZMQ_API::Manageable
					{
					public:
						/**
						@param message	要发送的消息对象：必须提供 topic 和 body，其它信息可选
						@param shardingKey	求哈希值确定消息发送到哪个队列的字段
						*/
						virtual ZMQ_API::ProduceResult send(const ZMQ_API::MQMessage& message, const std::string& shardingKey) = 0;
					};

				}
			}
		}
	}
}


#endif

