#ifndef DEF_ICE_SPRITE
#define DEF_ICE_SPRITE

#define ICE_DEFAULT_SPRITE_MNGR_SIZE 4
#include "../Core/State.h"

/* SPRITEMANAGER */

void ICE_SpriteManager_Init();
void ICE_SpriteManager_Free();

/* SPRITE */

ICE_Sprite ICE_Sprite_Create(ICE_Id texture_, ICE_Vect size_frame_sprite_);
ICE_Id ICE_Sprite_Load(ICE_Id texture_, ICE_Vect size_frame_sprite_);
void ICE_Sprite_Clear(ICE_Id sprite_);
void ICE_Sprite_Destroy(ICE_Id sprite_);

ICE_Sprite * ICE_Sprite_Get(ICE_Id sprite_);

ICE_Uint64 ICE_Sprite_GetFrameQuantity(ICE_Id sprite_);

#endif