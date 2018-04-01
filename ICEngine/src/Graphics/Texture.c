#include "Texture.h"

#include "TypesGraphics.h"
#include "../Core/TypesCore.h"
#include "../Framework/Std_.h"
#include "../Framework/Log.h"

#include <string.h>
#include "Texture_private.h"

extern ICE_Asset asset;

unsigned int ICE_TextureManager_Create() {
	ICE_TextureManager texture_manager = { 0 };
	texture_manager.texture_size = ICE_DEFAULT_TEXTURE_SIZE;
	texture_manager.texture = calloc(texture_manager.texture_size, sizeof(ICE_Texture));
	asset.texture_mngr_nb++;
	asset.texture_mngr = realloc(asset.texture_mngr, asset.texture_mngr_nb * sizeof(ICE_TextureManager));
	asset.texture_mngr[asset.texture_mngr_nb - 1] = texture_manager;
	printf("TextureManager number %d created \n", asset.texture_mngr_nb - 1);
	return asset.texture_mngr_nb - 1;
}

unsigned int ICE_Texture_Create(int manager, char* path) {

	char path2[500]; strcpy(path2, path);
	char* ext = icestd_ext(path2);
	icestd_sup(ext);

	ICE_Texture *text = ICE_LoadImage(path);
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

ICE_Texture * ICE_Texture_Get(unsigned int man, unsigned int nb)
{
	return &asset.texture_mngr[man].texture[nb];
}