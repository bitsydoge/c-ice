﻿#ifndef DEF_ICE_TEXTURE_PRIVATE
#define DEF_ICE_TEXTURE_PRIVATE

#include "Texture.h"
#include "Box.h"
#include "SDL2_Includer.h"
#include ICE_INCLUDE_SDL2

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

ICE_Texture ICE_Texture_Build_RW(SDL_RWops* rwops);
int ICE_Texture_RenderEx(const ICE_Texture *texture, ICE_Box* src, ICE_Box* dst, const ICE_Float angle);
int ICE_Texture_RenderEx2(const ICE_Texture* tex, ICE_Box* src, ICE_Box* dst, const ICE_Float angle);
ICE_Texture ICE_Texture_LoadFromFile(char *path);
ICE_Texture ICE_Texture_LoadFromFile_RW(SDL_RWops * rwops_);
ICE_Texture* ICE_Texture_Get(ICE_ID texture_);
void ICE_Texture_Free(ICE_Texture* texture_);

#endif