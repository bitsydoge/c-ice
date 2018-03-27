﻿#include "hdr/Core_private.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "hdr/Terminal_private.h"
#include "hdr/Time_private.h"
#include "hdr/TypesCore.h"
#include "hdr/Label.h"
#include "hdr/Log.h"
#include <stdio.h>

extern ICE_Game game;

int ICE_Core_Init() {
	// Other
	ICE_Term_SaveColor();
	printf("------------------------\n");
	ICE_Log(ICE_LOG_RUNNING, "Engine]::[Init]::[Start");
	printf("------------------------\n");
	ICE_Term_HideCursor();

	// SDL
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	TTF_Init();
	
	// SDL_gfx
	ICE_Time_Init();

	return 0;
}

int ICE_Core_Close() {
	printf("------------------------\n");
	ICE_Log(ICE_LOG_RUNNING, "Engine]::[Close]::[Start");
	printf("------------------------\n");

	// Manager Clean
	//free(game.label_mngr);
	ICE_LabelManager_DestroyAll();
	// SDL
	TTF_Quit();
	SDL_Quit();

	printf("------------------------\n");
	ICE_Log(ICE_LOG_SUCCES, "Engine]::[Close]::[Finish");
	printf("------------------------\n\n");


	return 0;
}