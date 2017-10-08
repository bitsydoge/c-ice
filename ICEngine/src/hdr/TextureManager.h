#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Texture.h"
#include "Game.h"
#include "Type.h"

struct ICE_TextureManager
{
    unsigned short array_size;
    unsigned short nb_existing_texture;
    ICE_Texture* texturepack;

};

// Create the texture manager with a default number of texture, everytime the number of texture is too high, it will double
ICE_TextureManager ICE_CreateTextureManager();
void ICE_CreateTexture(ICE_Game *app, ICE_TextureManager *texturemanager, char* path, Uint32 color_hex);

#endif // TEXTUREMANAGER_H
