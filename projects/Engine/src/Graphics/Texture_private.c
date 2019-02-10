#include "Texture_private.h"

//#define STB_IMAGE_IMPLEMENTATION
//#include "../External/stb/stb_image.h"

#define SDL_STBIMAGE_IMPLEMENTATION 1
#include "../External/stb/SDL_stbimage.h"

#include "../Core/TypesCore.h"

#include "../Core/SDL2_Includer.h"
#include ICE_INCLUDE_SDL2

#include "TypesGraphics.h"
#include "../Maths/TypesMaths.h"
#include "../Core/Converter_private.h"
#include "../Framework/Log.h"

extern ICE_Game GAME;
extern ICE_Core CORE;

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
ICE_Uint32 static const rmask = 0xff000000;
ICE_Uint32 static const gmask = 0x00ff0000;
ICE_Uint32 static const bmask = 0x0000ff00;
ICE_Uint32 static const amask = 0x000000ff;
#else
ICE_Uint32 static const rmask = 0x000000ff;
ICE_Uint32 static const gmask = 0x0000ff00;
ICE_Uint32 static const bmask = 0x00ff0000;
ICE_Uint32 static const amask = 0xff000000;
#endif

ICE_Texture ICE_Texture_LoadFromFile_RW(SDL_RWops * rwops_)
{
	ICE_Texture text = {0};
	SDL_Surface* surf = STBIMG_Load_RW(rwops_, 1);
	if (surf == NULL) 
	{
		ICE_Log_Critical("Can't create Surface from image : %s", SDL_GetError());
		//stbi_image_free(data);

	//#include "../Ressources/raw/Error.c"
	//	surf = SDL_CreateRGBSurfaceFrom((void*)ice_raw_img_error.pixel_data, ice_raw_img_error.width,
	//		ice_raw_img_error.height, ice_raw_img_error.bytes_per_pixel * 8, ice_raw_img_error.bytes_per_pixel*ice_raw_img_error.width,
	//		rmask, gmask, bmask, amask);
		return text;
	}
	else
	{
		text.handle = SDL_CreateTextureFromSurface(CORE.window.render, surf);
		if (text.handle == NULL)
			ICE_Log_Critical("Can't create Texture from Surface : %s \n", SDL_GetError());
		text.w = surf->w; text.h = surf->h;
		SDL_FreeSurface(surf);
		return text;
	}
	

	
}

int ICE_Texture_RenderEx(const ICE_Texture *texture, ICE_Box* src, ICE_Box* dst, const ICE_Float angle) {

	if (!src && dst)
	{
		SDL_Rect s_dst = ICE_Convert_BoxToSDL(dst);
		return SDL_RenderCopyEx(CORE.window.render, texture->handle, NULL, &s_dst, angle, NULL, SDL_FLIP_NONE);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = ICE_Convert_BoxToSDL(src);
		return SDL_RenderCopyEx(CORE.window.render, texture->handle, &s_src, NULL, angle, NULL, SDL_FLIP_NONE);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopyEx(CORE.window.render, texture->handle, NULL, NULL, angle, NULL, SDL_FLIP_NONE);
	}
	SDL_Rect s_dst = ICE_Convert_BoxToSDL(dst);
	SDL_Rect s_src = ICE_Convert_BoxToSDL(src);
	return SDL_RenderCopyEx(CORE.window.render, texture->handle, &s_src, &s_dst, angle, NULL, SDL_FLIP_NONE);
}

int ICE_Texture_RenderEx2(const ICE_Texture* tex, ICE_Box* src, ICE_Box* dst, const ICE_Float angle)
{
	if (!src && dst)
	{
		SDL_Rect s_dst = ICE_Convert_BoxToSDL(dst);
		s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
		return SDL_RenderCopyEx(CORE.window.render, tex->handle, NULL, &s_dst, angle, NULL, SDL_FLIP_NONE);
	}
	if (src && !dst)
	{
		SDL_Rect s_src = ICE_Convert_BoxToSDL(src);
		return SDL_RenderCopyEx(CORE.window.render, tex->handle, &s_src, NULL, angle, NULL, SDL_FLIP_NONE);
	}
	if (!src && !dst)
	{
		return SDL_RenderCopyEx(CORE.window.render, tex->handle, NULL, NULL, angle, NULL, SDL_FLIP_NONE);
	}
	SDL_Rect s_dst = ICE_Convert_BoxToSDL(dst);
	s_dst.x -= s_dst.w / 2; s_dst.y -= s_dst.h / 2;
	SDL_Rect s_src = ICE_Convert_BoxToSDL(src);
	return SDL_RenderCopyEx(CORE.window.render, tex->handle, &s_src, &s_dst, angle, NULL, SDL_FLIP_NONE);
}