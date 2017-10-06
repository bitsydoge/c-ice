#include "hdr/Init.h"
#include "hdr/TerminalColor.h"
#include <SDL2/SDL.h>

int ICE_InitGameEngine()
{
	ICE_TC_SetBackgroundColor(GREY);
	cls();
	ICE_TC_SetColor(BLACK);
	ICE_TC_SaveColor();
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
	return 0;
}

int ICE_CloseGameEngine()
{
	SDL_Quit();	
	return 0;
}