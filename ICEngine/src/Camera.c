#include "hdr/Camera.h"

void ICE_SetCamera(ICE_Game *game, int x, int y){
	game->camera.x = x; game->camera.y = y;
}

void ICE_MoveCamera(ICE_Game *game, int dx, int dy){
	game->camera.x += dx * game->time.delta; game->camera.y += dy * game->time.delta;
}

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