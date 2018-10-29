#include "Sprite.h"
#include "../Core/State.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

extern ICE_Game GAME; 
extern ICE_Asset ASSET;

/* SPRITEMANAGER */

ICE_ID ICE_SpriteManager_Insert()
{
	ICE_SpriteManager sprite_manager = { 0 };
	sprite_manager.sprite_size = ICE_DEFAULT_SPRITE_MNGR_SIZE;
	sprite_manager.sprite = ICE_Calloc(sprite_manager.sprite_size, sizeof(ICE_Sprite)); // Label Array

	ASSET.sprite_mngr_nb++;
	ASSET.sprite_mngr = ICE_Realloc(ASSET.sprite_mngr, ASSET.sprite_mngr_nb * sizeof(ICE_SpriteManager)); // Manager Array
	ASSET.sprite_mngr[ASSET.sprite_mngr_nb - 1] = sprite_manager;

	ICE_Log(ICE_LOG_SUCCES, "Create SpriteManager : %d", ASSET.sprite_mngr_nb - 1);
	return ASSET.sprite_mngr_nb - 1;
}

void ICE_SpriteManager_Destroy(const ICE_ID man)
{
	ICE_SpriteManager *manager = &ASSET.sprite_mngr[man];

	for (ICE_ID i = 0; i < manager->sprite_contain; i++)
	{
		//Free everything to free in Label
		ICE_Sprite_Destroy(&manager->sprite[i]);
	}

	ICE_Free(manager->sprite);
	ICE_Log(ICE_LOG_SUCCES, "Free SpriteManager : %d", man);
}

void ICE_SpriteManager_DestroyAll()
{
	ICE_SpriteManager *manager = ASSET.sprite_mngr;
	ICE_ID nb_manager = ASSET.sprite_mngr_nb;

	for (ICE_ID i = 0; i < nb_manager; i++)
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

	sprite.size_w = size_frame_sprite.x;
	sprite.size_h = size_frame_sprite.y;

	sprite.number_frame_w = texture->w / size_frame_sprite.x;
	sprite.number_frame_h = texture->h / size_frame_sprite.y;

	return sprite;
}

ICE_ID ICE_Sprite_Insert(const ICE_ID man, ICE_Texture * texture, ICE_Vect size_frame_sprite)
{
	// Insert sprite in array
	ASSET.sprite_mngr[man].sprite[ASSET.sprite_mngr[man].sprite_contain] = ICE_Sprite_Create(texture, size_frame_sprite);
	ASSET.sprite_mngr[man].sprite_contain++;

	ICE_Log(ICE_LOG_SUCCES, "SpriteManager]::[%d]::[Sprite]::[%d]::[Create", man, ASSET.sprite_mngr[man].sprite_contain - 1);

	// Test size to realloc more space
	if (ASSET.sprite_mngr[man].sprite_size <= ASSET.sprite_mngr[man].sprite_contain) {
		ICE_Sprite* tmp = ICE_Realloc(ASSET.sprite_mngr[man].sprite, sizeof(ICE_Sprite)*(ASSET.sprite_mngr[man].sprite_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "SpriteManager]::[%d]::[Resized]::[%d", man, ASSET.sprite_mngr[man].sprite_size * 2);
		ASSET.sprite_mngr[man].sprite = tmp;
		ASSET.sprite_mngr[man].sprite_size *= 2;
	}

	return ASSET.sprite_mngr[man].sprite_contain - 1;
}

void ICE_Sprite_Clear(ICE_Sprite * label)
{
	memset(label, 0, sizeof(ICE_Sprite));
}

void ICE_Sprite_Destroy(ICE_Sprite * ptr)
{
	
}

ICE_Sprite * ICE_Sprite_Get(ICE_ID man, ICE_ID nb)
{
	return &ASSET.sprite_mngr[man].sprite[nb];
}

ICE_Uint64 ICE_Sprite_GetFrameQuantity(ICE_Sprite * _sprite)
{
	return _sprite->number_frame_h * _sprite->number_frame_w;
}