#include "hdr/menu.h"


void menu_create(ICE_Game* game)
{
	
}

void menu_update(ICE_Game* game)
{
	ICE_RenderClear(game->render);
	if (game->input->key[SDL_SCANCODE_ESCAPE])
		game->input->substate_quit = 1;
}

void menu_destroy(ICE_Game* game)
{
	
}