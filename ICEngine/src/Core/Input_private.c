#include "Input_private.h"

#include "TypesCore.h"

extern ICE_Game game;
extern ICE_Core core;

void ICE_Input_Return()
{
	static SDL_Event event;

	// Reset one time event
	for(int i = 0; i < 512; i++)
	{
			core.window.input.OnPress[i] = 0;
			core.window.input.OnRelease[i] = 0;
	}

	core.window.input.leftclic_OnPress = 0;
	core.window.input.leftclic_OnRelease = 0;
	core.window.input.rightclic_OnPress = 0;
	core.window.input.rightclic_OnRelease = 0;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			core.window.input.quit = 1;
			break;
		case SDL_KEYDOWN:
			
			if (core.window.input.Pressed[event.key.keysym.scancode] == 0)
			{
				core.window.input.Pressed[event.key.keysym.scancode] = 1;
				core.window.input.OnPress[event.key.keysym.scancode] = 1;
			}
			break;
		case SDL_KEYUP:
			if (core.window.input.Pressed[event.key.keysym.scancode] == 1)
			{
				core.window.input.Pressed[event.key.keysym.scancode] = 0;
				core.window.input.OnRelease[event.key.keysym.scancode] = 1;
			}	
			break;
		case SDL_MOUSEWHEEL:
			if (event.wheel.y > 0)
				core.window.input.wheelup = 1;
			if (event.wheel.y < 0)
				core.window.input.wheeldown = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				if (core.window.input.leftclic_pressed == 0)
				{
					core.window.input.leftclic_pressed = 1;
					core.window.input.leftclic_OnPress = 1;
				}
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				if (core.window.input.rightclic_pressed == 0)
				{
					core.window.input.rightclic_pressed = 1;
					core.window.input.rightclic_OnPress = 1;
				}
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				if (core.window.input.leftclic_pressed == 1)
				{
					core.window.input.leftclic_pressed = 0;
					core.window.input.leftclic_OnRelease = 1;
				}
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				if (core.window.input.rightclic_pressed == 1)
				{
					core.window.input.rightclic_pressed = 0;
					core.window.input.rightclic_OnRelease = 1;
				}
			}
			break;
		case SDL_MOUSEMOTION:
			core.window.input.mousex = event.motion.x;
			core.window.input.mousey = event.motion.y;
			break;
		case SDL_DROPFILE:
			core.window.input.filedrop = event.drop.file;
			break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				core.window.input.focus = 1;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				core.window.input.focus = 0;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				core.window.w = event.window.data1;
				core.window.h = event.window.data2;
				break;
			default:
				break;
			}
		default:
			break;
		}
		if (event.wheel.y == 0)
		{
			core.window.input.wheelup = 0;
			core.window.input.wheeldown = 0;
		}
	}
}