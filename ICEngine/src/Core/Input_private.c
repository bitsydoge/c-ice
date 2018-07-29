#include "Input_private.h"

#include "TypesCore.h"

extern ICE_Game game;

void ICE_Input_Return()
{
	static SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			game.window.input.quit = 1;
			break;
		case SDL_KEYDOWN:
			game.window.input.key[event.key.keysym.scancode] = 1;
			break;
		case SDL_KEYUP:
			game.window.input.key[event.key.keysym.scancode] = 0;
			break;
		case SDL_MOUSEWHEEL:
			if (event.wheel.y > 0)
				game.window.input.wheelup = 1;
			if (event.wheel.y < 0)
				game.window.input.wheeldown = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				game.window.input.leftclic = 1;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				game.window.input.rightclic = 1;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				game.window.input.leftclic = 0;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				game.window.input.rightclic = 0;
			}
			break;
		case SDL_MOUSEMOTION:
			game.window.input.mousex = event.motion.x;
			game.window.input.mousey = event.motion.y;
			break;
		case SDL_DROPFILE:
			game.window.input.filedrop = event.drop.file;
			break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				game.window.input.focus = 1;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				game.window.input.focus = 0;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				game.window.w = event.window.data1;
				game.window.h = event.window.data2;
				break;
			default:
				break;
			}
		default:
			break;
		}
		if (event.wheel.y == 0)
		{
			game.window.input.wheelup = 0;
			game.window.input.wheeldown = 0;
		}
	}
}