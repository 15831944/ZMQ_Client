#ifndef _PRODUCE_RESULT_STATUS_H
#define _PRODUCE_RESULT_STATUS_H

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
					* This enumeration is to define the sent status about producing message.
					*/
					enum ProduceResultStatus 
					{
						/**
						* The message is sent successfully.
						*/
						PRS_SEND_OK,
						/**
						* The message is sent but timeout to flush to the disk.
						*/
						PRS_FLUSH_DISK_TIMEOUT,
						/**
						* The message is sent but timeout to replicate to the slave.
						*/
						PRS_FLUSH_SLAVE_TIMEOUT,
						/**
						* The message is sent but cannot replicate to the slave.
						*/
						PRS_SLAVE_NOT_AVAILABLE
					};

				}
			}
		}
	}
}



#endif // !_PRODUCE_RESULT_STATUS_H



