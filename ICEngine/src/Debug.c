#include "hdr/Debug.h"


void ICE_DebugMouseCoordinate(ICE_Game *game)
{
	char coo[20];
	iceRect coordinate = { game->input->mousex, game->input->mousey };
	if (game->input->leftclic)
		coordinate = ICE_CameraScreenWorld(coordinate, &game->camera);
	sprintf(coo, "%0.1f, %0.1f", coordinate.x, coordinate.y);
	
	iceVect vect = { game->input->mousex + 10, game->input->mousey + 10 };
	ICE_FontDraw(game, coo, 10, vect);
}

void ICE_DebugShowFps(ICE_Game *game)
{
	char gh[100];
	sprintf(gh, "%f", game->time.fps);
	ICE_FontDraw(game, gh, 20, iceVectNew(10, 5));
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
		ICE_TermSetColor(LIGHTRED);
		printf("\n\n\t\t-------------------[ERROR]-------------------\t\t\n\n");
		ICE_TermResetColor();
		printf("Assert Msg\t:\t");
		ICE_TermSetColor(LIGHTGREEN);
		printf("%s\n", msg);
		ICE_TermResetColor();
		printf("Expected\t:\t");
		ICE_TermSetColor(LIGHTMAGENTA);
		printf("%s\n", expr_str);
		ICE_TermResetColor();
		printf("Source File\t:\t"); 
		ICE_TermSetColor(YELLOW);
		printf("%s\n", file); 
		ICE_TermResetColor();
		printf("At the Line\t:\t"); 
		ICE_TermSetColor(LIGHTCYAN);
		printf("%d\n\n", line);
		ICE_TermSetColor(LIGHTRED);
		printf("\t\t-------------------[ERROR]-------------------\t\t\n");
		abort();
	}
}