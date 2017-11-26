#include "hdr/Substate.h"

// Create a substate with the iceGame but with new Create/Update/Destroy function. This must be called only for specifique thing

int iceSubstateLoop(iceGame* game, void(*call_create)(iceGame*), void(*call_update)(iceGame*), void(*call_destroy)(iceGame*)) {
	iceInputReset(game->input);
	call_create(game);
	game->input->substate_quit = 0;
	while (!game->input->quit && !game->input->substate_quit) {
		game->time.actual = SDL_GetTicks(); // ticks since start of software at the start of loop
		game->time.ticksEllapsed = game->time.actual - game->time.last; // calculate nb of ticks ellapsed
		game->time.delta = (double)game->time.ticksEllapsed / 1000; // update the time.delta
																  //if (game.time.ticksEllapsed > game.time.ticks) {// if the ticks ellapsed is superiore to the ticks for a frame it run the loop
		if (game->time.ticksEllapsed)
			game->time.fps = (double)(1000 / game->time.ticksEllapsed); // calculate fps
		iceInputReturn(&game, game->input);
		iceDrawClearColor(game->drawer.render, game->background);
		iceDrawClear(game->drawer.render);
		call_update(game); // Call Update
		iceDrawPresent(game->drawer.render);
		game->time.last = game->time.actual; // restart counter
										   //}
										   //else // else it wait until the nb of ticks is enough to fix fps to max fps
										   //SDL_Delay((Uint32)(game.time.ticks - (game.time.actual - game.time.last)));
	}
	call_destroy(game);
	iceInputReset(game->input);
	return 0;
}
