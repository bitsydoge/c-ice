#include "Camera.h"
#include "../Core/TypesCore.h"
#include "../Maths/Vector.h"


extern ICE_Game game;
extern ICE_Core core;

// Camera edit
// ----------------------------------------------------

void ICE_Camera_SetPos(ICE_Vect vect)
{
	
	game.current->object.camera.x = vect.x;
	game.current->object.camera.y = vect.y;
}

void ICE_Camera_MovePos(ICE_Vect vect, ICE_Float r)
{
	const ICE_Float xdif = vect.x - game.current->object.camera.x;
	const ICE_Float ydif = vect.y - game.current->object.camera.y;

	const ICE_Float angle = atan2(ydif, xdif);
	const ICE_Float distance_r_r = xdif * xdif + ydif * ydif;

	game.current->object.camera.x += r * cos(angle);
	game.current->object.camera.y += r * sin(angle);

	if (distance_r_r < r)
	{
		game.current->object.camera.x = vect.x;
		game.current->object.camera.y = vect.y;
	}
}

void ICE_Camera_ShiftPos(ICE_Vect Dvect)
{
	game.current->object.camera.x += Dvect.x;
	game.current->object.camera.y += Dvect.y;
}

// Camera return
// ----------------------------------------------------

ICE_Vect ICE_Camera_GetPos()
{
	return ICE_Vect_New(core.window.w, core.window.h);
}

// Converter
// ----------------------------------

ICE_Box ICE_Camera_WorldScreen(ICE_Box rect)
{
	ICE_Box rect2 = {
		(core.window.w / 2) + rect.x - game.current->object.camera.x,
		(core.window.h / 2) + rect.y - game.current->object.camera.y,
		rect.w,
		rect.h
	};
	return rect2;
}

ICE_Box ICE_Camera_ScreenWorld(ICE_Box rect)
{
	ICE_Box rect2 = {
		-core.window.w / 2 + game.current->object.camera.x + rect.x,
		-core.window.h / 2 + game.current->object.camera.y + rect.y,
		rect.w,
		rect.h
	};
	return rect2;
}
