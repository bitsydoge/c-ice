#include "Texture.h"

#include "TypesGraphics.h"
#include "../Core/TypesCore.h"
#include "../Framework/Log.h"

#include "Texture_private.h"
#include "../Framework/Memory_.h"

extern ICE_Asset ASSET;
extern ICE_Game GAME;

void ICE_TextureManager_Init() 
{
	ICE_TextureManager texture_manager = { 0 };
	texture_manager.texture_size = ICE_DEFAULT_TEXTURE_SIZE;
	texture_manager.texture = ICE_Calloc(texture_manager.texture_size, sizeof(ICE_Texture));
	ASSET.texture_mngr = texture_manager;
	ICE_Log(ICE_LOG_SUCCES, "Create TextureManager");
}

void ICE_TextureManager_Destroy()
{
	for (ICE_Id i = 0; i < ASSET.texture_mngr.texture_contain; i++)
		ICE_Texture_Destroy(i);

	ICE_Free(ASSET.texture_mngr.texture);
	ICE_Log(ICE_LOG_SUCCES, "Destroy TextureManager");
}

ICE_Id ICE_Texture_Load(char* path_) 
{
	ICE_Texture *text = ICE_Texture_LoadFromFile(path_);
	text->exist = 1;
	int w, h;
	SDL_QueryTexture(text->handle, NULL, NULL, &w, &h);
	text->w = w; text->h = h;
	text->index = ASSET.texture_mngr.texture_contain;
	ASSET.texture_mngr.texture[ASSET.texture_mngr.texture_contain] = *text;
	SDL_SetTextureBlendMode(text->handle, SDL_BLENDMODE_BLEND);

	ASSET.texture_mngr.texture_contain++;
	
	ICE_Log(ICE_LOG_SUCCES, "Load texture %d from Path=\"%s\"", ASSET.texture_mngr.texture_contain - 1, path_);
	
	if (ASSET.texture_mngr.texture_size <= ASSET.texture_mngr.texture_contain) {
		ASSET.texture_mngr.texture = realloc(ASSET.texture_mngr.texture, sizeof(ICE_Texture)*(ASSET.texture_mngr.texture_size * 2));
		ASSET.texture_mngr.texture_size *= 2;
	}
	free(text);

	// Return ID of the loaded Texture
	return ASSET.texture_mngr.texture_contain - 1;
}

void ICE_Texture_Destroy(ICE_Id texture_) 
{
	SDL_DestroyTexture(ASSET.texture_mngr.texture[texture_].handle);
}

unsigned int ICE_Texture_GetW(ICE_Id texture_)
{
	return ASSET.texture_mngr.texture[texture_].w;
}

unsigned int ICE_Texture_GetH(ICE_Id texture_)
{
	return ASSET.texture_mngr.texture[texture_].h;
}