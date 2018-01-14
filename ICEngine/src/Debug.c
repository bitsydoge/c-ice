﻿#include "hdr/Debug.h"

extern iceGame game;

void iceDebugMouseCoordinate()
{
	char coo[20];
	iceBox coordinate = { game.input->mousex, game.input->mousey };
	if (game.input->leftclic)
		coordinate = iceCameraScreenWorld(coordinate);
	sprintf(coo, "%0.1f, %0.1f", coordinate.p.x, coordinate.p.y);
	
	iceVect vect = { game.input->mousex + 10, game.input->mousey + 10 };
	iceFontDraw(coo, 10, vect);
}

void iceDebugShowFps()
{
	char gh[100];
	sprintf(gh, "%f", game.time.fps);

	iceFontDraw(gh, 20, iceVectNew(10, 5));
}

void iceDebugShowFpsTitle()
{
	char buffer[25];
	sprintf(buffer, "FPS : [%0.1f]", game.time.fps);
	iceWindowTitle(buffer);
}

void iceAssert_(const char* expr_str, int expr, const char* file, int line, const char* msg)
{
	if (!expr)
	{
		iceTermSetColor(iceLIGHTRED);
		printf("\n\n\t\t-------------------[ERROR]-------------------\t\t\n\n");
		iceTermResetColor();
		printf("Assert Msg\t:\t");
		iceTermSetColor(iceLIGHTGREEN);
		printf("%s\n", msg);
		iceTermResetColor();
		printf("Expected\t:\t");
		iceTermSetColor(iceLIGHTMAGENTA);
		printf("%s\n", expr_str);
		iceTermResetColor();
		printf("Source File\t:\t"); 
		iceTermSetColor(iceYELLOW);
		printf("%s\n", file); 
		iceTermResetColor();
		printf("At the Line\t:\t"); 
		iceTermSetColor(iceLIGHTCYAN);
		printf("%d\n\n", line);
		iceTermSetColor(iceLIGHTRED);
		printf("\t\t-------------------[ERROR]-------------------\t\t\n");
		abort();
	}
}