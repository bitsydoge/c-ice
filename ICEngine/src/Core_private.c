#include "hdr/Core_private.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "hdr/Terminal_private.h"
#include "hdr/Time_private.h"
#include "hdr/TypesCore.h"
#include "hdr/Label.h"
#include "hdr/Log.h"

extern ICE_Game game;

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

	ICE_Log(ICE_LOG_SUCCES, "ENGINE]::[OK");

	return 0;
}

int ICE_CoreClose() {
	
	// Manager Clean
	//free(game.label_mngr);
	ICE_LabelManagerDestroyAll();
	// SDL
	TTF_Quit();
	SDL_Quit();

	return 0;
}