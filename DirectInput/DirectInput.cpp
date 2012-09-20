#include "DirectInput.h"

#pragma region

Input::Input(HWND windowHandle)
{
	WindowHandle = windowHandle;
	initDirectInput(WindowHandle);
	m_keyboard = NULL;
	m_mouse = NULL;
}

bool Input::initDirectInput(HWND windowHandle)
{
	if(FAILED(DirectInput8Create(GetModuleHandle(NULL),
                             DIRECTINPUT_VERSION,
                             IID_IDirectInput8,
                             (void**)&m_input,
                             NULL)))
 {
 MessageBox(windowHandle,
            "DirectInput8Create() failed!",
            "InitDirectInput()",
            MB_OK);
	return false;
 }

return true;
}

Input::Keyboard* Input::getKeyboard()
{
	if (m_keyboard == NULL)
		m_keyboard = new Keyboard(m_input, this->WindowHandle);
	
	return m_keyboard;
}

Input::Mouse* Input::getMouse()
{
	if (m_mouse == NULL)
		m_mouse = new Mouse(m_input, this->WindowHandle);

	return m_mouse;
}

Input::~Input()
{
	releaseAll();
}

bool Input::releaseKeyboard()
{
	if(m_keyboard != NULL)
	{
		m_keyboard->unAcquire();
		m_keyboard->release();
		m_keyboard = NULL;
	}
	delete m_keyboard;

	return true;
}

bool Input::releaseMouse()
{
	if(m_mouse != NULL)
	{
		m_mouse->unAcquire();
		m_mouse->release();
		m_mouse = NULL;
	}
	delete m_mouse;

	return true;
}

bool Input::releaseAll()
{
	releaseKeyboard();
	releaseMouse();
	if (m_input != NULL)
	{
		m_input->Release();
		m_input = NULL;
	}

	return true;
}

#pragma endregion Input Implementation

#pragma region

Input::Keyboard::Keyboard(LPDIRECTINPUT8 input, HWND WindowHandle)
{

	if(FAILED(input->CreateDevice(GUID_SysKeyboard,
                                    &m_KeyboardDevice,
                                    NULL)))
	{
 MessageBox(WindowHandle,
            "SetDataFormat() failed!",
            "InitKeyboard()",
            MB_OK);
	return;
	}
	
	if(FAILED(m_KeyboardDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
 MessageBox(WindowHandle,
            "SetDataFormat() failed!",
            "InitKeyboard()",
            MB_OK);
	return;
	}

	if(FAILED(m_KeyboardDevice->SetCooperativeLevel(WindowHandle,
                                                   DISCL_BACKGROUND | 
                                                   DISCL_NONEXCLUSIVE)))
	{
 MessageBox(WindowHandle,
            "SetDataFormat() failed!",
            "InitKeyboard()",
            MB_OK);
	return;
	}

	if(FAILED(m_KeyboardDevice->Acquire()))
	{
	MessageBox(WindowHandle,
            "Acquire() failed!",
            "InitKeyboard()",
            MB_OK);
		return;
	}
}

Input::Keyboard::~Keyboard()
{
	release();
}

bool Input::Keyboard::release()
{
	if(m_KeyboardDevice != NULL)
	{
	unAcquire();
	if(FAILED(m_KeyboardDevice->Release()))
		return false;
	m_KeyboardDevice = NULL;
	}
	return true;
}

bool Input::Keyboard::unAcquire()
{
	if(m_KeyboardDevice != NULL)
	{
	if(FAILED(m_KeyboardDevice->Unacquire()))
		return false;
	}
	return true;
}

bool Input::Keyboard::acquire()
{
	if(m_KeyboardDevice != NULL)
	{
	if(FAILED(m_KeyboardDevice->Acquire()))
		return false;
	}
	return true;
}

bool Input::Keyboard::isKeyDown(int Key)
{
	if(FAILED(m_KeyboardDevice->Poll()))
		if(!acquire())
		{
			return false;
		}

	if(FAILED(m_KeyboardDevice->GetDeviceState(sizeof(m_KeyBuffer),(LPVOID)&m_KeyBuffer)))
	{
		return false;
	}

	if(m_KeyBuffer[Key] & 0x80)
	{
		return true;
	}
	return false;
}

bool Input::Keyboard::isKeyUp(int Key)
{
	return !isKeyDown(Key);
}

#pragma endregion Keyboard Implementation

#pragma region

Input::Mouse::Mouse(LPDIRECTINPUT8 input,HWND WindowHandle) : winHandle(WindowHandle)
{
	DIDEVCAPS MouseCapabilities; //device capabilities

	if(FAILED(input->CreateDevice(GUID_SysMouse,
                                    &m_MouseDevice,
                                    NULL)))
	{
		MessageBox(WindowHandle,
            "CreateDevice() failed!",
            "InitMouse()",
            MB_OK);
		return;
	}

	if(FAILED(m_MouseDevice->SetDataFormat(&c_dfDIMouse2)))
	{
		MessageBox(WindowHandle,
            "SetDataFormat() failed!",
            "InitMouse()",
            MB_OK);
		return;
	}

	if(FAILED(m_MouseDevice->SetCooperativeLevel(WindowHandle,
                                                DISCL_BACKGROUND | 
                                                DISCL_NONEXCLUSIVE)))
	{
		MessageBox(WindowHandle,
            "SetCooperativeLevel() failed!",
            "InitMouse()",
            MB_OK);
		return;
	}

	if(!acquire())
	{
		MessageBox(WindowHandle,
            "Acquire() failed!",
            "InitMouse()",
            MB_OK);
		return;
	}

}

Input::Mouse::~Mouse()
{
	release();
}

bool Input::Mouse::release()
{
	if(m_MouseDevice != NULL)
	{
		m_MouseDevice->Release();
		m_MouseDevice = NULL;
	}
	return true;
}

bool Input::Mouse::acquire()
{
	if(FAILED(m_MouseDevice->Acquire()))
	{
		return false;
	}

	return true;
}

bool Input::Mouse::unAcquire()
{
	if(FAILED(m_MouseDevice->Unacquire()))
	{
		return false;
	}
	return true;
}

POINT Input::Mouse::getPos()
{
	POINT p;
	GetCursorPos(&p);
	ScreenToClient(winHandle, &p);
	return p;
}

int Input::Mouse::getX()
{
	return getPos().x;
}

int Input::Mouse::getY()
{
	return getPos().y;
}

bool Input::Mouse::setPos(const POINT &p)
{
	WINDOWINFO info;
	GetWindowInfo(winHandle, &info);
	RECT rect = info.rcClient;
	if(!SetCursorPos(rect.left + p.x, rect.top + p.y))
		return false;

	return true;
}

#pragma endregion Mouse Implementation