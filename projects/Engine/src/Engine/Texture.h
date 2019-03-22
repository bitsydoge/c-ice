#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#include "../Framework/String_.h"
#include "Types.h"
#include "Vector.h"
#include "IO.h"
#define ICE_DEFAULT_TEXTUREMNGR_SIZE 4

#define ICE_Texture_Load_MEM(S) ICE_Texture_Load_RW(ICE_IO_FromConstMem(S, S##_length));\
	if(ICE_Texture_GetLastLoaded() != (ICE_ID)-1)\
		ICE_Log_Succes(ICE_MACROTOOLS_STRINGIZE(Texture loaded from memory : ID(%ld) Token(##S##)), ICE_Texture_GetLastLoaded());\
	else\
		ICE_Log_printf(ICE_MACROTOOLS_STRINGIZE(Texture didn t loaded from token : ##S));\

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// ------------------------------------     PUBLIC      -------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

ICE_TextureID ICE_Texture_GetLastLoaded();
ICE_TextureID ICE_Texture_Load(ICE_StringStd path_);
ICE_TextureID ICE_Texture_Load_RW(ICE_IO rwops_);
void ICE_Texture_Destroy(ICE_TextureID texture_);
ICE_Vect ICE_Texture_GetSize(ICE_TextureID texture_);
unsigned int ICE_Texture_GetWidth(ICE_TextureID texture_);
unsigned int ICE_Texture_GetHeight(ICE_TextureID texture_);

#endif