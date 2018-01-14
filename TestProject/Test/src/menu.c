#include "hdr/menu.h"
#include "hdr/data.h"


void menu_create(){
	DATA1 *data = iceDataGet(1);
	data->menu_escape = iceBoxNew(50, 50, iceCameraGetW() - 100, iceCameraGetH() - 100);
	iceSoundPlay(0, 2);
}

void menu_update(){
	DATA1 *data = iceDataGet(1);

	iceGuiRect(0, 1, data->menu_escape);

	// Quit the substate
	if (iceInputButton(SDL_SCANCODE_ESCAPE)) iceSubstateQuit();
}

void menu_destroy(iceGame* game){

}