#ifndef DEF_ICE_TEXTURE_PRIVATE
#define DEF_ICE_TEXTURE_PRIVATE

#include "TypesCore.h"

iceTexture* iceLoadImage(char *path);

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
