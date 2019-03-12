#pragma once
#include <ICE.h>

///////////// SKULL ENTITY ////////////////

struct GG_Skull_Data
{
	ICE_Float timer;
	ICE_Float speed_rotation;
	ICE_Bool direction_rotation;
};

void GG_Skull_Create(ICE_Entity* this_);
void GG_Skull_Update(ICE_Entity* this_);