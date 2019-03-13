#ifndef DEF_ICE_TEXTURE_PRIVATE
#define DEF_ICE_TEXTURE_PRIVATE

#include "Texture.h"
#include "Box.h"
#include "SDL2_Includer.h"
#include ICE_INCLUDE_SDL2

int ICE_Texture_RenderEx(const ICE_Texture *texture, ICE_Box* src, ICE_Box* dst, const ICE_Float angle);
int ICE_Texture_RenderEx2(const ICE_Texture* tex, ICE_Box* src, ICE_Box* dst, const ICE_Float angle);
ICE_Texture ICE_Texture_LoadFromFile(char *path);
ICE_Texture ICE_Texture_LoadFromFile_RW(SDL_RWops * rwops_);

#endif