#ifndef DEF_ICE_SPRITE
#define DEF_ICE_SPRITE

#define ICE_DEFAULT_SPRITE_MNGR_SIZE 4
#include "../Core/State.h"

/* SPRITEMANAGER */

ICE_Id ICE_SpriteManager_Insert();
void ICE_SpriteManager_Destroy(const ICE_Id man);
void ICE_SpriteManager_DestroyAll();

/* SPRITE */

ICE_Sprite ICE_Sprite_Create(ICE_Texture * texture, ICE_Vect size_frame_sprite);
ICE_Id ICE_Sprite_Insert(const ICE_Id man, ICE_Texture * texture, ICE_Vect size_frame_sprite);
void ICE_Sprite_Clear(ICE_Sprite * label);
void ICE_Sprite_Destroy(ICE_Sprite * ptr);
ICE_Sprite * ICE_Sprite_Get(ICE_Id man, ICE_Id nb);
ICE_Uint64 ICE_Sprite_GetFrameQuantity(ICE_Sprite * _sprite);

#endif