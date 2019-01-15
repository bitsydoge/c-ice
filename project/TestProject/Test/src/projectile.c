#include <ICE.h>

#include "projectile.h"
#include "game.h"
#include "player.h"

void GAME_Projectile_Create(ICE_Entity * this_)
{
	GAME_DATA * D = ICE_Data_Get(NULL, 0);
	GAME_DATA_PROJECTILE * D_entity = ICE_Entity_DataAdd(this_, GAME_DATA_PROJECTILE);
	ICE_Entity * player = ICE_Entity_Get(NULL, D->player);
	GAME_DATA_PLAYER * D_player = ICE_Entity_DataGet(player, 0);

	ICE_Entity_SetSprite(this_, D->sprite_player);
	ICE_Entity_SetSpriteFrame(this_, 39);
	ICE_Sound_Play(D->explosion, 0.105);
	D_entity->speed = 600;
	D_entity->speedDiag = sqrt((D_entity->speed*D_entity->speed) / 2);
	D_entity->dx = D_player->dx;
	D_entity->dy = D_player->dy;
	D_entity->timer = 1.500;
}

void GAME_Projectile_Update(ICE_Entity * this_)
{
	GAME_DATA_PROJECTILE * D_entity = ICE_Entity_DataGet(this_, 0);

	if(D_entity->dx != 0 && D_entity->dy != 0)
		ICE_Entity_ShiftPos(
			this_,
			D_entity->dx * D_entity->speedDiag * ICE_Game_GetDelta(),
			D_entity->dy * D_entity->speedDiag * ICE_Game_GetDelta()
		);
	else
		ICE_Entity_ShiftPos(
			this_,
			D_entity->dx * D_entity->speed * ICE_Game_GetDelta(),
			D_entity->dy * D_entity->speed * ICE_Game_GetDelta()
		);

	D_entity->timer -= ICE_Game_GetDelta();

	if (D_entity->timer < 0)
		ICE_Entity_Destroy(this_);
}

void GAME_Projectile_Destroy(ICE_Entity * this_)
{
	ICE_Log(ICE_LOG_SUCCES, "Destroy Entity %d (Projectile)", ICE_Entity_GetID(this_), ICE_State_CurrentName());
}