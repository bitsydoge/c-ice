#include "hdr/Core_private.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "hdr/Terminal_private.h"
#include "hdr/Time_private.h"

int ICE_CoreInit() {


	// Other
	ICE_TermSaveColor();
	ICE_TermHideCursor();

	// SDL
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	TTF_Init();
	
	// SDL_gfx
	ICE_TimeInit();

	return 0;
}

int ICE_CoreClose() {
	// SDL
	TTF_Quit();
	SDL_Quit();

	return 0;
}