#ifndef DEF_ICE_TEXTURE_PRIVATE
#define DEF_ICE_TEXTURE_PRIVATE

#include "TypesGraphics.h"
#include "../Maths/TypesMaths.h"

ICE_Texture* ICE_LoadImage(char *path);
void ICE_TextureDestroy(ICE_Texture *tex);
int ICE_TextureRenderEx(const ICE_Texture *tex, ICE_Box* source, ICE_Box* destination, const double angle);

#endif