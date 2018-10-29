#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#define ICE_DEFAULT_TEXTURE_SIZE 4

#include "TypesGraphics.h"

ICE_Id ICE_TextureManager_Insert();
void ICE_TextureManager_Destroy(const ICE_Id man);
void ICE_TextureManager_DestroyAll();
ICE_Id ICE_Texture_Load(ICE_Id manager, char* path);
void ICE_Texture_Destroy(ICE_Texture * tex);
ICE_Texture * ICE_Texture_Get(ICE_Id man, ICE_Id nb);
unsigned int ICE_Texture_GetW(ICE_Texture * text);
unsigned int ICE_Texture_GetH(ICE_Texture * text);

#endif