#include <SDL2/SDL.h>
#include <string.h>
#include <stdio.h>

#include "hdr/Input.h"
#include "hdr/Terminal.h"
#include "hdr/Debug.h"

extern ICE_Game game;

ICE_Bool ICE_InputButton(const int button)
{
	if (button < 512)
	{
		return game.window.input.key[button];
	}
	if (button > 600 && button < ICE_INPUT_MAX)
	{
		if (button == ICE_INPUT_LEFTCLICK)
		{
			return game.window.input.leftclic;
		}
		if (button == ICE_INPUT_RIGHTCLICK)
		{
			return game.window.input.rightclic;
		}
		if (button == ICE_INPUT_WHEELUP)
		{
			return game.window.input.wheelup;
		}
		if (button == ICE_INPUT_WHEELDOWN)
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

void ICE_InputQuit()
{
	game.window.input.quit = ICE_True;
}

void ICE_InputReset() {
	int temp = game.window.input.focus;
	int temp2 = game.window.input.quit;
	int mousex = game.window.input.mousex;
	int mousey = game.window.input.mousey;
	memset(&game.window.input, 0, sizeof(ICE_Input));
	game.window.input.focus = temp;
	game.window.input.quit = temp2;
	game.window.input.mousex = mousex;
	game.window.input.mousey = mousey;


	printf("Input Reset : ");
	ICE_TermSetColor(iceGREEN);
	printf("OK\n");
	ICE_TermResetColor();
}