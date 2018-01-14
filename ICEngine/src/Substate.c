#include "hdr/Substate.h"

extern iceGame game;

// Create a substate with the iceGame but with new Create/Update/Destroy function. This must be called only for specifique thing

int iceSubstateLoop(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void)) {
	iceInputReset();
	call_create();
	game.input->substate_quit = 0;
	while (!game.input->quit && !game.input->substate_quit) {
		game.time.actual = SDL_GetTicks(); // ticks since start of software at the start of loop
		game.time.ticksEllapsed = game.time.actual - game.time.last; // calculate nb of ticks ellapsed
		game.time.delta = (double)game.time.ticksEllapsed / 1000; // update the time.delta
																  //if (game.time.ticksEllapsed > game.time.ticks) {// if the ticks ellapsed is superiore to the ticks for a frame it run the loop
		if (game.time.ticksEllapsed)
			game.time.fps = (double)(1000 / game.time.ticksEllapsed); // calculate fps
		iceInputReturn();
		iceDrawClearColor(game.background);
		iceDrawClear();
		call_update(); // Call Update
		iceDrawPresent();
		game.time.last = game.time.actual; // restart counter
										   //}
										   //else // else it wait until the nb of ticks is enough to fix fps to max fps
										   //SDL_Delay((Uint32)(game.time.ticks - (game.time.actual - game.time.last)));
	}
	call_destroy();
	iceInputReset();
	return 0;
}

void iceSubstateQuit()
{
	game.input->substate_quit = iceTrue;
}
