#include <SDL2/SDL.h>
#include "hdr/Core.h"
#include "hdr/TerminalColor.h"
#include "hdr/Render.h"
#include "hdr/Input.h"

int ICE_InitGameEngine(){
	ICE_TC_SaveColor();
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_AllocateChannels(20);
	Mix_VolumeMusic(5);
	return 0;
}

int ICE_CloseGameEngine(){
	SDL_Quit();
	return 0;
}

int ICE_GameLoop(ICE_Game(*call_create)(void), void(*call_update)(ICE_Game*), void(*call_destroy)(ICE_Game*)){
	ICE_InitGameEngine();
	ICE_Game game = call_create();
	while (!game.input->quit){
		game.time.actual = SDL_GetTicks(); // ticks since start of software at the start of loop
		game.time.ticksEllapsed = game.time.actual - game.time.last; // calculate nb of ticks ellapsed
		game.time.delta = (float)game.time.ticksEllapsed / 1000; // update the time.delta
		if (game.time.ticksEllapsed > game.time.ticks) {// if the ticks ellapsed is superiore to the ticks for a frame it run the loop
			game.time.fps = (float)(1000 / game.time.ticksEllapsed); // calculate fps
			ICE_InputReturn(&game, game.input);
			ICE_RenderClear(game.render);
			call_update(&game); // Call Update
			ICE_RenderPresent(game.render);
			game.time.last = game.time.actual; // restart counter
		}
		else // else it wait until the nb of ticks is enough to fix fps to max fps
			SDL_Delay((Uint32)(game.time.ticks - (game.time.actual - game.time.last)));
	}
	call_destroy(&game);
	ICE_CloseGameEngine();
	return 0;
}

// Create a substate with the ICE_Game but with new Create/Update/Destroy function. This must be called only for specifique thing
int ICE_SubstateLoop(ICE_Game* game, void(*call_create)(ICE_Game*), void(*call_update)(ICE_Game*), void(*call_destroy)(ICE_Game*)) {
	ICE_InputReset(game->input);
	call_create(game);
	game->input->substate_quit = 0;
	while (!game->input->quit && !game->input->substate_quit) {
		game->time.actual = SDL_GetTicks(); // ticks since start of software at the start of loop
		game->time.ticksEllapsed = game->time.actual - game->time.last; // calculate nb of ticks ellapsed
		game->time.delta = (float)game->time.ticksEllapsed / 1000; // update the time.delta
		if (game->time.ticksEllapsed > game->time.ticks) {// if the ticks ellapsed is superiore to the ticks for a frame it run the loop
			game->time.fps = (float)(1000 / game->time.ticksEllapsed); // calculate fps
			ICE_InputReturn(game, game->input);
			ICE_RenderClear(game->render);
			call_update(game); // Call Update
			ICE_RenderPresent(game->render);
			game->time.last = game->time.actual; // restart counter
		}
		else // else it wait until the nb of ticks is enough to fix fps to max fps
			SDL_Delay((Uint32)(game->time.ticks - (game->time.actual - game->time.last)));
	}
	game->input->substate_quit = 1;
	call_destroy(game);
	ICE_InputReset(game->input);
	return 0;
}
