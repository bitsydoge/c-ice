#include "Texture.h"

#include "TypesGraphics.h"
#include "../Core/TypesCore.h"
#include "../Framework/Log.h"

#include "Texture_private.h"
#include "../Framework/Memory_.h"

extern ICE_Asset ASSET;
extern ICE_Game GAME;

ICE_Id ICE_TextureManager_Insert() 
{
	ICE_TextureManager texture_manager = { 0 };
	texture_manager.texture_size = ICE_DEFAULT_TEXTURE_SIZE;
	texture_manager.texture = ICE_Calloc(texture_manager.texture_size, sizeof(ICE_Texture));
	
	ASSET.texture_mngr_nb++;
	ASSET.texture_mngr = ICE_Realloc(ASSET.texture_mngr, ASSET.texture_mngr_nb * sizeof(ICE_TextureManager));
	ASSET.texture_mngr[ASSET.texture_mngr_nb - 1] = texture_manager;

	ICE_Log(ICE_LOG_SUCCES, "Create TextureManager : %d", ASSET.texture_mngr_nb - 1);
	return ASSET.texture_mngr_nb - 1;
}

void ICE_TextureManager_Destroy(const ICE_Id man)
{
	ICE_TextureManager * manager = &ASSET.texture_mngr[man];
	
	for (ICE_Id i = 0; i < manager->texture_contain; i++)
		ICE_Texture_Destroy(ICE_Texture_Get(man, i));

	ICE_Free(manager->texture);
	ICE_Log(ICE_LOG_SUCCES, "Free TextureManager : %d", man);
}

void ICE_TextureManager_DestroyAll()
{
	ICE_TextureManager *manager = ASSET.texture_mngr;
	ICE_Id nb_manager = ASSET.texture_mngr_nb;

	for (ICE_Id i = 0; i < nb_manager; i++)
	{
		if (!manager[i].isFree)
		{
			ICE_TextureManager_Destroy(i);
			manager[i].isFree = ICE_True;
		}
	}
	free(manager);
}

ICE_Id ICE_Texture_Load(ICE_Id manager, char* path) 
{
	ICE_Texture *text = ICE_Texture_LoadFromFile(path);
	text->exist = 1;
	text->manager_index = manager;
	int w, h;
	SDL_QueryTexture(text->handle, NULL, NULL, &w, &h);
	text->w = w; text->h = h;
	text->index = ASSET.texture_mngr->texture_contain;
	ASSET.texture_mngr[manager].texture[ASSET.texture_mngr[manager].texture_contain] = *text;
	SDL_SetTextureBlendMode(text->handle, SDL_BLENDMODE_BLEND);

	ASSET.texture_mngr[manager].texture_contain++;
	
	ICE_Log(ICE_LOG_SUCCES, "Texture]::[%d]::[Load]::[Path=\"%s\"", ASSET.texture_mngr->texture_contain - 1, path);
	if (ASSET.texture_mngr[manager].texture_size <= ASSET.texture_mngr[manager].texture_contain) {
		ASSET.texture_mngr[manager].texture = realloc(ASSET.texture_mngr[manager].texture, sizeof(ICE_Texture)*(ASSET.texture_mngr[manager].texture_size * 2));
		ASSET.texture_mngr[manager].texture_size *= 2;
	}
	free(text);

	return ASSET.texture_mngr->texture_contain - 1;
}

void ICE_Texture_Destroy(ICE_Texture * tex) {
	SDL_DestroyTexture(tex->handle);
}

ICE_Texture * ICE_Texture_Get(ICE_Id man, ICE_Id nb)
{
	return &ASSET.texture_mngr[man].texture[nb];
}

unsigned int ICE_Texture_GetW(ICE_Texture * text)
{
	return text->w;
}

unsigned int ICE_Texture_GetH(ICE_Texture * text)
{
	return text->h;
}