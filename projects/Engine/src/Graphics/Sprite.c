#include "Sprite.h"
#include "../Core/State.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

extern ICE_Game GAME; 
extern ICE_Asset ASSET;

/* SPRITEMANAGER */

void ICE_SpriteManager_Init()
{
	ICE_SpriteManager sprite_manager = { 0 };
	sprite_manager.sprite_size = ICE_DEFAULT_SPRITEMNGR_SIZE;
	sprite_manager.sprite = ICE_Calloc(ICE_DEFAULT_SPRITEMNGR_SIZE, sizeof(ICE_Sprite));
	ASSET.sprite_mngr = sprite_manager;
	ICE_Log(ICE_LOG_SUCCES, "Init SpriteManager");
}

void ICE_SpriteManager_Destroy()
{
	for (ICE_ID i = 0; i < ASSET.sprite_mngr.sprite_contain; i++)
		ICE_Sprite_Destroy(i);

	ICE_Free(ASSET.sprite_mngr.sprite);
	ASSET.sprite_mngr.sprite = NULL;
	ICE_Log(ICE_LOG_SUCCES, "Free SpriteManager");
}

/* SPRITE */

ICE_Sprite ICE_Sprite_Build(ICE_TextureID texture_, ICE_Vect size_frame_sprite_)
{
	ICE_Sprite sprite = { 0 };
	ICE_Texture * texture_get = &ASSET.texture_mngr.texture[texture_];
	
	sprite.exist = ICE_True;
	sprite.have_texture_defined = ICE_True;
	sprite.texture_index = texture_;
	sprite.size_w = (unsigned int)size_frame_sprite_.x;
	sprite.size_h = (unsigned int)size_frame_sprite_.y;
	sprite.number_frame_w = (ICE_Index)texture_get->w / size_frame_sprite_.x;
	sprite.number_frame_h = (ICE_Index)texture_get->h / size_frame_sprite_.y;

	return sprite;
}

ICE_ID ICE_Sprite_Load(ICE_TextureID texture_, ICE_Vect size_frame_sprite_)
{
	ASSET.sprite_mngr.sprite[ASSET.sprite_mngr.sprite_contain] = ICE_Sprite_Build(texture_, size_frame_sprite_);
	ASSET.sprite_mngr.sprite_contain++;

	ASSET.sprite_mngr.sprite[ASSET.sprite_mngr.sprite_contain].index = ASSET.sprite_mngr.sprite_contain - 1;

	ICE_Log(ICE_LOG_SUCCES, "Create Sprite %d from Texture %d <%d*%d>", ASSET.sprite_mngr.sprite_contain - 1, texture_, ASSET.sprite_mngr.sprite[ASSET.sprite_mngr.sprite_contain-1].size_w, ASSET.sprite_mngr.sprite[ASSET.sprite_mngr.sprite_contain-1].size_h);

	if (ASSET.sprite_mngr.sprite_size <= ASSET.sprite_mngr.sprite_contain) 
	{
		ASSET.sprite_mngr.sprite = ICE_Realloc(ASSET.sprite_mngr.sprite, sizeof(ICE_Sprite)*(ASSET.sprite_mngr.sprite_size * 2));;
		ASSET.sprite_mngr.sprite_size *= 2;
	}

	return ASSET.sprite_mngr.sprite_contain - 1;
}

void ICE_Sprite_Clear(ICE_SpriteID sprite_)
{
	memset(&ASSET.sprite_mngr.sprite[sprite_], 0, sizeof(ICE_Sprite));
}

ICE_Sprite * ICE_Sprite_Get(ICE_SpriteID sprite_)
{
	return &ASSET.sprite_mngr.sprite[sprite_];
}

void ICE_Sprite_Destroy(ICE_SpriteID sprite_)
{

}

ICE_Uint64 ICE_Sprite_GetFrameQuantity(ICE_SpriteID _sprite)
{
	return ASSET.sprite_mngr.sprite[_sprite].number_frame_h * ASSET.sprite_mngr.sprite[_sprite].number_frame_w;
}