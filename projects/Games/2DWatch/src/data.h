#ifndef DEF_GAME_DATA
#define DEF_GAME_DATA

#include "weapon.h"

struct DATA1
{
	int					life, speed;
	//ICE_State			inventory;
	Game_Weapon			current_weapon;

}; typedef struct DATA1 DATA1;

#endif