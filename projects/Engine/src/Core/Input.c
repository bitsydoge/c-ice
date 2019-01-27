#include <string.h>

#include "Input.h"

#include "../Framework/Log.h"
#include "../Graphics/Camera.h"
#include "../Maths/Box.h"

extern ICE_Game GAME;
extern ICE_Core CORE;

ICE_Bool ICE_Input_Pressed(enum ICE_Key button)
{
	if (button < 512)
	{
		return CORE.window.input.Pressed[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return CORE.window.input.leftclic_pressed;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return CORE.window.input.rightclic_pressed;
		}
		if (button == ICE_KEY_WHEELUP)
		{
			return CORE.window.input.wheelup;
		}
		if (button == ICE_KEY_WHEELDOWN)
		{
			return CORE.window.input.wheeldown;
		}
	}
	else
	{
		ICE_Log(ICE_LOG_WARNING, "No key corresponding : %d", button);
		return ICE_False;
	}

	return ICE_False;
}

ICE_Bool ICE_Input_OnPress(enum ICE_Key button)
{
	if (button < 512)
	{
		return CORE.window.input.OnPress[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return CORE.window.input.leftclic_OnPress;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return CORE.window.input.rightclic_OnPress;
		}
	}
	ICE_Log(ICE_LOG_WARNING, "No key corresponding : %d", button);
	return ICE_False;
}

ICE_Bool ICE_Input_OnRelease(enum ICE_Key button)
{
	if (button < 512)
	{
		return CORE.window.input.OnRelease[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return CORE.window.input.leftclic_OnRelease;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return CORE.window.input.rightclic_OnRelease;
		}
	}
	ICE_Log(ICE_LOG_WARNING, "No key corresponding : %d", button);
	return ICE_False;
}

int ICE_Input_MouseX()
{
	return CORE.window.input.mousex;
}

int ICE_Input_MouseY()
{
	return CORE.window.input.mousey;
}

int ICE_Input_MouseX_World()
{
	ICE_Box translating  = ICE_Camera_ScreenWorld(ICE_Box_New(CORE.window.input.mousex, CORE.window.input.mousey,1, 1));
	return (int)translating.x;
}

int ICE_Input_MouseY_World()
{
	ICE_Box translating = ICE_Camera_ScreenWorld(ICE_Box_New(CORE.window.input.mousex, CORE.window.input.mousey, 1, 1));
	return (int)translating.y;
}

void ICE_Input_Quit()
{
	SDL_HideWindow(CORE.window.handle);
	CORE.window.input.quit = ICE_True;
}

void ICE_Input_Reset() 
{
	int temp = CORE.window.input.focus;
	int temp2 = CORE.window.input.quit;
	int mousex = CORE.window.input.mousex;
	int mousey = CORE.window.input.mousey;
	memset(&CORE.window.input, 0, sizeof(ICE_Input));
	CORE.window.input.focus = temp;
	CORE.window.input.quit = temp2;
	CORE.window.input.mousex = mousex;
	CORE.window.input.mousey = mousey;
}