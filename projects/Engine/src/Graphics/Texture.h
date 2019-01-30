#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#include "TypesGraphics.h"

#define ICE_DEFAULT_TEXTUREMNGR_SIZE 4

void ICE_TextureManager_Init();
void ICE_TextureManager_Destroy();

ICE_Texture ICE_Texture_Build(char* path_);
ICE_ID ICE_Texture_Load(char* path_);
ICE_ID ICE_Texture_Load_RW(SDL_RWops * rwops_);
void ICE_Texture_Destroy(ICE_ID texture_);
void ICE_Texture_Free(ICE_Texture * texture_);
unsigned int ICE_Texture_GetW(ICE_ID texture_);
unsigned int ICE_Texture_GetH(ICE_ID texture_);
ICE_Texture * ICE_Texture_Get(ICE_ID texture_);

#endif