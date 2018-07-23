﻿#ifndef DEF_GAME_WEAPON
#define DEF_GAME_WEAPON

#include <ICE.h>

struct Game_Weapon
{

	ICE_WString			name;
	ICE_Float			damage;
	ICE_Float			speed;
	ICE_Float			weight;

}; typedef struct Game_Weapon Game_Weapon;


Game_Weapon Game_Weapon_Init(wchar_t* name, ICE_Float damage, ICE_Float speed, ICE_Float weight);
void Game_Weapon_Destroy(Game_Weapon *weapon);

#endif