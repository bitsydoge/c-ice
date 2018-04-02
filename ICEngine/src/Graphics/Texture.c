#include "Texture.h"

#include "TypesGraphics.h"
#include "../Core/TypesCore.h"
#include "../Framework/Std_.h"
#include "../Framework/Log.h"

#include <string.h>
#include "Texture_private.h"
#include "../Framework/Memory_.h"
#include "../Core/Converter_private.h"

extern ICE_Asset asset;
extern ICE_Game game;

unsigned int ICE_TextureManager_Insert() 
{
	ICE_TextureManager texture_manager = { 0 };
	texture_manager.texture_size = ICE_DEFAULT_TEXTURE_SIZE;
	texture_manager.texture = ICE_Calloc(texture_manager.texture_size, sizeof(ICE_Texture));
	
	asset.texture_mngr_nb++;
	asset.texture_mngr = ICE_Realloc(asset.texture_mngr, asset.texture_mngr_nb * sizeof(ICE_TextureManager));
	asset.texture_mngr[asset.texture_mngr_nb - 1] = texture_manager;
	
	ICE_Log(ICE_LOG_SUCCES, "TextureManager]::[%d]::[Create", asset.texture_mngr_nb - 1);
	return asset.texture_mngr_nb - 1;
}

void ICE_TextureManager_Destroy(const unsigned int man)
{
	ICE_TextureManager * manager = &asset.texture_mngr[man];
	
	for (unsigned int i = 0; i < asset.texture_mngr[man].texture_contain; i++)
		ICE_Texture_Destroy(ICE_Texture_Get(man, i));

	ICE_Free(manager->texture);
	ICE_Log(ICE_LOG_SUCCES, "TextureManager]::[%d]::[Free", man);
}

void ICE_TextureManager_DestroyAll()
{
	ICE_TextureManager *manager = asset.texture_mngr;
	unsigned int nb_manager = asset.texture_mngr_nb;

	for (unsigned int i = 0; i < nb_manager; i++)
	{
		if (!manager[i].isFree)
		{
			ICE_TextureManager_Destroy(i);
			manager[i].isFree = ICE_True;
		}
	}
	free(manager);
}

unsigned int ICE_Texture_Insert(int manager, char* path) 
{
	ICE_Texture *text = ICE_Texture_Load(path);
	text->exist = 1;

	SDL_QueryTexture(text->handle, NULL, NULL, &text->w, &text->h);
	asset.texture_mngr[manager].texture[asset.texture_mngr[manager].texture_contain] = *text;
	asset.texture_mngr[manager].texture_contain++;

	if (asset.texture_mngr[manager].texture_size <= asset.texture_mngr[manager].texture_contain) {
		asset.texture_mngr[manager].texture = realloc(asset.texture_mngr[manager].texture, sizeof(ICE_Texture)*(asset.texture_mngr[manager].texture_size * 2));
		asset.texture_mngr[manager].texture_size *= 2;
	}
	free(text);
	return asset.texture_mngr->texture_contain - 1;
}

void ICE_Texture_Destroy(ICE_Texture *tex) {
	SDL_DestroyTexture(tex->handle);
}

ICE_Texture * ICE_Texture_Get(unsigned int man, unsigned int nb)
{
	return &asset.texture_mngr[man].texture[nb];
}