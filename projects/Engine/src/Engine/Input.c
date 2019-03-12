#include <string.h>

#include "Input.h"
#include "Input_private.h"

#include "../Framework/Log.h"
#include "Box.h"
#include <SDL2/SDL.h>

ICE_Input OBJ_INPUT = {0};

ICE_Bool ICE_Input_Pressed(enum ICE_Key button)
{
	if (button < 512)
	{
		return OBJ_INPUT.Pressed[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return OBJ_INPUT.leftclic_pressed;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return OBJ_INPUT.rightclic_pressed;
		}
		if (button == ICE_KEY_WHEELUP)
		{
			return OBJ_INPUT.wheelup;
		}
		if (button == ICE_KEY_WHEELDOWN)
		{
			return OBJ_INPUT.wheeldown;
		}
	}
	else
	{
		ICE_Log(ICE_LOGTYPE_WARNING, "No key corresponding : %d", button);
		return ICE_False;
	}

	return ICE_False;
}

ICE_Bool ICE_Input_OnPress(enum ICE_Key button)
{
	if (button < 512)
	{
		return OBJ_INPUT.OnPress[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return OBJ_INPUT.leftclic_OnPress;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return OBJ_INPUT.rightclic_OnPress;
		}
	}
	ICE_Log(ICE_LOGTYPE_WARNING, "No key corresponding : %d", button);
	return ICE_False;
}

ICE_Bool ICE_Input_OnRelease(enum ICE_Key button)
{
	if (button < 512)
	{
		return OBJ_INPUT.OnRelease[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return OBJ_INPUT.leftclic_OnRelease;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return OBJ_INPUT.rightclic_OnRelease;
		}
	}
	ICE_Log(ICE_LOGTYPE_WARNING, "No key corresponding : %d", button);
	return ICE_False;
}

int ICE_Input_MouseX()
{
	return OBJ_INPUT.mousex;
}

int ICE_Input_MouseY()
{
	return OBJ_INPUT.mousey;
}

ICE_Vect ICE_Input_MouseVector()
{
	return ICE_Vect_New(OBJ_INPUT.mousex, OBJ_INPUT.mousey);
}

int ICE_Input_MouseX_World()
{
	ICE_Box translating = { 0 };// = ICE_Camera_ScreenWorld(ICE_Box_New(OBJ_INPUT.mousex, OBJ_INPUT.mousey, 1, 1));
	return (int)translating.x;
}

int ICE_Input_MouseY_World()
{
	ICE_Box translating = { 0 };// = ICE_Camera_ScreenWorld(ICE_Box_New(OBJ_INPUT.mousex, OBJ_INPUT.mousey, 1, 1));
	return (int)translating.y;
}

ICE_Vect ICE_Input_MouseVector_World()
{
	ICE_Box translating = {0};// = ICE_Camera_ScreenWorld(ICE_Box_New(OBJ_INPUT.mousex, OBJ_INPUT.mousey, 1, 1));
	return ICE_Vect_New(translating.x, translating.y);
}

void ICE_Input_Quit()
{
	//SDL_HideWindow(CORE.window.handle);
	OBJ_INPUT.quit = ICE_True;
}

void ICE_Input_Reset() 
{
	int temp = OBJ_INPUT.focus;
	int temp2 = OBJ_INPUT.quit;
	int mousex = OBJ_INPUT.mousex;
	int mousey = OBJ_INPUT.mousey;
	memset(&OBJ_INPUT, 0, sizeof(ICE_Input));
	OBJ_INPUT.focus = temp;
	OBJ_INPUT.quit = temp2;
	OBJ_INPUT.mousex = mousex;
	OBJ_INPUT.mousey = mousey;
}

void ICE_Input_Return()
{
	static SDL_Event event;

	// Reset one time event
	for (int i = 0; i < 512; i++)
	{
		OBJ_INPUT.OnPress[i] = 0;
		OBJ_INPUT.OnRelease[i] = 0;
	}

	OBJ_INPUT.leftclic_OnPress = 0;
	OBJ_INPUT.leftclic_OnRelease = 0;
	OBJ_INPUT.rightclic_OnPress = 0;
	OBJ_INPUT.rightclic_OnRelease = 0;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			OBJ_INPUT.quit = 1;
			break;
		case SDL_KEYDOWN:

			if (OBJ_INPUT.Pressed[event.key.keysym.scancode] == 0)
			{
				OBJ_INPUT.Pressed[event.key.keysym.scancode] = 1;
				OBJ_INPUT.OnPress[event.key.keysym.scancode] = 1;
			}
			break;
		case SDL_KEYUP:
			if (OBJ_INPUT.Pressed[event.key.keysym.scancode] == 1)
			{
				OBJ_INPUT.Pressed[event.key.keysym.scancode] = 0;
				OBJ_INPUT.OnRelease[event.key.keysym.scancode] = 1;
			}
			break;
		case SDL_MOUSEWHEEL:
			if (event.wheel.y > 0)
				OBJ_INPUT.wheelup = 1;
			if (event.wheel.y < 0)
				OBJ_INPUT.wheeldown = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				if (OBJ_INPUT.leftclic_pressed == 0)
				{
					OBJ_INPUT.leftclic_pressed = 1;
					OBJ_INPUT.leftclic_OnPress = 1;
				}
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				if (OBJ_INPUT.rightclic_pressed == 0)
				{
					OBJ_INPUT.rightclic_pressed = 1;
					OBJ_INPUT.rightclic_OnPress = 1;
				}
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				if (OBJ_INPUT.leftclic_pressed == 1)
				{
					OBJ_INPUT.leftclic_pressed = 0;
					OBJ_INPUT.leftclic_OnRelease = 1;
				}
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				if (OBJ_INPUT.rightclic_pressed == 1)
				{
					OBJ_INPUT.rightclic_pressed = 0;
					OBJ_INPUT.rightclic_OnRelease = 1;
				}
			}
			break;
		case SDL_MOUSEMOTION:
			OBJ_INPUT.mousex = event.motion.x;
			OBJ_INPUT.mousey = event.motion.y;
			break;
		case SDL_DROPFILE:
			OBJ_INPUT.filedrop = event.drop.file;
			break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				OBJ_INPUT.focus = 1;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				OBJ_INPUT.focus = 0;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				//CORE.window.w = event.window.data1;
				//CORE.window.h = event.window.data2;
				break;
			default:
				break;
			}
		default:
			break;
		}
		if (event.wheel.y == 0)
		{
			OBJ_INPUT.wheelup = 0;
			OBJ_INPUT.wheeldown = 0;
		}
	}
}