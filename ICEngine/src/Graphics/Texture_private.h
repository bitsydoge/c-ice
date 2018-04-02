#ifndef DEF_ICE_TEXTURE_PRIVATE
#define DEF_ICE_TEXTURE_PRIVATE

#include "TypesGraphics.h"
#include "../Maths/TypesMaths.h"

ICE_Texture* ICE_Texture_Load(char *path);
int ICE_Texture_RenderEx(const ICE_Texture *tex, ICE_Box* source, ICE_Box* destination, const double angle);
int ICE_Texture_RenderExCentered(const ICE_Texture *tex, ICE_Box* source, ICE_Box* destination, const double angle);

#endif