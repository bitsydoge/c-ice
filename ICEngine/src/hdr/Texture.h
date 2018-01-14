#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE

#include "TypesCore.h"
#include "Box.h"

#define ICE_DEFAULT_TEXTURE_SIZE 4

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
/// Create the texture manager with a default number of texture, everytime the number of texture is too high, it will double
void iceTextureManagerCreate();
/// Create a Texture in the choosed manager; Return the texture number
int iceTextureCreate(int manager, char* path);
/// Get a texture width
int iceTextureGetWidth(int manager, int texture);
/// Get a texture height
int iceTextureGetHeight(int manager, int texture);

#endif
