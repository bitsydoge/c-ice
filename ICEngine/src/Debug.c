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

void ICE_DebugShowFps(ICE_Game *game)
{
	char gh[100];
	sprintf(gh, "%f", game->time.fps);
	ICE_FontDraw(game, gh, 20, RectNew(10, 5, 0, 0));
}

void ICE_DebugShowFpsTitle(ICE_Game *game)
{
	char buffer[25];
	sprintf(buffer, "FPS : [%0.1f]", game->time.fps);
	ICE_GameTitle(game, buffer);
}

void _ICE_Assert_(const char* expr_str, int expr, const char* file, int line, const char* msg)
{
	if (!expr)
	{
		ICE_TC_SetColor(LIGHTRED);
		printf("\n\n\t\t-------------------[ERROR]-------------------\t\t\n\n");
		ICE_TC_ResetColor();
		printf("Assert Msg\t:\t");
		ICE_TC_SetColor(LIGHTGREEN);
		printf("%s\n", msg);
		ICE_TC_ResetColor();
		printf("Expected\t:\t");
		ICE_TC_SetColor(LIGHTMAGENTA);
		printf("%s\n", expr_str);
		ICE_TC_ResetColor();
		printf("Source File\t:\t"); 
		ICE_TC_SetColor(YELLOW);
		printf("%s\n", file); 
		ICE_TC_ResetColor();
		printf("At the Line\t:\t"); 
		ICE_TC_SetColor(LIGHTCYAN);
		printf("%d\n\n", line);
		ICE_TC_SetColor(LIGHTRED);
		printf("\t\t-------------------[ERROR]-------------------\t\t\n");
		abort();
	}
}