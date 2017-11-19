#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#include <SDL2/SDL.h>
#include "Struct.h"
#include <stdio.h>
#include "../external/lodepng.h"
#include "TerminalColor.h"
#include "../external/icestd.h"

/// Load a PNG with lodepng to a Texture with Error handling
ICE_Texture* ICE_LoadPNG(ICE_Renderer *render, char *path);
/// Load a BMP with SDL_LoadBMP to a Texture with Error handling
ICE_Texture* ICE_LoadBMP(ICE_Renderer *render, char *path);
/// Load a BMP with SDL_LoadBMP to a Texture with Mono Alpha handle from a hex color
ICE_Texture* ICE_LoadBMPAlpha(ICE_Renderer *render, char *path, const ICE_Color rgba_hex);
/// Destroy the texture and free pointer
void ICE_TextureDestroy(ICE_Texture *tex);
/// Render a ICE_Texture to the renderer. The X, Y of the Source is the top left but the X, Y of the Destination is the center
int ICE_TextureRender(ICE_Game *game, int man, int text, ICE_Rect* source, ICE_Rect* destination);
/// NO CENTER
int ICE_TextureRenderNC(ICE_Game *game, int man, int text, ICE_Rect* source, ICE_Rect* destination);
/// Render a ICE_Texture to the renderer with a rotation
int ICE_TextureRenderEx(ICE_Renderer* renderer, const ICE_Texture *tex, ICE_Rect* source, ICE_Rect* destination, const double angle);
/// Create a new ICE_Color from a R G and B int; The A is 255, use NewColorA to set the transparancy
ICE_Color NewColor(const unsigned int r, const unsigned int g, const unsigned int b);
/// Create a new ICE_Color from a R G B and A int
ICE_Color NewColorA(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a);
/// Create the texture manager with a default number of texture, everytime the number of texture is too high, it will double
void ICE_TextureManagerCreate(ICE_Game *game);
/// Create a Texture in the choosed manager; Return the texture number
int ICE_TextureCreate(ICE_Game *game, int manager, char* path);

#endif
