#ifndef DEF_ICE_SPRITE
#define DEF_ICE_SPRITE

#define ICE_DEFAULT_SPRITE_MNGR_SIZE 4
#include "../Core/State.h"

/* SPRITEMANAGER */

size_t ICE_SpriteManager_Insert(ICE_State* state);
void ICE_SpriteManager_Destroy(ICE_State * state, const size_t man);
void ICE_SpriteManager_DestroyAll(ICE_State * state);

/* SPRITE */

ICE_Sprite ICE_Sprite_Create(size_t man_texture, size_t nb_texture);
size_t ICE_Sprite_Insert(ICE_State* state, const size_t man, const ICE_Box box, size_t texture_manager,
                         size_t texture_nb);
void ICE_Sprite_Clear(ICE_Sprite * label);
void ICE_Sprite_Destroy(ICE_Sprite * ptr);

#endif