#include <string.h>

#include "Input.h"

#include "../Framework/Log.h"
#include "../ICE.h"

extern ICE_Game game;
extern ICE_Core core;

ICE_Bool ICE_Input_Pressed(enum ICE_Key button)
{
	if (button < 512)
	{
		return core.window.input.Pressed[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return core.window.input.leftclic_pressed;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return core.window.input.rightclic_pressed;
		}
		if (button == ICE_KEY_WHEELUP)
		{
			return core.window.input.wheelup;
		}
		if (button == ICE_KEY_WHEELDOWN)
		{
			return core.window.input.wheeldown;
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
		return core.window.input.OnPress[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return core.window.input.leftclic_OnPress;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return core.window.input.rightclic_OnPress;
		}
	}
	ICE_Log(ICE_LOG_WARNING, "No key corresponding : %d", button);
	return ICE_False;
}

ICE_Bool ICE_Input_OnRelease(enum ICE_Key button)
{
	if (button < 512)
	{
		return core.window.input.OnRelease[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return core.window.input.leftclic_OnRelease;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return core.window.input.rightclic_OnRelease;
		}
	}
	ICE_Log(ICE_LOG_WARNING, "No key corresponding : %d", button);
	return ICE_False;
}

int ICE_Input_MouseX()
{
	return core.window.input.mousex;
}

int ICE_Input_MouseY()
{
	return core.window.input.mousey;
}

int ICE_Input_MouseX_World()
{
	ICE_Box translating  = ICE_Camera_ScreenWorld(ICE_Box_New(core.window.input.mousex, core.window.input.mousey,1, 1));
	return (int)translating.x;
}

int ICE_Input_MouseY_World()
{
	ICE_Box translating = ICE_Camera_ScreenWorld(ICE_Box_New(core.window.input.mousex, core.window.input.mousey, 1, 1));
	return (int)translating.y;
}

void ICE_Input_Quit()
{
	core.window.input.quit = ICE_True;
}

void ICE_Input_Reset() 
{
	int temp = core.window.input.focus;
	int temp2 = core.window.input.quit;
	int mousex = core.window.input.mousex;
	int mousey = core.window.input.mousey;
	memset(&core.window.input, 0, sizeof(ICE_Input));
	core.window.input.focus = temp;
	core.window.input.quit = temp2;
	core.window.input.mousex = mousex;
	core.window.input.mousey = mousey;
}