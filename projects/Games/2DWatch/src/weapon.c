#include "weapon.h"

Game_Weapon Game_Weapon_Init(ICE_String name, ICE_Float damage, ICE_Float speed, ICE_Float weight)
{
	Game_Weapon weapon = {
		ICE_String_Init(name),
		damage,
		speed,
		weight };

	return weapon;
}

void Game_Weapon_Destroy(Game_Weapon *weapon)
{
	ICE_String_Free(weapon->name);
}