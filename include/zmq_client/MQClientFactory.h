#ifndef _MQ_CLIENT_FACTORY_H_
#define _MQ_CLIENT_FACTORY_H_



// 
// class Producer;
// class OrderProducer;
// class Consumer;
// class OrderConsumer;


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
					* ��������ࡿMQ �ͻ��˹����ӿڶ��壺���ڴ��������� producer �� consumer.
					*/
					class MQClientFactory
					{
					public:
						/**
						* Creates the producer to send normal messages.
						*
						* @param properties
						*            the properties for the producer
						* @return created producer
						* @throws MQClientApiException
						*/
						virtual Producer* createProducer(const ZMQ_API::Properties& properties) = 0;


						/**
						* Creates the producer to send order messages.
						*
						* @param properties
						*            the properties for the producer
						* @return created order producer
						* @throws MQClientApiException
						*/
						virtual OrderProducer* createOrderProducer(const ZMQ_API::Properties& properties) = 0;

						/**
						* Creates the consumers to consume messages.
						*
						* @param properties
						*            the properties for the consumer
						* @return created consumer
						* @throws MQClientApiException
						*/
						virtual Consumer* createConsumer(const ZMQ_API::Properties& properties) = 0;

						/**
						* Creates the consumers to consume order messages.
						*
						* @param properties
						*            the properties for the consumer
						* @return created consumer
						* @throws MQClientApiException
						*/
						virtual OrderConsumer* createOrderConsumer(const ZMQ_API::Properties& properties) = 0;

						/** ����ͬ����� createOrderConsumer�����Ӷ���Ĳ�����ʾָ�� Consumer �������߳���
						
							@param consumeWorkerSize	OrderConsumer ˳�����ѣ�ָ����һ�������ڵ���Ϣ��һ���߳�˳�򣬵��Ƕ�������Ƕ���̲߳��������
								ͨ�����ù����߳������������Ʋ��������߳���
								�ò���Ҳ������ properties �����ã��ò��������� properties �и����Ե�ָ��PropertyKey::Consumer_Worker_Size����
						*/
						virtual OrderConsumer* createOrderConsumer(ZMQ_API::Properties& properties, unsigned int consumeWorkerSize) = 0;
					};

				}
			}
		}
	}
}

#endif
