#ifndef _PRODUCE_RESULT_H_
#define _PRODUCE_RESULT_H_

#include <stdio.h>
#include <string>
#include "ProduceResultStatus.h"

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
					/**
					* This class is represent as the result to produce the message.
					*
					*/
					class ProduceResult
					{
					protected:
						/**
						* The result status.
						*/
						ProduceResultStatus status;

						/**
						* The message id.
						*/
						std::string messageId;
					public:
						
						/**
						* Gets the message id.
						* @return
						*/
						std::string getMessageId() 
						{
							return messageId;
						}

						/**
						* Sets the message id.
						* @param messageId
						*/
						void setMessageId(const std::string& messageId)
						{
							this->messageId = messageId;
						}

						/**
						* Gets the result status of producing message.
						* @return
						*/
						ProduceResultStatus getStatus() 
						{
							return status;
						}

						/**
						* Sets the result status of producing message.
						* @param status
						*/
						void setStatus(ProduceResultStatus status) 
						{
							this->status = status;
						}


						std::string toString()
						{
							char msg[128] = { 0 };
							sprintf(msg, "ProduceResult [status=%d, msgId=%s]", this->status, this->messageId.c_str());
							//return "ProduceResult [status=" + this.status + ", msgId=" + this.messageId + "]";
							return msg;
						}
					};

				}
			}
		}
	}
}



#endif





