#include "Sprite.h"
#include "../Core/State.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

extern ICE_Game game; 
extern ICE_Asset asset;

/* SPRITEMANAGER */

ICE_Index ICE_SpriteManager_Insert()
{
	ICE_SpriteManager sprite_manager = { 0 };
	sprite_manager.sprite_size = ICE_DEFAULT_SPRITE_MNGR_SIZE;
	sprite_manager.sprite = ICE_Calloc(sprite_manager.sprite_size, sizeof(ICE_Sprite)); // Label Array

	asset.sprite_mngr_nb++;
	asset.sprite_mngr = ICE_Realloc(asset.sprite_mngr, asset.sprite_mngr_nb * sizeof(ICE_SpriteManager)); // Manager Array
	asset.sprite_mngr[asset.sprite_mngr_nb - 1] = sprite_manager;

	ICE_Log(ICE_LOG_SUCCES, "SpriteManager]::[%d]::[Create", asset.sprite_mngr_nb - 1);
	return asset.sprite_mngr_nb - 1;
}

void ICE_SpriteManager_Destroy(const ICE_Index man)
{
	ICE_SpriteManager *manager = &asset.sprite_mngr[man];

	for (ICE_Index i = 0; i < manager->sprite_contain; i++)
	{
		//Free everything to free in Label
		ICE_Sprite_Destroy(&manager->sprite[i]);
	}

	ICE_Free(manager->sprite);
	ICE_Log(ICE_LOG_SUCCES, "SpriteManager]::[%d]::[Free", man);
}

void ICE_SpriteManager_DestroyAll()
{
	ICE_SpriteManager *manager = asset.sprite_mngr;
	ICE_Index nb_manager = asset.sprite_mngr_nb;

	for (ICE_Index i = 0; i < nb_manager; i++)
	{
		if (!manager[i].isFree)
		{
			ICE_SpriteManager_Destroy(i);
			manager[i].isFree = ICE_True;
		}
	}
	free(manager);
}

/* SPRITE */

ICE_Sprite ICE_Sprite_Create(ICE_Texture * texture, ICE_Vect size_frame_sprite)
{
	ICE_Sprite sprite = { 0 };

	sprite.exist = ICE_True;
	
	sprite.have_texture_defined = ICE_True;
	sprite.texturemanager_index = texture->manager_index;
	sprite.texture_index = texture->index;

	sprite.size_w = asset.texture_mngr[sprite.texturemanager_index].texture[sprite.texture_index].w/size_frame_sprite.x;
	sprite.size_h = asset.texture_mngr[sprite.texturemanager_index].texture[sprite.texture_index].h/size_frame_sprite.y;

	return sprite;
}

ICE_Index ICE_Sprite_Insert(const ICE_Index man, ICE_Texture * texture, ICE_Vect size_frame_sprite)
{
	// Insert sprite in array
	asset.sprite_mngr[man].sprite[asset.sprite_mngr[man].sprite_contain] = ICE_Sprite_Create(texture, size_frame_sprite);
	asset.sprite_mngr[man].sprite_contain++;

	ICE_Log(ICE_LOG_SUCCES, "SpriteManager]::[%d]::[Sprite]::[%d]::[Create", man, asset.sprite_mngr[man].sprite_contain - 1);

	// Test size to realloc more space
	if (asset.sprite_mngr[man].sprite_size <= asset.sprite_mngr[man].sprite_contain) {
		ICE_Sprite* tmp = ICE_Realloc(asset.sprite_mngr[man].sprite, sizeof(ICE_Sprite)*(asset.sprite_mngr[man].sprite_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "SpriteManager]::[%d]::[Resized]::[%d", man, asset.sprite_mngr[man].sprite_size * 2);
		asset.sprite_mngr[man].sprite = tmp;
		asset.sprite_mngr[man].sprite_size *= 2;
	}

	return asset.sprite_mngr[man].sprite_contain - 1;
}

void ICE_Sprite_Clear(ICE_Sprite * label)
{
	memset(label, 0, sizeof(ICE_Sprite));
}

void ICE_Sprite_Destroy(ICE_Sprite * ptr)
{
	
}

ICE_Sprite * ICE_Sprite_Get(ICE_Index man, ICE_Index nb)
{
	return &asset.sprite_mngr[man].sprite[nb];
}