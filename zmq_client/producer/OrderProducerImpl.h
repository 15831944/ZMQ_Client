#ifndef _ORDER_PRODUCER_IMPL_H_
#define _ORDER_PRODUCER_IMPL_H_

#include <string>
#include "DefaultMQProducer.h"
#include "zmq_client/ProduceResult.h"
#include "zmq_client/MQMessage.h"
#include "zmq_client/Properties.h"
#include "zmq_client/OrderProducer.h"

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
					class OrderProducerImpl : public ZMQ_API::OrderProducer
					{
					public:
						OrderProducerImpl(ZMQ_API::Properties properties);
						void start();
						void shutdown();
						bool isStarted();
						bool isShutdown();
						ZMQ_API::ProduceResult send(const ZMQ_API::MQMessage& message, const std::string& shardingKey);

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

