#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#define ICE_DEFAULT_TEXTURE_SIZE 4

#include "TypesGraphics.h"
#include "../Maths/TypesMaths.h"

unsigned int ICE_TextureManager_Insert();
void ICE_TextureManager_Destroy(const unsigned int man);
void ICE_TextureManager_DestroyAll();
unsigned int ICE_Texture_Insert(int manager, char* path);
void ICE_Texture_Destroy(ICE_Texture *tex);
ICE_Texture * ICE_Texture_Get(unsigned int man, unsigned int nb);

#endif