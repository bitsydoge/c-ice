#ifndef DEF_iceTEXTURE
#define DEF_iceTEXTURE

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
iceTexture* iceLoadJPG(SDL_Renderer *render, char *path);
/// Load a PNG with lodepng to a Texture with Error handling
iceTexture* iceLoadPNG(iceRenderer *render, char *path);
/// Load a BMP with SDL_LoadBMP to a Texture with Error handling
iceTexture* iceLoadBMP(iceRenderer *render, char *path);
/// Load a BMP with SDL_LoadBMP to a Texture with Mono Alpha handle from a hex color
iceTexture* iceLoadBMPAlpha(iceRenderer *render, char *path, const iceColor rgba_hex);
/// Destroy the texture and free pointer
void iceTextureDestroy(iceTexture *tex);
/// Render a iceTexture to the renderer. The X, Y of the Source is the top left but the X, Y of the Destination is the center
int iceTextureRender(iceGame *game, int man, int text, iceRect* src, iceRect* dst);
/// NO CENTER
int iceTextureRenderCentered(iceGame *game, int man, int text, iceRect* src, iceRect* dst);
/// Render a iceTexture to the renderer with a rotation
int iceTextureRenderEx(iceRenderer* renderer, const iceTexture *tex, SDL_Rect* source, SDL_Rect* destination, const double angle);
/// Create a new iceColor from a R G and B int; The A is 255, use NewColorA to set the transparancy
iceColor NewColor(const unsigned int r, const unsigned int g, const unsigned int b);
/// Create a new iceColor from a R G B and A int
iceColor NewColorA(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a);
/// Create the texture manager with a default number of texture, everytime the number of texture is too high, it will double
void iceTextureManagerCreate(iceGame *game);
/// Create a Texture in the choosed manager; Return the texture number
int iceTextureCreate(iceGame *game, int manager, char* path);
/// Get a texture width
int iceTextureGetWidth(iceGame *game, int manager, int texture);
/// Get a texture height
int iceTextureGetHeight(iceGame *game, int manager, int texture);

#endif
