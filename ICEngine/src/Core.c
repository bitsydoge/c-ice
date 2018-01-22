#include <SDL2/SDL.h>
#include "hdr/Core.h"
#include "hdr/Core_private.h"
#include "hdr/Camera_private.h"

extern iceGame game;

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
		iceDebugShowCollide();

		//////////////////////////

		iceDrawPresent();
		icePhysicsSpaceStep();
		icePhysicsUpdateEntity();
		game.time.last = game.time.actual; // restart counter
	//}
	//else // else it wait until the nb of ticks is enough to fix fps to max fps
		//SDL_Delay((Uint32)(game.time.ticks - (game.time.actual - game.time.last)));
	}
	call_destroy();
	iceCoreClose();
	return 0;
}