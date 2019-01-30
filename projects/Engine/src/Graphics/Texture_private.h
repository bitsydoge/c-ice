#ifndef DEF_ICE_TEXTURE_PRIVATE
#define DEF_ICE_TEXTURE_PRIVATE

#include "TypesGraphics.h"
#include "../Maths/TypesMaths.h"

ICE_Texture ICE_Texture_LoadFromFile(char *path);
int ICE_Texture_RenderEx(const ICE_Texture *texture, ICE_Box* src, ICE_Box* dst, const ICE_Float angle);
int ICE_Texture_RenderExCentered(const ICE_Texture* tex, ICE_Box* src, ICE_Box* dst, const ICE_Float angle);
ICE_Texture ICE_Texture_LoadFromFile_RW(SDL_RWops * rwops_);

#endif