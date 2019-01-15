#ifndef DEF_ICE_SPRITE
#define DEF_ICE_SPRITE

#include "TypesGraphics.h"

#define ICE_DEFAULT_SPRITEMNGR_SIZE 4

void ICE_SpriteManager_Init();
void ICE_SpriteManager_Destroy();

ICE_Sprite ICE_Sprite_Build(ICE_TextureID texture_, ICE_Vect size_frame_sprite_);
ICE_ID ICE_Sprite_Load(ICE_TextureID texture_, ICE_Vect size_frame_sprite_);
void ICE_Sprite_Clear(ICE_SpriteID sprite_);
void ICE_Sprite_Destroy(ICE_SpriteID sprite_);
ICE_Sprite * ICE_Sprite_Get(ICE_SpriteID sprite_);
ICE_Uint64 ICE_Sprite_GetFrameQuantity(ICE_SpriteID sprite_);

#endif