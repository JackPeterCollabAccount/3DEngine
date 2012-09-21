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

enum Keys
{

ESCAPE = 0x01     
,NUM1  
,NUM2  
,NUM3           
,NUM4         
,NUM5          
,NUM6           
,NUM7           
,NUM8          
,NUM9              
,NUM0             
,MINUS           
,EQUALS        
,BACK            
,TAB             
,Q               
,W               
,E               
,R               
,T               
,Y               
,U               
,I               
,O               
,P               
,LBRACKET        
,RBRACKET        
,RETURN          
,LCONTROL        
,A               
,S               
,D               
,F               
,G               
,H               
,J               
,K               
,L               
,SEMICOLON       
,APOSTROPHE      
,GRAVE           
,LSHIFT          
,BACKSLASH       
,Z               
,X               
,C               
,V               
,B               
,N               
,M               
,COMMA           
,PERIOD          
,SLASH           
,RSHIFT          
,MULTIPLY        
,LMENU           
,SPACE           
,CAPITAL         
,F1              
,F2              
,F3              
,F4              
,F5              
,F6              
,F7              
,F8              
,F9              
,F10             
,NUMLOCK         
,SCROLL          
,NUMPAD7         
,NUMPAD8         
,NUMPAD9         
,SUBTRACT        
,NUMPAD4         
,NUMPAD5         
,NUMPAD6         
,ADD             
,NUMPAD1         
,NUMPAD2         
,NUMPAD3         
,NUMPAD0         
,NUMPADDECIMAL       
,OEM_102         
,F11             
,F12             
,F13             
,F14             
,F15             
,KANA            
,ABNT_C1         
,CONVERT         
,NOCONVERT       
,YEN             
,ABNT_C2         
,NUMPADEQUALS    
,PREVTRACK       
,AT              
,COLON           
,UNDERLINE       
,KANJI           
,STOP            
,AX              
,UNLABELED       
,NEXTTRACK       
,NUMPADENTER     
,RCONTROL        
,MUTE            
,CALCULATOR      
,PLAYPAUSE       
,MEDIASTOP       
,VOLUMEDOWN      
,VOLUMEUP        
,WEBHOME         
,NUMPADCOMMA     
,DIVIDE          
,SYSRQ           
,RMENU           
,PAUSE           
,HOME            
,UP              
,PRIOR           
,LEFT            
,RIGHT           
,END             
,DOWN            
,NEXT            
,INSERT 
,DEL        
,LWIN            
,RWIN            
,APPS            
,POWER           
,SLEEP           
,WAKE            
,WEBSEARCH       
,WEBFAVORITES    
,WEBREFRESH      
,WEBSTOP         
,WEBFORWARD      
,WEBBACK         
,MYCOMPUTER      
,MAIL            
,MEDIASELECT     

};