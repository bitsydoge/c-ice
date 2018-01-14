#include "hdr/Camera.h"

extern iceGame game;

void iceCameraSetPos(iceVect vect){
	game.camera.x = vect.x; game.camera.y = vect.y;
}

void iceCameraMovePos(iceVect vect, iceFloat r){
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

void iceCameraShiftPos(iceVect Dvect){
	game.camera.x += Dvect.x; game.camera.y += Dvect.y;
}

// Converter
iceBox iceCameraWorldScreen(iceBox rect){
	iceBox rect2 = {
		(game.camera.w / 2) + rect.p.x - game.camera.x,
		(game.camera.h / 2) + rect.p.y - game.camera.y,
		rect.w,
		rect.h
	};
	return rect2;
}

iceBox iceCameraScreenWorld(iceBox rect){
	iceBox rect2 = {
		-game.camera.w / 2 + game.camera.x + rect.p.x,
		-game.camera.h / 2 + game.camera.y + rect.p.y,
		rect.w,
		rect.h
	};
	return rect2;
}

void iceCameraAttachToEntity(int entity_manager, int entity)
{
	game.camera.isAttachedToEntity = iceTrue;
	game.camera.entity_attached = entity;
	game.camera.entity_manager_attached = entity_manager;
}

void iceCameraDetach()
{
	game.camera.isAttachedToEntity = iceFalse;
}

void iceCameraUpdateAttach()
{
	if(game.camera.isAttachedToEntity)
	{
		iceCameraSetPos(iceVectNew(game.entitymanager[game.camera.entity_manager_attached].entity[game.camera.entity_attached].x, game.entitymanager[game.camera.entity_manager_attached].entity[game.camera.entity_attached].y));
	}
}

iceBool iceCameraBoxOnScreen(iceBox box)
{
	//to implement
	//iceBox new = { game->camera.x - game->camera.w/2, game->camera.y - game->camera.h / 2, game->camera.w, game->camera.h };
	return 1;
}

int iceCameraGetW()
{
	return game.camera.w;
}

int iceCameraGetH()
{
	return game.camera.h;
}