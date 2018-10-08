#ifndef DEF_ICE_SPRITE
#define DEF_ICE_SPRITE

#define ICE_DEFAULT_SPRITE_MNGR_SIZE 4
#include "../Core/State.h"

/* SPRITEMANAGER */

ICE_Index ICE_SpriteManager_Insert();
void ICE_SpriteManager_Destroy(const ICE_Index man);
void ICE_SpriteManager_DestroyAll();

/* SPRITE */

ICE_Sprite ICE_Sprite_Create(ICE_Texture * texture, ICE_Vect size_frame_sprite);
ICE_Index ICE_Sprite_Insert(const ICE_Index man, ICE_Texture * texture, ICE_Vect size_frame_sprite);
void ICE_Sprite_Clear(ICE_Sprite * label);
void ICE_Sprite_Destroy(ICE_Sprite * ptr);
ICE_Sprite * ICE_Sprite_Get(ICE_Index man, ICE_Index nb);

#endif