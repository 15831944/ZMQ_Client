#ifndef _GENERAL_DEFINE_H_
#define _GENERAL_DEFINE_H_

#include "Exception.h"
#include "MQClientException.h"
#include "MQClientApiException.h"

#define ZMQCLIENT_API __declspec(dllexport)

#define ZMQ_API com::ztesoft::mq::client::api
#define ZMQ_IMPL com::ztesoft::mq::client::impl

#define CATCH_ZMQ_IMPL \
	catch (kpr::Exception& e)\
	{\
		throw ZMQ_API::MQClientApiException(e.what()); \
	}\
	catch (MQException& e)\
	{\
		throw ZMQ_API::MQClientApiException(e.what());\
	}\
	catch (...)\
    {\
		throw  ZMQ_API::MQClientApiException("Catch a unknown error!\n"); \
    }



enum ProcessStatus
{
	/**
* The message is processed successfully.
*/
	PS_Done,
	/**
* Unexpected problem happens, need to retry the process later.
*/
PS_Retry
};

enum OrderProcessStatus
{

	/**
* The message is consumed successfully.
*/
	OPS_Done,

	/**
* The message is failed to consume, and need to suspend for a while to continue.
*/
OPS_Suspend
};

#endif