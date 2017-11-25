#include "hdr/menu.h"
#include "hdr/data.h"


void menu_create(iceGame* game){
	DATA1 *data = iceDataGet(game, 1);
	data->menu_escape = iceBoxNew(50, 50, game->camera.w - 100, game->camera.h - 100);
	iceSoundPlay(game, 0, 2);
}

void menu_update(iceGame* game){
	DATA1 *data = iceDataGet(game, 1);

	iceGuiRect(game, 0, 1, data->menu_escape);

	// Quit the substate
	if(game->input->key[SDL_SCANCODE_ESCAPE]) game->input->substate_quit = 1; 
}

void menu_destroy(iceGame* game){

}