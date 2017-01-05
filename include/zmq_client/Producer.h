#ifndef _PRODUCER_H_
#define _PRODUCER_H_

#include "Manageable.h"
#include "GeneralDefine.h"
#include "ProduceResult.h"
#include "MQMessage.h"

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
					class Producer : public ZMQ_API::Manageable
					{
					  public:
						/**
						* Sends the normal message.
						*
						* @param message
						*            the message to send
						* @return the send result
						* @throws MQClientApiException
						*/
						  virtual ZMQ_API::ProduceResult send(const ZMQ_API::MQMessage& message) = 0;

						/**
						* Sends the normal message in one way mode.
						*
						* @param message
						*            the message to send
						* @throws MQClientApiException
						*/
						  virtual void sendOneway(const ZMQ_API::MQMessage& message) = 0;
					};
				}
			}
		}
	}
}


#endif
