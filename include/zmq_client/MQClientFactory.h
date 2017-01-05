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
					* 【抽象基类】MQ 客户端工厂接口定义：用于创建复数的 producer 和 consumer.
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

						/** 功能同上面的 createOrderConsumer，增加额外的参数显示指定 Consumer 的消费线程数
						
							@param consumeWorkerSize	OrderConsumer 顺序消费，指的是一个队列内的消息由一个线程顺序，但是多个队列是多个线程并发处理的
								通过设置工作线程数，可以限制并发工作线程数
								该参数也可以在 properties 中设置，该参数将覆盖 properties 中该属性的指（PropertyKey::Consumer_Worker_Size）。
						*/
						virtual OrderConsumer* createOrderConsumer(ZMQ_API::Properties& properties, unsigned int consumeWorkerSize) = 0;
					};

				}
			}
		}
	}
}

#endif
