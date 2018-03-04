﻿#include "hdr/Camera.h"
#include "hdr/TypesCore.h"
#include "hdr/Vector.h"

extern ICE_Game game;

// Camera edit
// ----------------------------------------------------

void ICE_CameraSetPos(ICE_Vect vect) {
	game.camera.x = vect.x; game.camera.y = vect.y;
}

void ICE_CameraMovePos(ICE_Vect vect, ICE_Float r) {
	float xdif = vect.x - game.camera.x;
	float ydif = vect.y - game.camera.y;

	float angle = atan2(ydif, xdif);
	float distance_r_r = xdif * xdif + ydif * ydif;

	game.camera.x += r * cos(angle);
	game.camera.y += r * sin(angle);

	if (distance_r_r < r) {
		game.camera.x = vect.x;
		game.camera.y = vect.y;
	}
}

void ICE_CameraShiftPos(ICE_Vect Dvect) {
	game.camera.x += Dvect.x; game.camera.y += Dvect.y;
}

// Camera return
// ----------------------------------------------------


int ICE_CameraGetW()
{
	return game.camera.w;
}

int ICE_CameraGetH()
{
	return game.camera.h;
}

// Converter
// ----------------------------------

ICE_Box ICE_CameraWorldScreen(ICE_Box rect) {
	ICE_Box rect2 = {
		(game.camera.w / 2) + rect.x - game.camera.x,
		(game.camera.h / 2) + rect.y - game.camera.y,
		rect.w,
		rect.h
	};
	return rect2;
}

ICE_Box ICE_CameraScreenWorld(ICE_Box rect) {
	ICE_Box rect2 = {
		-game.camera.w / 2 + game.camera.x + rect.x,
		-game.camera.h / 2 + game.camera.y + rect.y,
		rect.w,
		rect.h
	};
	return rect2;
}
