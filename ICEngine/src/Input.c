#include <SDL2/SDL.h>
#include <string.h>
#include <stdio.h>

#include "hdr/Input.h"
#include "hdr/Terminal.h"

extern iceGame game;

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

void iceInputReset() {
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