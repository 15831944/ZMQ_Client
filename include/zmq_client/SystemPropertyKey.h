#ifndef _SYSTEM_PEROPERTY_KEY_H_
#define _SYSTEM_PEROPERTY_KEY_H_

#include <string>
#include <set>
#include "Properties.h"

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
					 * This class is to represent to manage the keys used by system API and intra implementation.
					 */
					class SystemPropertyKey 
					{
					public:
						static SystemPropertyKey& instance();
					
						void init();
						/**
						 * Returns true if the key is reserved to be used by client API.
						 * 
						 * @param key
						 *            the key name
						 * @return whether the key is used
						 */
						 bool containApiKey(const std::string& key);
						

						/**
						 * Returns true if the key is reserved to be used by client intra implementation about map.
						 * 
						 * @param key
						 *            the key name
						 * @return whether the key is used
						 */
						 bool containIntraMapImplKey(const std::string& key);
					
    
						/**
						 * Returns true if the key is reserved to be used by client intra implementation.
						 * 
						 * @param key
						 *            the key name
						 * @return whether the key is used
						 */
						 bool containIntraImplKey(const std::string& key);
					private:
						 SystemPropertyKey(){}
						 std::set<std::string> SystemKeySet;
						 std::set<std::string> IntraSystemKeySet;
						 std::set<std::string> IntraMapSystemKeySet;

						 static bool m_isInit;

					};

				}
			}
		}
	}
}

#endif
