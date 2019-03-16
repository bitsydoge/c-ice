#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#include "../Framework/String_.h"
#include "Types.h"
#include <SDL2/SDL.h>
#include "../Framework/BasicTypes.h"

#define ICE_DEFAULT_TEXTUREMNGR_SIZE 4

#define ICE_Texture_Load_MEM(S) ICE_Texture_Load_RW(SDL_RWFromConstMem(S, S##_length));\
	if(ICE_Texture_GetLastLoaded() != (ICE_ID)-1)\
		ICE_Log_Succes(ICE_MACROTOOLS_STRINGIZE(Texture loaded from memory : ID(%ld) Token(##S##)), ICE_Texture_GetLastLoaded());\
	else\
		ICE_Log_printf(ICE_MACROTOOLS_STRINGIZE(Texture didn t loaded from token : ##S));\

ICE_TextureID ICE_Texture_GetLastLoaded();
ICE_ID ICE_Texture_Load(ICE_StringStd path_);
ICE_ID ICE_Texture_Load_RW(SDL_RWops * rwops_);
void ICE_Texture_Destroy(ICE_ID texture_);


// Texture Tools
unsigned int ICE_Texture_GetW(ICE_ID texture_);
unsigned int ICE_Texture_GetH(ICE_ID texture_);

#endif