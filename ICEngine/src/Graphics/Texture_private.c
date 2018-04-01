﻿#include "Texture_private.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../External/stb_image.h"

#include "../Core/TypesCore.h"

#include "TypesGraphics.h"
#include "../Maths/TypesMaths.h"
#include "../Core/Converter_private.h"

extern ICE_Game game;

ICE_Texture* ICE_Texture_Load(char *path)
{
	int req_format = STBI_rgb_alpha;
	int width, height, orig_format;
	unsigned char* data = stbi_load(path, &width, &height, &orig_format, req_format);
	if (data == NULL) {
		SDL_Log("ERROR : Can't load image : %s", stbi_failure_reason());
		exit(1);
	}

	int depth, pitch;
	Uint32 pixel_format;
	if (req_format == STBI_rgb) {
		depth = 24;
		pitch = 3 * width;
		pixel_format = SDL_PIXELFORMAT_RGB24;
	}
	else {
		depth = 32;
		pitch = 4 * width;
		pixel_format = SDL_PIXELFORMAT_RGBA32;
	}

	SDL_Surface* surf = SDL_CreateRGBSurfaceWithFormatFrom((void*)data, width, height,
		depth, pitch, pixel_format);

	if (surf == NULL) {
		SDL_Log("CRITICAL : Can't create Surface from image ", SDL_GetError());
		stbi_image_free(data);
		exit(1);
	}

	ICE_Texture *text = (ICE_Texture*)malloc(sizeof(ICE_Texture));
	text->handle = SDL_CreateTextureFromSurface(game.window.render, surf);
	if (text->handle == NULL)
		printf("CRITICAL : Can't create Texture from Surface \"%s\" : %s \n", path, SDL_GetError());
	text->w = surf->w; text->h = surf->h;

	SDL_FreeSurface(surf);
	stbi_image_free(data);
	return text;
}

int ICE_TextureRenderEx(const ICE_Texture *tex, ICE_Box* source, ICE_Box* destination, const double angle) {

	SDL_Rect rect = ICE_Convert_BoxToSDL(source);
	SDL_Rect rect2 = ICE_Convert_BoxToSDL(destination);
	return SDL_RenderCopyEx(game.window.render, tex->handle, &rect, &rect2, angle, NULL, SDL_FLIP_NONE);
}