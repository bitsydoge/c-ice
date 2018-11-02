#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include <ICE.h>

typedef struct
{
	ICE_EntityID id;
	int speed;
	int dx, dy;

	int frame_up, frame_down,
		frame_left, frame_right;

	ICE_String name;

} GAME_DATA_PLAYER;

void GAME_Player_Init();

#endif