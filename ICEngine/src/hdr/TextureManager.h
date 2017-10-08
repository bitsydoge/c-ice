#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Texture.h"

struct ICE_TextureManager
{
    unsigned short array_size;
    unsigned short nb_existing_texture;
    ICE_Texture* texturepack;
};

// Create the texture manager with a default number of texture, everytime the number of texture is too high, it will double
void ICE_CreateTextureManager(ICE_Game *game);
void ICE_CreateTexture(ICE_Game *game, ICE_TextureManager *texturemanager, char* path, Uint32 color_hex);

#endif 
