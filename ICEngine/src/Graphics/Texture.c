﻿#include "Texture.h"

#include "TypesGraphics.h"
#include "../Core/TypesCore.h"
#include "../Framework/Log.h"

#include "Texture_private.h"
#include "../Framework/Memory_.h"

extern ICE_Asset ASSET;
extern ICE_Game GAME;

/* TEXTUREMANAGER */

void ICE_TextureManager_Init() 
{
	ICE_TextureManager texture_manager = { 0 };
	texture_manager.texture_size = ICE_DEFAULT_TEXTUREMNGR_SIZE;
	texture_manager.texture = ICE_Calloc(ICE_DEFAULT_TEXTUREMNGR_SIZE, sizeof(ICE_Texture));
	ASSET.texture_mngr = texture_manager;
	ICE_Log(ICE_LOG_SUCCES, "Init TextureManager");
}

void ICE_TextureManager_Free()
{
	for (ICE_ID i = 0; i < ASSET.texture_mngr.texture_contain; i++)
		ICE_Texture_Destroy(i);

	ICE_Free(ASSET.texture_mngr.texture);
	ICE_Log(ICE_LOG_SUCCES, "Free TextureManager");
}

/* TEXTURE */

ICE_Texture ICE_Texture_Create(char* path_)
{
	ICE_Texture texture_temp = ICE_Texture_LoadFromFile(path_);
	texture_temp.exist = 1;
	int w, h;
	SDL_QueryTexture(texture_temp.handle, NULL, NULL, &w, &h);
	texture_temp.w = w; texture_temp.h = h;
	texture_temp.id = ASSET.texture_mngr.texture_contain;
	SDL_SetTextureBlendMode(texture_temp.handle, SDL_BLENDMODE_BLEND);
	return texture_temp;
}

ICE_ID ICE_Texture_Load(char* path_) 
{
	ASSET.texture_mngr.texture[ASSET.texture_mngr.texture_contain] = ICE_Texture_Create(path_);
	ASSET.texture_mngr.texture_contain++;
	ICE_Log(ICE_LOG_SUCCES, "Load Texture %d from Path=\"%s\"", ASSET.texture_mngr.texture_contain - 1, path_);
	
	if (ASSET.texture_mngr.texture_size <= ASSET.texture_mngr.texture_contain) 
	{
		ASSET.texture_mngr.texture = ICE_Realloc(ASSET.texture_mngr.texture, sizeof(ICE_Texture)*(ASSET.texture_mngr.texture_size * 2));
		ASSET.texture_mngr.texture_size *= 2;
	}
	
	return ASSET.texture_mngr.texture_contain - 1;
}

void ICE_Texture_Destroy(ICE_ID texture_) 
{
	SDL_DestroyTexture(ASSET.texture_mngr.texture[texture_].handle);
	ICE_Log(ICE_LOG_SUCCES, "Destroy Texture %d", texture_);
}

void ICE_Texture_Free(ICE_Texture * texture_)
{
	SDL_DestroyTexture(texture_->handle);
}

unsigned int ICE_Texture_GetW(ICE_ID texture_)
{
	return ASSET.texture_mngr.texture[texture_].w;
}

unsigned int ICE_Texture_GetH(ICE_ID texture_)
{
	return ASSET.texture_mngr.texture[texture_].h;
}

ICE_Texture * ICE_Texture_Get(ICE_ID texture_)
{
	return &ASSET.texture_mngr.texture[texture_];
}