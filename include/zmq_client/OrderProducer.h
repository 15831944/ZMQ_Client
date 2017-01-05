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
					/** ˳����Ϣ������

					Producer ������Ӧ�ò�ָ�����ֶΣ������ϣֵ��Ȼ��������ȡģ����ȷ����Ϣ���͵��ĸ�����
					���������ֶ���ͬ����Ϣ�������͵���ͬ�Ķ�����
					*/
					class OrderProducer : public ZMQ_API::Manageable
					{
					public:
						/**
						@param message	Ҫ���͵���Ϣ���󣺱����ṩ topic �� body��������Ϣ��ѡ
						@param shardingKey	���ϣֵȷ����Ϣ���͵��ĸ����е��ֶ�
						*/
						virtual ZMQ_API::ProduceResult send(const ZMQ_API::MQMessage& message, const std::string& shardingKey) = 0;
					};

				}
			}
		}
	}
}


#endif

