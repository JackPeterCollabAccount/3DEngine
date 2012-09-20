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