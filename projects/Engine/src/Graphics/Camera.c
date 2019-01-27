#include "Camera.h"
#include "../Core/TypesCore.h"
#include "../Maths/Vector.h"


extern ICE_Game GAME;
extern ICE_Core CORE;

// Camera edit
// ----------------------------------------------------

void ICE_Camera_SetPos(ICE_Vect vect)
{
	
	GAME.current->object.camera.x = vect.x;
	GAME.current->object.camera.y = vect.y;
}

void ICE_Camera_MovePos(ICE_Vect vect, ICE_Float r)
{
	const ICE_Float xdif = vect.x - GAME.current->object.camera.x;
	const ICE_Float ydif = vect.y - GAME.current->object.camera.y;

	const ICE_Float angle = atan2(ydif, xdif);
	const ICE_Float distance_r_r = xdif * xdif + ydif * ydif;

	GAME.current->object.camera.x += r * cos(angle);
	GAME.current->object.camera.y += r * sin(angle);

	if (distance_r_r < r)
	{
		GAME.current->object.camera.x = vect.x;
		GAME.current->object.camera.y = vect.y;
	}
}

void ICE_Camera_ShiftPos(ICE_Vect delta_)
{
	GAME.current->object.camera.x += delta_.x;
	GAME.current->object.camera.y += delta_.y;
}

// Camera return
// ----------------------------------------------------

ICE_Vect ICE_Camera_GetPos(ICE_State* state_)
{
	if (state_ == NULL)
		state_ = GAME.current;

	return ICE_Vect_New(state_->object.camera.x, state_->object.camera.y);
}

// Converter
// ----------------------------------

ICE_Box ICE_Camera_WorldScreen(ICE_Box rect)
{
	ICE_Box rect2 = {
		(CORE.window.w / 2) + rect.x - GAME.current->object.camera.x,
		(CORE.window.h / 2) + rect.y - GAME.current->object.camera.y,
		rect.w,
		rect.h
	};
	return rect2;
}

ICE_Box ICE_Camera_ScreenWorld(ICE_Box rect)
{
	ICE_Box rect2 = {
		-CORE.window.w / 2 + GAME.current->object.camera.x + rect.x,
		-CORE.window.h / 2 + GAME.current->object.camera.y + rect.y,
		rect.w,
		rect.h
	};
	return rect2;
}
