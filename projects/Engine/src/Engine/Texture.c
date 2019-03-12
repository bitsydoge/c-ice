#include "Texture.h"
#include "Texture_private.h"

#include "../Framework/Log.h"

#include "../Framework/Memory_.h"
#include "../External/physfs/physfsrwops.h"
#include "TypesCore.h"
#include "TextureManager_private.h"

#define SDL_STBIMAGE_IMPLEMENTATION 1
#include "../External/stb/SDL_stbimage.h"

extern ICE_TextureManager TEXTURE_MANAGER;
ICE_ID last_loaded_texture = (ICE_ID)-1;

/* TEXTUREMANAGER */

void ICE_TextureManager_Init() 
{
	ICE_TextureManager texture_manager = { 0 };
	texture_manager.texture_size = ICE_DEFAULT_TEXTUREMNGR_SIZE;
	texture_manager.texture = ICE_Calloc(ICE_DEFAULT_TEXTUREMNGR_SIZE, sizeof(ICE_Texture));
	TEXTURE_MANAGER = texture_manager;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Init TextureManager");
}

void ICE_TextureManager_Destroy()
{
	for (ICE_ID i = 0; i < TEXTURE_MANAGER.texture_contain; i++)
		ICE_Texture_Destroy(i);

	ICE_Free(TEXTURE_MANAGER.texture);
	TEXTURE_MANAGER.texture = NULL;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Free TextureManager");
}

/* TEXTURE */

ICE_TextureID ICE_Texture_GetLastLoaded()
{
	return last_loaded_texture;
}

ICE_ID ICE_Texture_Load(ICE_StringStd path_) 
{
	SDL_RWops * ops = NULL;

	if(ICE_AssetPak_isPathFromPak(path_))
	{
		PHYSFS_File * ph_file = PHYSFS_openRead(path_ + 6);
		ops = PHYSFSRWOPS_makeRWops(ph_file);
	}
	else
	{
		ops = SDL_RWFromFile(path_, "rb");
	}

	ICE_ID temp_id = ICE_Texture_Load_RW(ops);

	if(temp_id != (ICE_ID)-1)
		ICE_Log_Succes("Texture loaded from path : ID(%ld), Path(\"%s\")",temp_id, path_);
	else
		ICE_Log_Error("Texture didn't loaded from file : %s", path_);

	return temp_id;
}

ICE_Texture ICE_Texture_Build_RW(SDL_RWops * rwops_)
{
	ICE_Texture texture_temp = ICE_Texture_LoadFromFile_RW(rwops_);
	texture_temp.exist = 1;
	int w, h;
	SDL_QueryTexture(texture_temp.handle, NULL, NULL, &w, &h);
	texture_temp.w = w; texture_temp.h = h;
	SDL_SetTextureBlendMode(texture_temp.handle, SDL_BLENDMODE_BLEND);
	return texture_temp;
}

ICE_ID ICE_Texture_Load_RW(SDL_RWops * rwops_) 
{
	ICE_Texture temp = ICE_Texture_Build_RW(rwops_);
	if(temp.handle)
	{
		ICE_EntityID avaible_slot = 0;
		ICE_Bool no_avaible_slot = ICE_False;

		for (ICE_EntityID i = 0; i < TEXTURE_MANAGER.texture_contain; i++)
		{
			if (TEXTURE_MANAGER.texture[i].exist == ICE_False)
			{
				avaible_slot = i;
				no_avaible_slot = ICE_True;
				break;
			}
		}
		if (!no_avaible_slot)
		{
			avaible_slot = TEXTURE_MANAGER.texture_contain;
			TEXTURE_MANAGER.texture_contain++;
		}

		TEXTURE_MANAGER.texture[avaible_slot] = temp;
		TEXTURE_MANAGER.texture[avaible_slot].id = avaible_slot;

		//ICE_Log(ICE_LOGTYPE_SUCCES, "Load Texture %d succes", avaible_slot);
		
		if (TEXTURE_MANAGER.texture_size <= TEXTURE_MANAGER.texture_contain) 
		{
			TEXTURE_MANAGER.texture = ICE_Realloc(TEXTURE_MANAGER.texture, sizeof(ICE_Texture)*(TEXTURE_MANAGER.texture_size * 2));
			TEXTURE_MANAGER.texture_size *= 2;
		}

		last_loaded_texture = avaible_slot;
		return avaible_slot;
	}
	return (ICE_TextureID)-1; // ERROR ID
}

void ICE_Texture_Destroy(ICE_ID texture_) 
{
	TEXTURE_MANAGER.texture[texture_].exist = ICE_False;
	SDL_DestroyTexture(TEXTURE_MANAGER.texture[texture_].handle);
	ICE_Log(ICE_LOGTYPE_SUCCES, "Destroy Texture %d", texture_);
}

void ICE_Texture_Free(ICE_Texture * texture_)
{
	SDL_DestroyTexture(texture_->handle);
}

unsigned int ICE_Texture_GetW(ICE_ID texture_)
{
	return TEXTURE_MANAGER.texture[texture_].w;
}

unsigned int ICE_Texture_GetH(ICE_ID texture_)
{
	return TEXTURE_MANAGER.texture[texture_].h;
}

ICE_Texture * ICE_Texture_Get(ICE_ID texture_)
{
	return &TEXTURE_MANAGER.texture[texture_];
}

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

ICE_Texture ICE_Texture_LoadFromFile_RW(SDL_RWops* rwops_)
{
	ICE_Texture text = { 0 };
	SDL_Surface* surf = STBIMG_Load_RW(rwops_, 1);
	if (surf == NULL)
	{
		ICE_Log_Critical("Can't create Surface from image : %s", SDL_GetError());
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

int ICE_Texture_RenderEx(const ICE_Texture * texture, ICE_Box * src, ICE_Box * dst, const ICE_Float angle) {

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

int ICE_Texture_RenderEx2(const ICE_Texture * tex, ICE_Box * src, ICE_Box * dst, const ICE_Float angle)
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

void ICE_Texture_ErrorInit()
{
	SDL_RendererInfo info_renderer;
	SDL_GetRendererInfo(CORE.window.render, &info_renderer);
	if (info_renderer.max_texture_width >= 1024 && info_renderer.max_texture_height >= 1024)
	{
#include "../Ressources/bin/err1024_png.c"
		ASSET.texture_error = ICE_Texture_LoadFromFile_RW(SDL_RWFromMem((void*)ICE_Ressource_err1024_png, ICE_Ressource_err1024_png_length));
	}
	else
	{
#include "../Ressources/bin/err512_png.c"
		ASSET.texture_error = ICE_Texture_LoadFromFile_RW(SDL_RWFromMem((void*)ICE_Ressource_err512_png, ICE_Ressource_err512_png_length));
	}
}

void ICE_Texture_DefaultGuiInit()
{
#include "../Ressources/bin/gui27_png.c"
	ASSET.texture_gui_default = ICE_Texture_LoadFromFile_RW(SDL_RWFromMem((void*)ICE_Ressource_gui27_png, ICE_Ressource_gui27_png_length));
}

void ICE_Texture_LogoInit()
{
#include "../Ressources/bin/logo_png.c"
	ASSET.texture_logo = ICE_Texture_LoadFromFile_RW(SDL_RWFromMem((void*)ICE_Ressource_logo_png, ICE_Ressource_logo_png_length));
}

void ICE_Texture_DefaultGuiFree()
{
	ICE_Texture_Free(&ASSET.texture_gui_default);
}

void ICE_Texture_ErrorFree()
{
	ICE_Texture_Free(&ASSET.texture_error);
}

void ICE_Texture_LogoFree()
{
	ICE_Texture_Free(&ASSET.texture_error);
}

void ICE_Texture_DefaultAllFree()
{
	ICE_Texture_DefaultGuiFree();
	ICE_Texture_ErrorFree();
	ICE_Texture_LogoFree();
}