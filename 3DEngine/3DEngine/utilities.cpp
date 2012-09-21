#include "utilities.h"

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

std::vector<std::string> StrSplit(const std::string& strValue, char separator)
{
	std::vector<std::string> vecstrResult;
	int startpos=0;
	int endpos=0;

	endpos = strValue.find_first_of(separator, startpos);
	while (endpos != -1)
	{       
		vecstrResult.push_back(strValue.substr(startpos, endpos-startpos));
		startpos = endpos+1;
		endpos = strValue.find_first_of(separator, startpos);
		if(endpos==-1)
		{
			vecstrResult.push_back(strValue.substr(startpos));
		}
	}
		
	return vecstrResult;
}