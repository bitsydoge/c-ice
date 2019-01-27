#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include <ICE.h>

typedef struct
{
	ICE_EntityID id;
	ICE_Float speed;
	int dx, dy;

	ICE_ID frame_up, frame_down,
		frame_left, frame_right;

	int size_text;
	ICE_String name;

} GAME_DATA_PLAYER;

void GAME_Player_Init();

#endif