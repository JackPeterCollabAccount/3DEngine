#pragma once

#include <dinput.h>
#include <Windows.h>

//constants for mouse buttons (NEW)
#define DIMOUSE_LEFTBUTTON   0
#define DIMOUSE_RIGHTBUTTON  1
#define DIMOUSE_MIDDLEBUTTON 2
#define DIMOUSE_4BUTTON      3
#define DIMOUSE_5BUTTON      4
#define DIMOUSE_6BUTTON      5
#define DIMOUSE_7BUTTON      6
#define DIMOUSE_8BUTTON      7

class __declspec(dllexport) Input
{
public:
	class __declspec(dllexport) Keyboard
	{
	private:
	LPDIRECTINPUTDEVICE8 m_KeyboardDevice; //keyboard device
    char m_KeyBuffer[256];    //buffer for keys

	public:
		Keyboard(LPDIRECTINPUT8 input,HWND WindowHandle);
		~Keyboard();
		bool acquire();
		bool unAcquire();
		bool isKeyDown(int Key);
		bool isKeyUp(int Key);
		bool release();
	};

	class __declspec(dllexport) Mouse
	{
	private:
		LPDIRECTINPUTDEVICE8 m_MouseDevice; //mouse device
		HWND winHandle;
	public:
		Mouse(LPDIRECTINPUT8 input,HWND WindowHandle);
		~Mouse();
		bool acquire();
		bool unAcquire();
		POINT getPos();
		int getX();
		int getY();
		bool setPos(const POINT &p);
		bool setX(int X){return false;}
		bool setY(int Y){return false;}
		bool release();
	};

private:
	Keyboard* m_keyboard;
	Mouse* m_mouse;
    LPDIRECTINPUT8 m_input;

public:
	 Input(HWND windowHandle);
	~Input();
	bool initDirectInput(HWND windowHandle);
	Keyboard* getKeyboard();
	Mouse* getMouse();
	bool releaseKeyboard();
	bool releaseMouse();
	bool releaseAll();

protected:
	HWND WindowHandle;
};