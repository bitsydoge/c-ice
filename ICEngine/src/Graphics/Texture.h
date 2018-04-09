#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#define ICE_DEFAULT_TEXTURE_SIZE 4

#include "TypesGraphics.h"

size_t ICE_TextureManager_Insert();
void ICE_TextureManager_Destroy(const size_t man);
void ICE_TextureManager_DestroyAll();
size_t ICE_Texture_Insert(int manager, char* path);
void ICE_Texture_Destroy(ICE_Texture *tex);
ICE_Texture * ICE_Texture_Get(size_t man, size_t nb);

#endif