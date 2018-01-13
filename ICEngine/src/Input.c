#include <SDL2/SDL.h>
#include "hdr/Input.h"

extern iceGame game;

int iceInputReturn()
{
	static SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			game.input->quit = 1;
			break;
		case SDL_KEYDOWN:
			game.input->key[event.key.keysym.scancode] = 1;
			break;
		case SDL_KEYUP:
			game.input->key[event.key.keysym.scancode] = 0;
			break;
		case SDL_MOUSEWHEEL:
			if (event.wheel.y > 0)
				game.input->wheelup = 1;
			if (event.wheel.y < 0)
				game.input->wheeldown = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				game.input->leftclic = 1;
				game.input->leftclic_position_x = event.motion.x;
				game.input->leftclic_position_y = event.motion.y;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				game.input->rightclic = 1;
				game.input->rightclic_position_x = event.motion.x;
				game.input->rightclic_position_y = event.motion.y;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				game.input->leftclic = 0;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				game.input->rightclic = 0;
			}
			break;
		case SDL_MOUSEMOTION:
			game.input->mousex = event.motion.x;
			game.input->mousey = event.motion.y;
			break;
		case SDL_DROPFILE:
			game.input->filedrop = event.drop.file;
			break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				game.input->focus = 1;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				game.input->focus = 0;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				SDL_GetWindowSize(game.drawer.window, &game.camera.w, &game.camera.h);
				break;
			default:
				break;
			}
		default:
			break;
		}
		if (event.wheel.y == 0)
		{
			game.input->wheelup = 0;
			game.input->wheeldown = 0;
		}

		if (game.input->leftclic && !game.input->leftclic_trigger)
		{
			game.input->leftclic_trigger = 1;
			game.input->leftclic_position_x_old = game.input->leftclic_position_x;
			game.input->leftclic_position_y_old = game.input->leftclic_position_y;
		}

		if (!game.input->leftclic && game.input->leftclic_trigger)
		{
			game.input->leftclic_trigger = 0;
		}

	}
	return 0;
}

void iceInputReset(){
	int temp = game.input->focus;
	int temp2 = game.input->quit;
	int mousex = game.input->mousex;
	int mousey = game.input->mousey;
	memset(game.input, 0, sizeof(iceInput));
	game.input->focus = temp;
	game.input->quit = temp2;
	game.input->mousex = mousex;
	game.input->mousey = mousey;

	
	printf("Input Reset : ");
	iceTermSetColor(iceGREEN);
	printf("OK\n");
	iceTermResetColor();
}

iceBool iceInputButton(int button)
{
	if(button < 512)
	{
		return game.input->key[button];
	}
	if(button > 600)
	{
		if(button == ICE_INPUT_LEFTCLICK)
		{
			return game.input->leftclic;
		}
		if (button == ICE_INPUT_RIGHTCLICK)
		{
			return game.input->rightclic;
		}
		if (button == ICE_INPUT_WHEELUP)
		{
			return game.input->wheelup;
		}
		if (button == ICE_INPUT_WHEELDOWN)
		{
			return game.input->wheeldown;
		}
	}
	else
	{
		printf("No key have that name");
		return iceFalse;
	}

	return iceFalse;
}
