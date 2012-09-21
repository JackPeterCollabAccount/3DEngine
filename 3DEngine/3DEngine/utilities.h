#pragma once

#include "stdh.h"
#include <sstream>

template<class Type>
std::string ToString(Type value)
{
	std::stringstream temp;
	temp << value;
	return temp.str();
}

int getWindowHeight(HWND handle)
{
	RECT rect;
	if(GetClientRect(handle, &rect))
	{
		return rect.bottom - rect.top;
	}
	return 0;
}

int getWindowWidth(HWND handle)
{
	RECT rect;
	if(GetClientRect(handle, &rect))
	{
		return rect.right - rect.left;
	}
	return 0;
}

class EngineException
{
	public:
		EngineException(std::string why) : why(why) {}
		std::string virtual What()
		{
			return why;
		}

	private:
		std::string why;
};