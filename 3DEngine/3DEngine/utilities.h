#pragma once

#include "stdh.h"
#include <sstream>
#include <vector>

template<class Type>
std::string ToString(Type value)
{
	std::stringstream temp;
	temp << value;
	return temp.str();
}

int getWindowHeight(HWND handle);

int getWindowWidth(HWND handle);



class EngineException;

std::vector<std::string> StrSplit(const std::string& strValue, char separator);