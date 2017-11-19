#include "hdr/Camera.h"

void ICE_CameraSetPos(ICE_Game *game, const float x, const float y){
	game->camera.x = x; game->camera.y = y;
}

void ICE_CameraMovePos(ICE_Game *game, const float x, const float y, const float r){
	float xdif = x - game->camera.x; float ydif = y - game->camera.y;
	float angle = atan2(ydif, xdif);
	float distance_r_r = xdif*xdif + ydif*ydif;
	game->camera.x += r * cos(angle) * game->time.delta; game->camera.y += r * sin(angle) * game->time.delta;
	if (distance_r_r < r*game->time.delta)
	{
		game->camera.x = x;
		game->camera.y = y;
	}
}

void ICE_CameraShiftPos(ICE_Game *game, const float dx, const float dy){
	game->camera.x += dx * game->time.delta; game->camera.y += dy * game->time.delta;
}

// Converter
ICE_Rect position_to_screen(ICE_Rect rect, ICE_Camera *camera){
	ICE_Rect rect2 = {
		(camera->w / 2) + rect.x - camera->x,
		(camera->h / 2) + rect.y - camera->y,
		rect.w,
		rect.h
	};
	return rect2;
}

ICE_Rect screen_to_position(ICE_Rect rect, ICE_Camera *camera){
	ICE_Rect rect2 = {
		-camera->w / 2 + camera->x + rect.x,
		-camera->h / 2 + camera->y + rect.y,
		rect.w,
		rect.h
	};
	return rect2;
}