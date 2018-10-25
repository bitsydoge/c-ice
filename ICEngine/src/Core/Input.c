#include <string.h>

#include "Input.h"

#include "../Framework/Log.h"

extern ICE_Game game;

ICE_Bool ICE_Input_IsPressed(enum ICE_Key button)
{
	if (button < 512)
	{
		return game.window.input.Pressed[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return game.window.input.leftclic_pressed;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return game.window.input.rightclic_pressed;
		}
		if (button == ICE_KEY_WHEELUP)
		{
			return game.window.input.wheelup;
		}
		if (button == ICE_KEY_WHEELDOWN)
		{
			return game.window.input.wheeldown;
		}
	}
	else
	{
		ICE_Log(ICE_LOG_WARNING, "INPUT]::[NOKEY]::[%d", button);
		return ICE_False;
	}

	return ICE_False;
}

ICE_Bool ICE_Input_OnPress(enum ICE_Key button)
{
	if (button < 512)
	{
		return game.window.input.OnPress[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return game.window.input.leftclic_OnPress;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return game.window.input.rightclic_OnPress;
		}
	}
	ICE_Log(ICE_LOG_WARNING, "INPUT]::[NOKEY]::[%d", button);
	return ICE_False;
}

ICE_Bool ICE_Input_OnRelease(enum ICE_Key button)
{
	if (button < 512)
	{
		return game.window.input.OnRelease[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return game.window.input.leftclic_OnRelease;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return game.window.input.rightclic_OnRelease;
		}
	}
	ICE_Log(ICE_LOG_WARNING, "INPUT]::[NOKEY]::[%d", button);
	return ICE_False;
}

int ICE_Input_MouseX()
{
	return game.window.input.mousex;
}

int ICE_Input_MouseY()
{
	return game.window.input.mousey;
}

void ICE_Input_Quit()
{
	game.window.input.quit = ICE_True;
}

void ICE_Input_Reset() 
{
	int temp = game.window.input.focus;
	int temp2 = game.window.input.quit;
	int mousex = game.window.input.mousex;
	int mousey = game.window.input.mousey;
	memset(&game.window.input, 0, sizeof(ICE_Input));
	game.window.input.focus = temp;
	game.window.input.quit = temp2;
	game.window.input.mousex = mousex;
	game.window.input.mousey = mousey;
}