#ifndef _STRING_CONVERT_H
#define _STRING_CONVERT_H

#include <string>
class StringConvert
{
public:
	static int StringToInt(std::string strValue);
	static std::string IntToString(long nValue);
	static bool StringToBool(std::string strValue);
	static std::string BoolToString(const bool bValue);
};

#endif



