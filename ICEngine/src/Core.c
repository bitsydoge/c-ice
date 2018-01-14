#include <SDL2/SDL.h>
#include "hdr/Core.h"
#include <time.h>

extern iceGame game;

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

int iceCoreLoop(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void)) {
	iceCoreInit();
	call_create();
	while (!game.input->quit) {
		game.time.actual = SDL_GetTicks(); // ticks since start of software at the start of loop
		game.time.ticksEllapsed = game.time.actual - game.time.last; // calculate nb of ticks ellapsed
		game.time.delta = (double)game.time.ticksEllapsed / 1000; // update the time.delta
		//if (game.time.ticksEllapsed > game.time.ticks) {// if the ticks ellapsed is superiore to the ticks for a frame it run the loop
		if (game.time.ticksEllapsed)
			game.time.fps = (double)(1000 / game.time.ticksEllapsed); // calculate fps
		iceInputReturn();
		iceDrawClearColor(game.background);
		iceDrawClear();
		iceCameraUpdateAttach();

		call_update(); // Call Update

		// Rendering GameObject
		iceDrawAllEntity();
		iceDrawLabelWorld();
		iceDrawAllGui();
		iceDrawLabelScreen();
		//////////////////////////

		iceDrawPresent();
		game.time.last = game.time.actual; // restart counter
	//}
	//else // else it wait until the nb of ticks is enough to fix fps to max fps
		//SDL_Delay((Uint32)(game.time.ticks - (game.time.actual - game.time.last)));
	}
	call_destroy();
	iceCoreClose();
	return 0;
}