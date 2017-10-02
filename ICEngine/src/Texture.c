#include "hdr/Texture.h"
#include <stdio.h>
#include "external/lodepng.h"

ICE_Texture* ICE_LoadPNG(SDL_Renderer *render, char *path)
{
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	Uint32 static const rmask = 0xff000000;
	Uint32 static const gmask = 0x00ff0000;
	Uint32 static const bmask = 0x0000ff00;
	Uint32 static const amask = 0x000000ff;
#else
	Uint32 static const rmask = 0x000000ff;
	Uint32 static const gmask = 0x0000ff00;
	Uint32 static const bmask = 0x00ff0000;
	Uint32 static const amask = 0xff000000;
#endif

	unsigned char* raw_img;
	unsigned w, h;
	unsigned const error = lodepng_decode32_file(&raw_img, &w, &h, path);
	if (error)
	{
		printf("\"%s\" -> PNG Decoder error %u : %s\n", path, error, lodepng_error_text(error));
	}

	SDL_Surface *surf = SDL_CreateRGBSurfaceFrom(raw_img, w, h, 32, 4 * w, rmask, gmask, bmask, amask);
	if (error)
	{
		surf = SDL_LoadBMP("res/img/error.bmp");
		if (surf == NULL)
		{
			printf("CRITICAL : Can't load image \"%s\" : %s \n", "res/img/error.bmp", SDL_GetError());
		}
	}
	ICE_Texture *text = (ICE_Texture*)malloc(sizeof(ICE_Texture));
	text->handle = SDL_CreateTextureFromSurface(render, surf);
	if (text->handle == NULL)
	{
		printf("CRITICAL : Can't create Texture from Surface \"%s\" : %s \n", path, SDL_GetError());
	}
	text->w = surf->w; text->h = surf->h;

	SDL_FreeSurface(surf);
	return text;
}

ICE_Texture* ICE_LoadBMP(SDL_Renderer *render, char *path)
{
	SDL_Surface *surf = SDL_LoadBMP(path);
	if (surf == NULL)
	{
		surf = SDL_LoadBMP("res/img/error.bmp");
		if (surf == NULL)
		{
			printf("CRITICAL : Can't load image \"%s\" : %s \n", "res/img/error.bmp", SDL_GetError());
		}
	}


	ICE_Texture *text = (ICE_Texture*)malloc(sizeof(ICE_Texture));
	text->handle = SDL_CreateTextureFromSurface(render, surf);
	if (text->handle == NULL)
	{
		printf("CRITICAL : Can't create Texture from Surface \"%s\" : %s \n", path, SDL_GetError());
	}
	text->w = surf->w; text->h = surf->h;
	SDL_FreeSurface(surf);
	return text;
}

ICE_Texture* ICE_LoadBMPAlpha(SDL_Renderer *render, char *path,const Uint32 rgba_hex)
{
	const int r = rgba_hex >> 24 & 255;
	const int g = rgba_hex >> 16 & 255;
	const int b = rgba_hex >> 8 & 255;
	const int a = rgba_hex & 255;

	SDL_Surface *surf = SDL_LoadBMP(path);
	if (surf == NULL)
	{
		surf = SDL_LoadBMP("res/img/error.bmp");
		if (surf == NULL)
		{
			printf("CRITICAL : Can't load image \"%s\" : %s \n", "res/img/error.bmp", SDL_GetError());
		}
	}
	else if (r >= 0 && g >= 0 && b >= 0)
	{
		SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, r, g, b));
		if (a < 255 && a >= 0)
			SDL_SetSurfaceAlphaMod(surf, a);
	}

	ICE_Texture *text = (ICE_Texture*)malloc(sizeof(ICE_Texture));
	text->handle = SDL_CreateTextureFromSurface(render, surf);

	if (text->handle == NULL)
	{
		printf("CRITICAL : Can't create Texture from Surface \"%s\" : %s \n", path, SDL_GetError());
	}

	text->w = surf->w; text->h = surf->h;
	SDL_FreeSurface(surf);
	return text;
}

int ICE_TextureRender(SDL_Renderer* renderer, ICE_Texture *tex, SDL_Rect* source, SDL_Rect* destination)
{
	return SDL_RenderCopy(renderer, tex->handle, source, destination);
}

int ICE_TextureRenderEx(SDL_Renderer* renderer, const ICE_Texture *tex, SDL_Rect* source, SDL_Rect* destination, const double angle)
{
	return SDL_RenderCopyEx(renderer, tex->handle, source, destination, angle, NULL, SDL_FLIP_NONE);
}

Uint32 ICE_Rgba(const unsigned int r, const unsigned int g,const unsigned int b,const unsigned int a)
{
	return (r << 24) + (g << 16) + (b << 8) + a;

}