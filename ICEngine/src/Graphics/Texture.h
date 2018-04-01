#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#define ICE_DEFAULT_TEXTURE_SIZE 4

#include "TypesGraphics.h"

unsigned int ICE_TextureManager_Create();
unsigned int ICE_Texture_Create(int manager, char* path);
ICE_Texture * ICE_Texture_Get(unsigned int man, unsigned int nb);

#endif