#include "hdr/menu.h"
#include "hdr/data.h"


void menu_create(ICE_Game* game){
	DATA1 *data = ICE_GetData(game, 1);
	data->menu_escape = RectNew(50, 50, game->camera.w - 100, game->camera.h - 100);
	ICE_SoundPlay(game, 0, 2);
}

void menu_update(ICE_Game* game){
	DATA1 *data = ICE_GetData(game, 1);

	ICE_GuiRect(game, 0, 1, data->menu_escape);

	// Quit the substate
	if(game->input->key[SDL_SCANCODE_ESCAPE]) game->input->substate_quit = 1; 
}

void menu_destroy(ICE_Game* game){

}