#include "hdr/Camera.h"

void iceCameraSetPos(iceGame *game, iceVect vect){
	game->camera.x = vect.x; game->camera.y = vect.y;
}

void iceCameraMovePos(iceGame *game, iceVect vect, iceFloat r){
	float xdif = vect.x - game->camera.x; 
	float ydif = vect.y - game->camera.y;

	float angle = atan2(ydif, xdif);
	float distance_r_r = xdif*xdif + ydif*ydif;

	game->camera.x += r * cos(angle); 
	game->camera.y += r * sin(angle);

	if (distance_r_r < r){
		game->camera.x = vect.x;
		game->camera.y = vect.y;
	}
}

void iceCameraShiftPos(iceGame *game, iceVect Dvect){
	game->camera.x += Dvect.x; game->camera.y += Dvect.y;
}

// Converter
iceBox iceCameraWorldScreen(iceBox rect, iceCamera *camera){
	iceBox rect2 = {
		(camera->w / 2) + rect.p.x - camera->x,
		(camera->h / 2) + rect.p.y - camera->y,
		rect.w,
		rect.h
	};
	return rect2;
}

iceBox iceCameraScreenWorld(iceBox rect, iceCamera *camera){
	iceBox rect2 = {
		-camera->w / 2 + camera->x + rect.p.x,
		-camera->h / 2 + camera->y + rect.p.y,
		rect.w,
		rect.h
	};
	return rect2;
}