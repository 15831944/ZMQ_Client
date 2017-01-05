#ifndef _FOR_EACH_UTIL_H_
#define _FOR_EACH_UTIL_H_

#include "zmq_client/GeneralDefine.h"
#include "zmq_client/Properties.h"
#include "Message.h"
#include "zmq_client/MQMessage.h"

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

					/**
					* This class is to represent as the utility to simplify the iterator operations about map.
					*
					* @author chen.si
					*
					*/
					typedef void(*handler)(Message& msg, const std::string& strKey, const std::string& strValue);
					typedef void(*mqHandler)(ZMQ_API::MQMessage& msg, const std::string& strKey, const std::string& strValue);

					class ForEachUtil
					{
					public:
						/**
						* Simplifies the iteration about map.
						*
						* @param map
						*            the map to iterator.
						*
						* @param handler
						*            the handler to handle each map entry
						*/
						static void map(Message& msg, const  ZMQ_API::Properties&  mapProperty, handler phandler);
						//static void map(ZMQ_API::MQMessage& msg, const  ZMQ_API::Properties&  mapProperty, mqHandler phandler);
    					static void UserHandler(Message& msg,const std::string& strKey,const std::string& strValue);
						static void SystemHandler(Message& msg, const std::string& strKey, const std::string& strValue);
					};

				}
			}
		}
	}
}
#endif
