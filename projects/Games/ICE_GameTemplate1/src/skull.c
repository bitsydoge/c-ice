#include "skull.h"

void GG_Skull_Create(ICE_Entity* this_)
{
	struct GG_Skull_Data* D = ICE_Entity_DataAdd(this_, struct GG_Skull_Data);
	D->timer = 3.0f;
	ICE_Entity_SetAngle(this_, ICE_Random_Int(0, 360));
	D->speed_rotation = ICE_Random_Int(5, 15);
	D->direction_rotation = ICE_Random_Int(0, 1);
}

void GG_Skull_Update(ICE_Entity* this_)
{
	struct GG_Skull_Data* D = ICE_Entity_DataGet(this_, 0);
	D->timer -= ICE_Game_GetDelta();
	ICE_Entity_AddAngle(this_, D->direction_rotation ? ICE_Game_GetDelta() * D->speed_rotation : -(ICE_Game_GetDelta() * D->speed_rotation));
	if (D->timer <= 0.0f)
		ICE_Entity_Destroy(this_);
}