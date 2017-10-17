#ifndef DEF_ICE_TEXTUREMANAGER
#define DEF_ICE_TEXTUREMANAGER

#include "Texture.h"
#include "Struct.h"

// Create the texture manager with a default number of texture, everytime the number of texture is too high, it will double
void ICE_CreateTextureManager(ICE_Game *game);
void ICE_CreateTexture(ICE_Game *game, ICE_TextureManager *texturemanager, char* path, Uint32 color_hex);

#endif 
