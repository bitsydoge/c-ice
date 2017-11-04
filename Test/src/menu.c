#include "hdr/menu.h"
#include "hdr/data.h"


void menu_create(ICE_Game* game)
{
	
}

void menu_update(ICE_Game* game)
{
	DATA1 *data1 = ICE_GetData(game, 0);

	ICE_GuiRect(game, 0, 1, NewRect(50, 50, game->camera.w - 100, game->camera.h - 100));
	
	if (game->input->key[SDL_SCANCODE_ESCAPE])
		game->input->substate_quit = 1;
}

void menu_destroy(ICE_Game* game)
{
	
}