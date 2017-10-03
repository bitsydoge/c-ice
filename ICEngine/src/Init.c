#include "hdr/Init.h"
#include <SDL2/SDL.h>

int ICE_InitGameEngine()
{
	
	SDL_Init(SDL_INIT_VIDEO);

	return 0;
}
