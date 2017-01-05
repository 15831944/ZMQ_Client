#include "zmq_client/StringConvert.h"
#include <sstream>
#include <stdlib.h>
using namespace std;


int StringConvert::StringToInt(std::string strValue)
{
	if (strValue.empty())
	{
		return 0;
	}

	return atoi(strValue.c_str());
}

std::string StringConvert::IntToString(long nValue)
{
	stringstream stream;
	stream << nValue;

	return stream.str();
}

bool StringConvert::StringToBool(std::string strValue)
{
	if (strValue.empty())
	{
		return false;
	}
	
	bool bResult;
	stringstream stream;
	stream << strValue;
	stream >> bResult;

	return bResult;
}

std::string StringConvert::BoolToString(const bool bValue)
{
	if (bValue)
	{
		return std::string("1");
	}
	else
	{
		return std::string("0");
	}
}
