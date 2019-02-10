#include "Texture.h"

#include "TypesGraphics.h"
#include "../Core/TypesCore.h"
#include "../Framework/Log.h"

#include "Texture_private.h"
#include "../Framework/Memory_.h"
#include "../External/physfs/physfsrwops.h"
#include "../Core/Asset.h"

extern ICE_Asset ASSET;
extern ICE_Game GAME;

ICE_ID last_loaded_texture = (ICE_ID)-1;

/* TEXTUREMANAGER */

void ICE_TextureManager_Init() 
{
	ICE_TextureManager texture_manager = { 0 };
	texture_manager.texture_size = ICE_DEFAULT_TEXTUREMNGR_SIZE;
	texture_manager.texture = ICE_Calloc(ICE_DEFAULT_TEXTUREMNGR_SIZE, sizeof(ICE_Texture));
	ASSET.texture_mngr = texture_manager;
	ICE_Log(ICE_LOGTYPE_SUCCES, "Init TextureManager");
}

void ICE_TextureManager_Destroy()
{
	for (ICE_ID i = 0; i < ASSET.texture_mngr.texture_contain; i++)
		ICE_Texture_Destroy(i);

	ICE_Free(ASSET.texture_mngr.texture);
	ASSET.texture_mngr.texture = NULL;
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

		for (ICE_EntityID i = 0; i < ASSET.texture_mngr.texture_contain; i++)
		{
			if (ASSET.texture_mngr.texture[i].exist == ICE_False)
			{
				avaible_slot = i;
				no_avaible_slot = ICE_True;
				break;
			}
		}
		if (!no_avaible_slot)
		{
			avaible_slot = ASSET.texture_mngr.texture_contain;
			ASSET.texture_mngr.texture_contain++;
		}

		ASSET.texture_mngr.texture[avaible_slot] = temp;
		ASSET.texture_mngr.texture[avaible_slot].id = avaible_slot;

		//ICE_Log(ICE_LOGTYPE_SUCCES, "Load Texture %d succes", avaible_slot);
		
		if (ASSET.texture_mngr.texture_size <= ASSET.texture_mngr.texture_contain) 
		{
			ASSET.texture_mngr.texture = ICE_Realloc(ASSET.texture_mngr.texture, sizeof(ICE_Texture)*(ASSET.texture_mngr.texture_size * 2));
			ASSET.texture_mngr.texture_size *= 2;
		}

		last_loaded_texture = avaible_slot;
		return avaible_slot;
	}
	return (ICE_TextureID)-1; // ERROR ID
}

void ICE_Texture_Destroy(ICE_ID texture_) 
{
	ASSET.texture_mngr.texture[texture_].exist = ICE_False;
	SDL_DestroyTexture(ASSET.texture_mngr.texture[texture_].handle);
	ICE_Log(ICE_LOGTYPE_SUCCES, "Destroy Texture %d", texture_);
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