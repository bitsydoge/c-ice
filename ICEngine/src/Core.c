#include "hdr/Core.h"
#include "hdr/Core_private.h"
#include "hdr/Camera_private.h"
#include "hdr/Input_private.h"
#include "hdr/Draw_private.h"
#include "hdr/Physics_private.h"
#include "hdr/Time_private.h"

extern iceGame game;

int iceCoreLoop(void(*call_create)(void), void(*call_update)(void), void(*call_destroy)(void)) {
	iceCoreInit();
	call_create();
	while (!game.input->quit) 
	{
		// Time
		//////////////////////////////
		iceTimeStart();
	
		// Input
		//////////////////////////////
		iceInputReturn();
		
		// Camera
		//////////////////////////////
		iceCameraUpdateAttach();
		
		// Physics
		//////////////////////////////
		icePhysicsSpaceStep();
		icePhysicsUpdateEntity();
		
		
		//////////////////////////////
		//////////////////////////////
		//////////////////////////////

		call_update();

		//////////////////////////////
		//////////////////////////////
		//////////////////////////////

		// Graphic Rendering
		//////////////////////////////
		iceDrawClearColor(game.background);
		iceDrawClear();
		iceDrawAllEntity();
		iceDrawLabelWorld();
		iceDrawAllGui();
		iceDrawLabelScreen();
		iceDrawPresent();

		// Time
		//////////////////////////////
		iceTimeEnd();
	}
	call_destroy();
	iceCoreClose();
	return 0;
}