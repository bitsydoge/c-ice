#ifndef DEF_GAME_WEAPON
#define DEF_GAME_WEAPON

#include "Framework/String_.h"

struct Game_Weapon
{

	ICE_String			name;
	ICE_Float			damage;
	ICE_Float			speed;
	ICE_Float			weight;

}; typedef struct Game_Weapon Game_Weapon;


Game_Weapon Game_Weapon_Init(ICE_String name, ICE_Float damage, ICE_Float speed, ICE_Float weight);
void Game_Weapon_Destroy(Game_Weapon *weapon);

#endif