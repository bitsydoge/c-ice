#include "hdr/Debug.h"

#include "hdr/Camera.h"
#include "hdr/Vector.h"
#include "hdr/Font.h"
#include "hdr/Window.h"
#include <stdio.h>
#include "hdr/Terminal.h"
#include "hdr/Primitive.h"
#include "hdr/Box.h"
#include "hdr/Physics.h"
#include "hdr/Color.h"

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

void iceDebugShowCollide()
{
	for (int i = 0; i < game.entitymanager_nb; i++)
		for (int j = 0; j < game.entitymanager[i].nb_existing; j++)
		{
			if (game.entitymanager[i].entity[j].exist)
			{
				if (game.entitymanager[i].entity[j].physics.body_types == ICE_PHYSICS_RIGID_BODY)
				{
					iceVect vect = cpVect_to_iceVect(cpBodyGetPosition(game.entitymanager[i].entity[j].physics.body));
					iceFloat radius = game.entitymanager[i].entity[j].physics.radius;
					iceBox box = iceCameraWorldScreen(
						iceBoxNew(
							vect.x-(radius), vect.y - (radius),
							radius*2, radius*2
						)
					);
					
					iceDrawPoint(iceVectNew(vect.x, vect.y), iceColorNew(0,0,255));
					iceDrawRectangle(box, iceColorNew(0,0,255));
				}
			}
		}
}