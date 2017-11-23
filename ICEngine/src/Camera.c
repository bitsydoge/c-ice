#include "hdr/Camera.h"

void ICE_CameraSetPos(ICE_Game *game, iceVect vect){
	game->camera.x = vect.x; game->camera.y = vect.y;
}

void ICE_CameraMovePos(ICE_Game *game, iceVect vect, iceFloat r){
	float xdif = vect.x - game->camera.x; 
	float ydif = vect.y - game->camera.y;

	float angle = atan2(ydif, xdif);
	float distance_r_r = xdif*xdif + ydif*ydif;

	game->camera.x += r * cos(angle) * game->time.delta; 
	game->camera.y += r * sin(angle) * game->time.delta;

	if (distance_r_r < r*game->time.delta){
		game->camera.x = vect.x;
		game->camera.y = vect.y;
	}
}

void ICE_CameraShiftPos(ICE_Game *game, iceVect Dvect){
	game->camera.x += Dvect.x; game->camera.y += Dvect.y;
}

// Converter
iceRect ICE_CameraWorldScreen(iceRect rect, ICE_Camera *camera){
	iceRect rect2 = {
		(camera->w / 2) + rect.x - camera->x,
		(camera->h / 2) + rect.y - camera->y,
		rect.w,
		rect.h
	};
	return rect2;
}

iceRect ICE_CameraScreenWorld(iceRect rect, ICE_Camera *camera){
	iceRect rect2 = {
		-camera->w / 2 + camera->x + rect.x,
		-camera->h / 2 + camera->y + rect.y,
		rect.w,
		rect.h
	};
	return rect2;
}