#pragma once

#include "stdh.h"

HWND NewWindow(LPCTSTR str_Title,int int_XPos, int int_YPos, int int_Width, int int_Height);
LRESULT CALLBACK OurWindowProcedure(HWND han_Wind,UINT uint_Message,WPARAM parameter1,LPARAM parameter2);