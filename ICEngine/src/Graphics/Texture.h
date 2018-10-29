#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#define ICE_DEFAULT_TEXTURE_SIZE 4

#include "TypesGraphics.h"

void ICE_TextureManager_Init();
void ICE_TextureManager_Destroy();
ICE_Id ICE_Texture_Load(char* path_);
void ICE_Texture_Destroy(ICE_Id texture_);
unsigned int ICE_Texture_GetW(ICE_Id texture_);
unsigned int ICE_Texture_GetH(ICE_Id texture_);
ICE_Texture * ICE_Texture_Get(ICE_Id texture_);

#endif