#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#include <SDL2/SDL.h>
#include "Struct.h"
#include "Types.h"
#include "Rect.h"
#include <stdio.h>
#include "../external/lodepng.h"
#include "../external/nanojpeg.h"
#include "Terminal.h"
#include "../external/icestd.h"

/// Load a JPG with nanojpeg to a Texture
ICE_Texture* ICE_LoadJPG(SDL_Renderer *render, char *path);
/// Load a PNG with lodepng to a Texture with Error handling
ICE_Texture* ICE_LoadPNG(ICE_Renderer *render, char *path);
/// Load a BMP with SDL_LoadBMP to a Texture with Error handling
ICE_Texture* ICE_LoadBMP(ICE_Renderer *render, char *path);
/// Load a BMP with SDL_LoadBMP to a Texture with Mono Alpha handle from a hex color
ICE_Texture* ICE_LoadBMPAlpha(ICE_Renderer *render, char *path, const iceColor rgba_hex);
/// Destroy the texture and free pointer
void ICE_TextureDestroy(ICE_Texture *tex);
/// Render a ICE_Texture to the renderer. The X, Y of the Source is the top left but the X, Y of the Destination is the center
int ICE_TextureRender(ICE_Game *game, int man, int text, iceRect* src, iceRect* dst);
/// NO CENTER
int ICE_TextureRenderCentered(ICE_Game *game, int man, int text, iceRect* src, iceRect* dst);
/// Render a ICE_Texture to the renderer with a rotation
int ICE_TextureRenderEx(ICE_Renderer* renderer, const ICE_Texture *tex, SDL_Rect* source, SDL_Rect* destination, const double angle);
/// Create a new iceColor from a R G and B int; The A is 255, use NewColorA to set the transparancy
iceColor NewColor(const unsigned int r, const unsigned int g, const unsigned int b);
/// Create a new iceColor from a R G B and A int
iceColor NewColorA(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a);
/// Create the texture manager with a default number of texture, everytime the number of texture is too high, it will double
void ICE_TextureManagerCreate(ICE_Game *game);
/// Create a Texture in the choosed manager; Return the texture number
int ICE_TextureCreate(ICE_Game *game, int manager, char* path);
/// Get a texture width
int ICE_TextureGetWidth(ICE_Game *game, int manager, int texture);
/// Get a texture height
int ICE_TextureGetHeight(ICE_Game *game, int manager, int texture);

#endif
