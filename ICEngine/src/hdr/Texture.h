#ifndef DEF_ICE_TEXTURE
#define DEF_ICE_TEXTURE
#include <SDL2/SDL.h>

typedef struct
{
	SDL_Texture* handle;
	unsigned int w;
	unsigned int h;
} ICE_Texture;

/// Load a PNG with lodepng to a Texture with Error handling
ICE_Texture* ICE_LoadPNG(SDL_Renderer *render, char *path);
/// Load a BMP with SDL_LoadBMP to a Texture with Error handling
ICE_Texture* ICE_LoadBMP(SDL_Renderer *render, char *path);
/// Load a BMP with SDL_LoadBMP to a Texture with Mono Alpha handle from a hex color
ICE_Texture* ICE_LoadBMPAlpha(SDL_Renderer *render, char *path, const Uint32 rgba_hex);
/// Render a ICE_Texture to the renderer
int ICE_TextureRender(SDL_Renderer* renderer, ICE_Texture* tex, SDL_Rect* source, SDL_Rect* destination);
/// Render a ICE_Texture to the renderer with a rotation
int ICE_TextureRenderEx(SDL_Renderer* renderer, const ICE_Texture *tex, SDL_Rect* source, SDL_Rect* destination, const double angle);
/// Convert ARGB to a Uint32 (Hex color)
Uint32 ICE_Rgba(const unsigned int r, const unsigned int g, const unsigned int b, const unsigned int a);

#endif
