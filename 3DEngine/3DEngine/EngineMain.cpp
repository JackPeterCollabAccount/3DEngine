#include "EngineMain.h"
#include "liblitexml.h"
#include "utilities.h"

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPreviousInstance,LPSTR lpcmdline,int nCmdShow)
{
 HWND han_Window = NewWindow("New Game",100,100,500,500);

 int i = 0;

 LiteXML::LibLiteXML test;

 try
 {
	 test.Open("C:\\eula.1028.txt");
 }
 catch(LiteXML::LiteXMLException e)
 {
	 MessageBox(han_Window, e.What().c_str(), "Error", MB_OK | MB_ICONERROR);
 }

 MessageBox(han_Window, test.data.c_str(), "2", MB_OK);
 MessageBox(han_Window, ToString<float>(45.86f).c_str(), "Error", MB_OK);

 return i;
}

HWND NewWindow(LPCTSTR str_Title,int int_XPos, int int_YPos, int int_Width, int int_Height)
{
    WNDCLASSEX wnd_Structure;

    wnd_Structure.cbSize = sizeof(WNDCLASSEX);
    wnd_Structure.style = CS_HREDRAW | CS_VREDRAW;
    wnd_Structure.lpfnWndProc = OurWindowProcedure;
    wnd_Structure.cbClsExtra = 0;
    wnd_Structure.cbWndExtra = 0;
    wnd_Structure.hInstance = GetModuleHandle(NULL);
    wnd_Structure.hIcon = NULL;
    wnd_Structure.hCursor = NULL;
    wnd_Structure.hbrBackground = GetSysColorBrush(COLOR_BTNFACE);
    wnd_Structure.lpszMenuName = NULL;
    wnd_Structure.lpszClassName = "WindowClassName";
    wnd_Structure.hIconSm = LoadIcon(NULL,IDI_APPLICATION);

    RegisterClassEx(&wnd_Structure);

    return CreateWindowEx(WS_EX_CONTROLPARENT, "WindowClassName", str_Title, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, int_XPos, int_YPos, int_Width, int_Height, NULL, NULL, GetModuleHandle(NULL), NULL);
}

LRESULT CALLBACK OurWindowProcedure(HWND han_Wind,UINT uint_Message,WPARAM parameter1,LPARAM parameter2)
{
    switch(uint_Message)
    {
        case WM_KEYDOWN:
        {
            //int_AppRunning = 0;
            break;
        }
        break;
    }

    return DefWindowProc(han_Wind,uint_Message,parameter1,parameter2);
}