#include "Sprite.h"
#include "../Core/State.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

extern ICE_Game GAME; 
extern ICE_Asset ASSET;

/* SPRITEMANAGER */

void ICE_SpriteManager_Insert()
{
	ICE_SpriteManager sprite_manager = { 0 };
	sprite_manager.sprite_size = ICE_DEFAULT_SPRITE_MNGR_SIZE;
	sprite_manager.sprite = ICE_Calloc(sprite_manager.sprite_size, sizeof(ICE_Sprite)); // Label Array
	ASSET.sprite_mngr = sprite_manager;
	ICE_Log(ICE_LOG_SUCCES, "Create SpriteManager");
}

void ICE_SpriteManager_Destroy()
{
	for (ICE_Id i = 0; i < ASSET.sprite_mngr.sprite_contain; i++)
	{
		//Free everything to free in Label
		ICE_Sprite_Destroy(i);
	}
	ICE_Free(ASSET.sprite_mngr.sprite);
	ICE_Log(ICE_LOG_SUCCES, "Destroy SpriteManager : %d");
}

/* SPRITE */

ICE_Sprite ICE_Sprite_Create(ICE_Id texture_, ICE_Vect size_frame_sprite_)
{
	ICE_Texture * texture_get = &ASSET.texture_mngr.texture[texture_];
	ICE_Sprite sprite = { 0 };

	sprite.exist = ICE_True;
	
	sprite.have_texture_defined = ICE_True;
	sprite.texture_index = texture_get->index;

	sprite.size_w = size_frame_sprite_.x;
	sprite.size_h = size_frame_sprite_.y;

	sprite.number_frame_w = texture_get->w / size_frame_sprite_.x;
	sprite.number_frame_h = texture_get->h / size_frame_sprite_.y;

	return sprite;
}

ICE_Id ICE_Sprite_Insert(ICE_Id texture_, ICE_Vect size_frame_sprite_)
{
	// Insert sprite in array
	ASSET.sprite_mngr.sprite[ASSET.sprite_mngr.sprite_contain] = ICE_Sprite_Create(texture_, size_frame_sprite_);
	ASSET.sprite_mngr.sprite_contain++;

	ICE_Log(ICE_LOG_SUCCES, "Create Sprite %d from texture %d", ASSET.sprite_mngr.sprite_contain - 1, texture_);

	// Test size to realloc more space
	if (ASSET.sprite_mngr.sprite_size <= ASSET.sprite_mngr.sprite_contain) {
		ICE_Sprite* tmp = ICE_Realloc(ASSET.sprite_mngr.sprite, sizeof(ICE_Sprite)*(ASSET.sprite_mngr.sprite_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "SpriteManager Resized to %d", ASSET.sprite_mngr.sprite_size * 2);
		ASSET.sprite_mngr.sprite = tmp;
		ASSET.sprite_mngr.sprite_size *= 2;
	}

	return ASSET.sprite_mngr.sprite_contain - 1;
}

void ICE_Sprite_Clear(ICE_Id sprite_)
{
	memset(&ASSET.sprite_mngr.sprite[sprite_], 0, sizeof(ICE_Sprite));
}

ICE_Sprite * ICE_Sprite_Get(ICE_Id sprite_)
{
	return &ASSET.sprite_mngr.sprite[sprite_];
}

void ICE_Sprite_Destroy(ICE_Id sprite_)
{
	ICE_Free(&ASSET.sprite_mngr.sprite[sprite_]);
}

ICE_Uint64 ICE_Sprite_GetFrameQuantity(ICE_Id _sprite)
{
	return ASSET.sprite_mngr.sprite[_sprite].number_frame_h * ASSET.sprite_mngr.sprite[_sprite].number_frame_w;
}