#include "weapon.h"

Game_Weapon Game_Weapon_Init(wchar_t* name, ICE_Float damage, ICE_Float speed, ICE_Float weight)
{
	Game_Weapon weapon = {
		ICE_WString_Init(name),
		damage,
		speed,
		weight };

	return weapon;
}

void Game_Weapon_Destroy(Game_Weapon *weapon)
{
	ICE_WString_Delete(weapon->name);
}