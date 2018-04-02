#include "Input_private.h"

#include "TypesCore.h"

extern ICE_Game game;

void ICE_Input_Return()
{
	static SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		int get_w, get_h;
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
				game.window.input.leftclic_position_x = event.motion.x;
				game.window.input.leftclic_position_y = event.motion.y;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				game.window.input.rightclic = 1;
				game.window.input.rightclic_position_x = event.motion.x;
				game.window.input.rightclic_position_y = event.motion.y;
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
				SDL_GetWindowSize(game.window.handle, &get_w, &get_h);
				game.window.w = get_w; game.window.h = get_h;
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

		if (game.window.input.leftclic && !game.window.input.leftclic_trigger)
		{
			game.window.input.leftclic_trigger = 1;
			game.window.input.leftclic_position_x_old = game.window.input.leftclic_position_x;
			game.window.input.leftclic_position_y_old = game.window.input.leftclic_position_y;
		}

		if (!game.window.input.leftclic && game.window.input.leftclic_trigger)
		{
			game.window.input.leftclic_trigger = 0;
		}

	}
}