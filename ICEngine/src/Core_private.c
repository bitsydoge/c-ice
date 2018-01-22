#include "hdr/Core_private.h"
#include "hdr/TypesAudio.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "hdr/Terminal.h"
#include "hdr/Random.h"

int iceCoreInit() {
	iceRandomInit();
	iceTermSaveColor();
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	TTF_Init();
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_AllocateChannels(20);
	Mix_VolumeMusic(5);
	return 0;
}

int iceCoreClose() {
	SDL_Quit();
	Mix_CloseAudio();
	return 0;
}