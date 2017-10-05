#include "hdr/Init.h"
#include <SDL2/SDL.h>

int ICE_InitGameEngine()
{
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	return 0;
}

int ICE_CloseGameEngine()
{
	
	SDL_Quit();
	
	return 0;
}