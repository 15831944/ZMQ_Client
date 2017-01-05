#ifndef _PRODUCER_IMPL_H_
#define _PRODUCER_IMPL_H_

#include "DefaultMQProducer.h"
#include "zmq_client/ProduceResult.h"
#include "zmq_client/MQMessage.h"
#include "zmq_client/Properties.h"
#include "zmq_client/Producer.h"

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
					class ProducerImpl : public ZMQ_API::Producer
					{
					public:
						ProducerImpl(ZMQ_API::Properties& properties);

						void start();
						void shutdown();
						bool isStarted();
						bool isShutdown();
						ZMQ_API::ProduceResult send(const ZMQ_API::MQMessage& message);
						void sendOneway(const ZMQ_API::MQMessage& message);

					private:
						DefaultMQProducer m_producer;
						bool m_bStartedFlag;
					};

				}
			}
		}
	}
}


#endif


