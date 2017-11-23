#include "hdr/Substate.h"

// Create a substate with the iceGame but with new Create/Update/Destroy function. This must be called only for specifique thing


int iceSubstateLoop(iceGame* game, void(*call_create)(iceGame*), void(*call_update)(iceGame*), void(*call_destroy)(iceGame*)) {
	iceInputReset(game->input);
	call_create(game);
	game->input->substate_quit = 0;
	while (!game->input->quit && !game->input->substate_quit) {
		game->time.actual = SDL_GetTicks(); // ticks since start of software at the start of loop
		game->time.ticksEllapsed = game->time.actual - game->time.last; // calculate nb of ticks ellapsed
		game->time.delta = (float)game->time.ticksEllapsed / 1000; // update the time.delta
		if (game->time.ticksEllapsed > game->time.ticks) {// if the ticks ellapsed is superiore to the ticks for a frame it run the loop
			game->time.fps = (float)(1000 / game->time.ticksEllapsed); // calculate fps
			iceInputReturn(game, game->input);
			iceRenderClear(game->render);
			call_update(game); // Call Update
			game->time.last = game->time.actual; // restart counter
		}
		else // else it wait until the nb of ticks is enough to fix fps to max fps
			SDL_Delay((Uint32)(game->time.ticks - (game->time.actual - game->time.last)));
	}
	game->input->substate_quit = 1;
	call_destroy(game);
	int returnvalue = game->returnvalue;
	iceGameDestroy(game);
	iceInputReset(game->input);
	return returnvalue;
}
