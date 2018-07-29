#ifndef DEF_ICE_SPRITE
#define DEF_ICE_SPRITE

#define ICE_DEFAULT_SPRITE_MNGR_SIZE 4
#include "../Core/State.h"

/* SPRITEMANAGER */

ICE_Index ICE_SpriteManager_Insert(ICE_State* state);
void ICE_SpriteManager_Destroy(ICE_State * state, const ICE_Index man);
void ICE_SpriteManager_DestroyAll(ICE_State * state);

/* SPRITE */

ICE_Sprite ICE_Sprite_Create(ICE_Index man_texture, ICE_Index nb_texture, unsigned int number_sprite_w, unsigned int number_sprite_h);
ICE_Index ICE_Sprite_Insert(ICE_State* state, const ICE_Index man, ICE_Index texture_manager,
                         ICE_Index texture_nb, unsigned int number_sprite_w, unsigned int number_sprite_h);
void ICE_Sprite_Clear(ICE_Sprite * label);
void ICE_Sprite_Destroy(ICE_Sprite * ptr);

#endif