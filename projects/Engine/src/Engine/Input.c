#include <string.h>

#include "Input.h"
#include "Input_private.h"

#include "../Framework/Log.h"
#include "Box.h"
#include <SDL2/SDL.h>
#include "Window_private.h"

ICE_Input ICE_GLOBJ_INPUT = {0};

ICE_Input * ICE_Input_GetPtr()
{
	return &ICE_GLOBJ_INPUT;
}

ICE_Bool ICE_Input_Pressed(enum ICE_Key button)
{
	if (button < 512)
	{
		return ICE_GLOBJ_INPUT.Pressed[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return ICE_GLOBJ_INPUT.leftclic_pressed;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return ICE_GLOBJ_INPUT.rightclic_pressed;
		}
		if (button == ICE_KEY_WHEELUP)
		{
			return ICE_GLOBJ_INPUT.wheelup;
		}
		if (button == ICE_KEY_WHEELDOWN)
		{
			return ICE_GLOBJ_INPUT.wheeldown;
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
		return ICE_GLOBJ_INPUT.OnPress[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return ICE_GLOBJ_INPUT.leftclic_OnPress;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return ICE_GLOBJ_INPUT.rightclic_OnPress;
		}
	}
	ICE_Log(ICE_LOGTYPE_WARNING, "No key corresponding : %d", button);
	return ICE_False;
}

ICE_Bool ICE_Input_OnRelease(enum ICE_Key button)
{
	if (button < 512)
	{
		return ICE_GLOBJ_INPUT.OnRelease[button];
	}
	if (button > 600 && button < ICE_KEY_MAX)
	{
		if (button == ICE_KEY_LEFTCLICK)
		{
			return ICE_GLOBJ_INPUT.leftclic_OnRelease;
		}
		if (button == ICE_KEY_RIGHTCLICK)
		{
			return ICE_GLOBJ_INPUT.rightclic_OnRelease;
		}
	}
	ICE_Log(ICE_LOGTYPE_WARNING, "No key corresponding : %d", button);
	return ICE_False;
}

int ICE_Input_MouseX()
{
	return ICE_GLOBJ_INPUT.mousex;
}

int ICE_Input_MouseY()
{
	return ICE_GLOBJ_INPUT.mousey;
}

ICE_Vect ICE_Input_MouseVector()
{
	return ICE_Vect_New(ICE_GLOBJ_INPUT.mousex, ICE_GLOBJ_INPUT.mousey);
}

int ICE_Input_MouseX_World()
{
	ICE_Vect translating = { 0 };// = ICE_Camera_Screen_to_World(ICE_Box_New(ICE_GLOBJ_INPUT.mousex, ICE_GLOBJ_INPUT.mousey, 1, 1));
	return (int)translating.x;
}

int ICE_Input_MouseY_World()
{
	ICE_Vect translating = { 0 };// = ICE_Camera_Screen_to_World(ICE_Box_New(ICE_GLOBJ_INPUT.mousex, ICE_GLOBJ_INPUT.mousey, 1, 1));
	return (int)translating.y;
}

ICE_Vect ICE_Input_MouseVector_World()
{
	ICE_Vect translating = {0};// = ICE_Camera_Screen_to_World(ICE_Box_New(ICE_GLOBJ_INPUT.mousex, ICE_GLOBJ_INPUT.mousey, 1, 1));
	return ICE_Vect_New(translating.x, translating.y);
}

void ICE_Input_Quit()
{
	//SDL_HideWindow(CORE.window.handle);
	ICE_GLOBJ_INPUT.quit = ICE_True;
}

void ICE_Input_Reset() 
{
	int temp = ICE_GLOBJ_INPUT.focus;
	int temp2 = ICE_GLOBJ_INPUT.quit;
	int mousex = ICE_GLOBJ_INPUT.mousex;
	int mousey = ICE_GLOBJ_INPUT.mousey;
	memset(&ICE_GLOBJ_INPUT, 0, sizeof(ICE_Input));
	ICE_GLOBJ_INPUT.focus = temp;
	ICE_GLOBJ_INPUT.quit = temp2;
	ICE_GLOBJ_INPUT.mousex = mousex;
	ICE_GLOBJ_INPUT.mousey = mousey;
}

void ICE_Input_Return()
{
	static SDL_Event event;

	// Reset one time event
	for (int i = 0; i < 512; i++)
	{
		ICE_GLOBJ_INPUT.OnPress[i] = 0;
		ICE_GLOBJ_INPUT.OnRelease[i] = 0;
	}

	ICE_GLOBJ_INPUT.leftclic_OnPress = 0;
	ICE_GLOBJ_INPUT.leftclic_OnRelease = 0;
	ICE_GLOBJ_INPUT.rightclic_OnPress = 0;
	ICE_GLOBJ_INPUT.rightclic_OnRelease = 0;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			ICE_GLOBJ_INPUT.quit = 1;
			break;
		case SDL_KEYDOWN:

			if (ICE_GLOBJ_INPUT.Pressed[event.key.keysym.scancode] == 0)
			{
				ICE_GLOBJ_INPUT.Pressed[event.key.keysym.scancode] = 1;
				ICE_GLOBJ_INPUT.OnPress[event.key.keysym.scancode] = 1;
			}
			break;
		case SDL_KEYUP:
			if (ICE_GLOBJ_INPUT.Pressed[event.key.keysym.scancode] == 1)
			{
				ICE_GLOBJ_INPUT.Pressed[event.key.keysym.scancode] = 0;
				ICE_GLOBJ_INPUT.OnRelease[event.key.keysym.scancode] = 1;
			}
			break;
		case SDL_MOUSEWHEEL:
			if (event.wheel.y > 0)
				ICE_GLOBJ_INPUT.wheelup = 1;
			if (event.wheel.y < 0)
				ICE_GLOBJ_INPUT.wheeldown = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				if (ICE_GLOBJ_INPUT.leftclic_pressed == 0)
				{
					ICE_GLOBJ_INPUT.leftclic_pressed = 1;
					ICE_GLOBJ_INPUT.leftclic_OnPress = 1;
				}
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				if (ICE_GLOBJ_INPUT.rightclic_pressed == 0)
				{
					ICE_GLOBJ_INPUT.rightclic_pressed = 1;
					ICE_GLOBJ_INPUT.rightclic_OnPress = 1;
				}
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				if (ICE_GLOBJ_INPUT.leftclic_pressed == 1)
				{
					ICE_GLOBJ_INPUT.leftclic_pressed = 0;
					ICE_GLOBJ_INPUT.leftclic_OnRelease = 1;
				}
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				if (ICE_GLOBJ_INPUT.rightclic_pressed == 1)
				{
					ICE_GLOBJ_INPUT.rightclic_pressed = 0;
					ICE_GLOBJ_INPUT.rightclic_OnRelease = 1;
				}
			}
			break;
		case SDL_MOUSEMOTION:
			ICE_GLOBJ_INPUT.mousex = event.motion.x;
			ICE_GLOBJ_INPUT.mousey = event.motion.y;
			break;
		case SDL_DROPFILE:
			ICE_GLOBJ_INPUT.filedrop = event.drop.file;
			break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				ICE_GLOBJ_INPUT.focus = 1;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				ICE_GLOBJ_INPUT.focus = 0;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				ICE_Window_GetPtr()->w = event.window.data1;
				ICE_Window_GetPtr()->h = event.window.data2;
				break;
			default:
				break;
			}
		default:
			break;
		}
		if (event.wheel.y == 0)
		{
			ICE_GLOBJ_INPUT.wheelup = 0;
			ICE_GLOBJ_INPUT.wheeldown = 0;
		}
	}
}