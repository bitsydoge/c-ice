#ifndef DEF_ICE_TEXTURE_PRIVATE
#define DEF_ICE_TEXTURE_PRIVATE

#include "TypesCore.h"

/// Load a JPG with nanojpeg to a Texture
iceTexture* iceLoadJPG(char *path);
/// Load a PNG with lodepng to a Texture with Error handling
iceTexture* iceLoadPNG(char *path);
/// Load a BMP with SDL_LoadBMP to a Texture with Error handling
iceTexture* iceLoadBMP(char *path);
/// Load a BMP with SDL_LoadBMP to a Texture with Mono Alpha handle from a hex color
iceTexture* iceLoadBMPAlpha(char *path, const iceColor rgba_hex);
/// Destroy the texture and free pointer
void iceTextureDestroy(iceTexture *tex);
/// Render a iceTexture to the renderer. The X, Y of the Source is the top left but the X, Y of the Destination is the center
int iceTextureRender(int man, int text, iceBox* src, iceBox* dst);
/// NO CENTER
int iceTextureRenderCentered(int man, int text, iceBox* src, iceBox* dst);
/// 
int iceTextureRenderCenteredEx(int man, int text, iceBox* src, iceBox* dst, iceFloat angle);
/// Render a iceTexture to the renderer with a rotation
int iceTextureRenderCenteredTexture(iceTexture *texture, iceBox* src, iceBox* dst);
/// 
int iceTextureRenderTexture(iceTexture *texture, iceBox* src, iceBox* dst);
///
int iceTextureRenderEx(const iceTexture *tex, iceBox* source, iceBox* destination, const double angle);

#endif
