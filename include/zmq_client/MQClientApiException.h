#ifndef _MQ_CLIENT_API_EXCEPTION_H_
#define _MQ_CLIENT_API_EXCEPTION_H_

#include <string>

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
					* This class is to represent as the api exception about mq client.
					*/
					class MQClientApiException
					{
					public:
						MQClientApiException(std::string strMsg){ m_strMsg = strMsg; }
						
						
						std::string what(){ return m_strMsg; }

					private:
						std::string m_strMsg;
					};

				}
			}
		}
	}
}

#endif

