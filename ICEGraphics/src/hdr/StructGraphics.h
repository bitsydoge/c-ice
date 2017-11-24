#ifndef DEF_ICE_STRUCTGRAPHICS
#define DEF_ICE_STRUCTGRAPHICS

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct {

	float x, y;
	int w, h;
	float speed;

} iceCamera;

typedef struct {

	int exist;
	int w;
	int h;
	SDL_Texture* handle;

} iceTexture;


typedef struct {

	int array_size;
	int nb_existing_texture;
	iceTexture* texture;
	SDL_Renderer *ren;

} iceTextureManager;

typedef struct {

	TTF_Font* size[256];

}iceFontManager;

#endif

