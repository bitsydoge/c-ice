#include "hdr/Debug.h"

void ICE_DebugMouseCoordinate(ICE_Game *game)
{
	char coo[20];
	ICE_Rect coordinate = { game->input->mousex, game->input->mousey };
	if (game->input->leftclic)
		coordinate = screen_to_position(coordinate, &game->camera);
	sprintf(coo, "%d, %d", coordinate.x, coordinate.y);
	
	ICE_Rect rect = { game->input->mousex + 10, game->input->mousey + 10 };
	ICE_FontDraw(game, coo, 10, rect);
}
