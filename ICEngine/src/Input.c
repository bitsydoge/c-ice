#include <SDL2/SDL.h>
#include <string.h>
#include <stdio.h>
#include "hdr/Input.h"


int ICE_InputReturn(ICE_Input *input)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			input->quit = 1;
			break;
		case SDL_KEYDOWN:
			input->key[event.key.keysym.scancode] = 1;
			break;
		case SDL_KEYUP:
			input->key[event.key.keysym.scancode] = 0;
			break;
		case SDL_MOUSEWHEEL:
			if (event.wheel.y > 0)
				input->wheelup = 1;
			if (event.wheel.y < 0)
				input->wheeldown = 1;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				input->leftclic = 1;
				input->leftclic_position_x = event.motion.x;
				input->leftclic_position_y = event.motion.y;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				input->rightclic = 1;
				input->rightclic_position_x = event.motion.x;
				input->rightclic_position_y = event.motion.y;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				input->leftclic = 0;
			}
			if (event.button.button == SDL_BUTTON_RIGHT)
			{
				input->rightclic = 0;
			}
			break;
		case SDL_MOUSEMOTION:
			input->mousex = event.motion.x;
			input->mousey = event.motion.y;
			break;
		case SDL_DROPFILE:
			input->filedrop = event.drop.file;
			break;
		case SDL_WINDOWEVENT:
			switch (event.window.event)
			{
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				input->focus = 1;
				break;
			case SDL_WINDOWEVENT_FOCUS_LOST:
				input->focus = 0;
				break;
			case SDL_WINDOWEVENT_RESIZED:
				//Windows resizer
				break;
			default:
				break;
			}
		default:
			break;
		}
		if (event.wheel.y == 0)
		{
			input->wheelup = 0;
			input->wheeldown = 0;
		}

		if (input->leftclic && !input->leftclic_trigger)
		{
			input->leftclic_trigger = 1;
			input->leftclic_position_x_old = input->leftclic_position_x;
			input->leftclic_position_y_old = input->leftclic_position_y;
		}

		if (!input->leftclic && input->leftclic_trigger)
		{
			input->leftclic_trigger = 0;
		}

	}
	return 0;
}

void ICE_InputReset(ICE_Input *input)
{
	int temp = input->focus;
	memset(input, 0, sizeof(ICE_Input));
	input->focus = temp;
	printf("	Initialize Input : OK \n");
}