#ifndef DEF_ICE_TEXTURE_PRIVATE
#define DEF_ICE_TEXTURE_PRIVATE

#include "TypesGraphics.h"
#include "../Maths/TypesMaths.h"

int ICE_Texture_RenderEx(const ICE_Texture *texture, ICE_Box* src, ICE_Box* dst, const ICE_Float angle);
int ICE_Texture_RenderEx2(const ICE_Texture* tex, ICE_Box* src, ICE_Box* dst, const ICE_Float angle);
ICE_Texture ICE_Texture_LoadFromFile(char *path);
ICE_Texture ICE_Texture_LoadFromFile_RW(SDL_RWops * rwops_);
void ICE_Texture_ErrorInit();
void ICE_Texture_LogoInit();
void ICE_Texture_DefaultGuiInit();

void ICE_Texture_LogoFree();
void ICE_Texture_DefaultGuiFree();
void ICE_Texture_ErrorFree();
void ICE_Texture_DefaultAllFree();

#endif