#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#include "../Framework/String_.h"
#include "TypesCore.h"
#include <SDL2/SDL.h>

/**
 * \brief Texture struct handling sdl texture
 */
struct ICE_Texture
{
	ICE_ID id;
	ICE_Bool	 exist;
	unsigned int w, h;
	SDL_Texture* handle;

}; typedef struct ICE_Texture ICE_Texture;

#define ICE_DEFAULT_TEXTUREMNGR_SIZE 4

void ICE_TextureManager_Init();
void ICE_TextureManager_Destroy();

#define ICE_Texture_Load_MEM(S) ICE_Texture_Load_RW(SDL_RWFromConstMem(S, S##_length));\
	if(ICE_Texture_GetLastLoaded() != (ICE_ID)-1)\
		ICE_Log_Succes(ICE_MACROTOOLS_STRINGIZE(Texture loaded from memory : ID(%ld) Token(##S##)), ICE_Texture_GetLastLoaded());\
	else\
		ICE_Log_printf(ICE_MACROTOOLS_STRINGIZE(Texture didn t loaded from token : ##S));\

ICE_TextureID ICE_Texture_GetLastLoaded();
ICE_ID ICE_Texture_Load(ICE_StringStd path_);
ICE_Texture ICE_Texture_Build_RW(SDL_RWops * rwops);
ICE_ID ICE_Texture_Load_RW(SDL_RWops * rwops_);
void ICE_Texture_Destroy(ICE_ID texture_);
void ICE_Texture_Free(ICE_Texture * texture_);

// Texture Tools
unsigned int ICE_Texture_GetW(ICE_ID texture_);
unsigned int ICE_Texture_GetH(ICE_ID texture_);
ICE_Texture * ICE_Texture_Get(ICE_ID texture_);

#endif