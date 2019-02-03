#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#include "TypesGraphics.h"
#include "../Framework/String_.h"
#include "../Framework/Macrotools.h"

#define ICE_DEFAULT_TEXTUREMNGR_SIZE 4

void ICE_TextureManager_Init();
void ICE_TextureManager_Destroy();

#define ICE_Texture_LoadFromEmbedded(S) ICE_Texture_Load_RW(SDL_RWFromConstMem(S, S##_length));\
	ICE_Log_Succes(ICE_MACROTOOLS_STRINGIZE(Texture number %ld loaded from embedded binary : ## S), ICE_Texture_GetLastLoaded());\

ICE_TextureID ICE_Texture_GetLastLoaded();
ICE_ID ICE_Texture_Load(ICE_StringStd path_);
ICE_Texture ICE_Texture_Build_RW(SDL_RWops * rwops);
ICE_ID ICE_Texture_Load_RW(SDL_RWops * rwops_);
void ICE_Texture_Destroy(ICE_ID texture_);
void ICE_Texture_Free(ICE_Texture * texture_);
unsigned int ICE_Texture_GetW(ICE_ID texture_);
unsigned int ICE_Texture_GetH(ICE_ID texture_);
ICE_Texture * ICE_Texture_Get(ICE_ID texture_);

#endif