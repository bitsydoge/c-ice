#include <SDL2/SDL.h>
#include "hdr/Converter_private.h"
#include <stdio.h>
#include "hdr/TypesCore.h"

#define STB_IMAGE_IMPLEMENTATION
#include "external/stb_image.h"

extern iceGame game;

iceTexture* iceLoadImage(char *path)
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

	iceTexture *text = (iceTexture*)malloc(sizeof(iceTexture));
	text->handle = SDL_CreateTextureFromSurface(game.drawer.render, surf);
	if (text->handle == NULL)
		printf("CRITICAL : Can't create Texture from Surface \"%s\" : %s \n", path, SDL_GetError());
	text->w = surf->w; text->h = surf->h;

	SDL_FreeSurface(surf);
	stbi_image_free(data);
	return text;
}

void iceTextureDestroy(iceTexture *tex) {
	SDL_DestroyTexture(tex->handle);
	free(tex);
}

int iceTextureRender(int man, int text, iceBox* src, iceBox* dst) {
	if (!src && dst)
	{
		SDL_Rect s_dst = iceConvertBoxToSdl(dst);
		return SDL_RenderCopy(game.drawer.render, game.texturemanager[man].texture[text].handle, NULL, &s_dst);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = iceConvertBoxToSdl(src);
		return SDL_RenderCopy(game.drawer.render, game.texturemanager[man].texture[text].handle, &s_src, NULL);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopy(game.drawer.render, game.texturemanager[man].texture[text].handle, NULL, NULL);
	}
	SDL_Rect s_dst = iceConvertBoxToSdl(dst);
	SDL_Rect s_src = iceConvertBoxToSdl(src);
	return SDL_RenderCopy(game.drawer.render, game.texturemanager[man].texture[text].handle, &s_src, &s_dst);
}

int iceTextureRenderCentered(int man, int text, iceBox* src, iceBox* dst) {
	if (!src && dst)
	{
		SDL_Rect s_dst = iceConvertBoxToSdl(dst);
		s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
		return SDL_RenderCopy(game.drawer.render, game.texturemanager[man].texture[text].handle, NULL, &s_dst);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = iceConvertBoxToSdl(src);
		return SDL_RenderCopy(game.drawer.render, game.texturemanager[man].texture[text].handle, &s_src, NULL);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopy(game.drawer.render, game.texturemanager[man].texture[text].handle, NULL, NULL);
	}
	SDL_Rect s_dst = iceConvertBoxToSdl(dst);
	s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
	SDL_Rect s_src = iceConvertBoxToSdl(src);
	return SDL_RenderCopy(game.drawer.render, game.texturemanager[man].texture[text].handle, &s_src, &s_dst);
}

int iceTextureRenderCenteredEx(int man, int text, iceBox* src, iceBox* dst, iceFloat angle) {
	if (!src && dst)
	{
		SDL_Rect s_dst = iceConvertBoxToSdl(dst);
		s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
		return SDL_RenderCopyEx(game.drawer.render, game.texturemanager[man].texture[text].handle, NULL, &s_dst, angle, NULL, 0);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = iceConvertBoxToSdl(src);
		return SDL_RenderCopyEx(game.drawer.render, game.texturemanager[man].texture[text].handle, &s_src, NULL, angle, NULL, 0);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopyEx(game.drawer.render, game.texturemanager[man].texture[text].handle, NULL, NULL, angle, NULL, 0);
	}
	SDL_Rect s_dst = iceConvertBoxToSdl(dst);
	s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
	SDL_Rect s_src = iceConvertBoxToSdl(src);
	return SDL_RenderCopy(game.drawer.render, game.texturemanager[man].texture[text].handle, &s_src, &s_dst);
}

int iceTextureRenderCenteredTexture(iceTexture *texture, iceBox* src, iceBox* dst)
{
	if (!src && dst)
	{
		SDL_Rect s_dst = iceConvertBoxToSdl(dst);
		s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
		return SDL_RenderCopy(game.drawer.render, texture->handle, NULL, &s_dst);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = iceConvertBoxToSdl(src);
		return SDL_RenderCopy(game.drawer.render, texture->handle, &s_src, NULL);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopy(game.drawer.render, texture->handle, NULL, NULL);
	}
	SDL_Rect s_dst = iceConvertBoxToSdl(dst);
	s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
	SDL_Rect s_src = iceConvertBoxToSdl(src);
	return SDL_RenderCopy(game.drawer.render, texture->handle, &s_src, &s_dst);
}

int iceTextureRenderTexture(iceTexture *texture, iceBox* src, iceBox* dst)
{
	if (!src && dst)
	{
		SDL_Rect s_dst = iceConvertBoxToSdl(dst);
		return SDL_RenderCopy(game.drawer.render, texture->handle, NULL, &s_dst);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = iceConvertBoxToSdl(src);
		return SDL_RenderCopy(game.drawer.render, texture->handle, &s_src, NULL);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopy(game.drawer.render, texture->handle, NULL, NULL);
	}
	SDL_Rect s_dst = iceConvertBoxToSdl(dst);
	SDL_Rect s_src = iceConvertBoxToSdl(src);
	return SDL_RenderCopy(game.drawer.render, texture->handle, &s_src, &s_dst);
}

int iceTextureRenderEx(const iceTexture *tex, iceBox* source, iceBox* destination, const double angle) {

	SDL_Rect rect = iceConvertBoxToSdl(source);
	SDL_Rect rect2 = iceConvertBoxToSdl(destination);
	return SDL_RenderCopyEx(game.drawer.render, tex->handle, &rect, &rect2, angle, NULL, SDL_FLIP_NONE);
}