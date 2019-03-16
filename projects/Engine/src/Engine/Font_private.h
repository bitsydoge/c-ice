#ifndef DEF_ICE_FONT_PRIVATE_H
#define DEF_ICE_FONT_PRIVATE_H

#include "Types.h"

#include "SDL2_Includer_private.h"
#include ICE_INCLUDE_SDL2_TTF

struct ICE_Font
{
	ICE_FontID id;
	ICE_Bool exist;
	TTF_Font * size[256];

}; typedef struct ICE_Font ICE_Font;

ICE_Font ICE_Font_Build_RW(SDL_RWops* rwops_);

#endif