#ifndef _MANAGEABLE_H_
#define _MANAGEABLE_H_


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
					* This class is to represent as the interface to describe the life cycle management about producer and consumer.
					*/
					class Manageable 
					{
					public:
						/**
						* Starts the resource.
						*
						* @throws MQClientApiException
						*/
						virtual void start() = 0;

						/**
						* Shutdowns the resource.
						*
						* @throws MQClientApiException
						*/
						virtual void shutdown() = 0;

						/**
						* Whether the resource is started.
						*
						* @return
						*/
						virtual bool isStarted() = 0;

						/**
						* Whether the resource is shutdown.
						*
						* @return
						*/
						virtual bool isShutdown() = 0;

					};

				}
			}
		}
	}
}


#endif
