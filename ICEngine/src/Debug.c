#include "hdr/Debug.h"


void iceDebugMouseCoordinate(iceGame *game)
{
	char coo[20];
	iceRect coordinate = { game->input->mousex, game->input->mousey };
	if (game->input->leftclic)
		coordinate = iceCameraScreenWorld(coordinate, &game->camera);
	sprintf(coo, "%0.1f, %0.1f", coordinate.x, coordinate.y);
	
	iceVect vect = { game->input->mousex + 10, game->input->mousey + 10 };
	iceFontDraw(game, coo, 10, vect);
}

void iceDebugShowFps(iceGame *game)
{
	char gh[100];
	sprintf(gh, "%f", game->time.fps);
	iceFontDraw(game, gh, 20, iceVectNew(10, 5));
}

void iceDebugShowFpsTitle(iceGame *game)
{
	char buffer[25];
	sprintf(buffer, "FPS : [%0.1f]", game->time.fps);
	iceGameTitle(game, buffer);
}

void _iceAssert_(const char* expr_str, int expr, const char* file, int line, const char* msg)
{
	if (!expr)
	{
		iceTermSetColor(LIGHTRED);
		printf("\n\n\t\t-------------------[ERROR]-------------------\t\t\n\n");
		iceTermResetColor();
		printf("Assert Msg\t:\t");
		iceTermSetColor(LIGHTGREEN);
		printf("%s\n", msg);
		iceTermResetColor();
		printf("Expected\t:\t");
		iceTermSetColor(LIGHTMAGENTA);
		printf("%s\n", expr_str);
		iceTermResetColor();
		printf("Source File\t:\t"); 
		iceTermSetColor(YELLOW);
		printf("%s\n", file); 
		iceTermResetColor();
		printf("At the Line\t:\t"); 
		iceTermSetColor(LIGHTCYAN);
		printf("%d\n\n", line);
		iceTermSetColor(LIGHTRED);
		printf("\t\t-------------------[ERROR]-------------------\t\t\n");
		abort();
	}
}