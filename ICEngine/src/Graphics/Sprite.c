#include "Sprite.h"
#include "../Core/State.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

extern ICE_Game game; 
extern ICE_Asset asset;

/* SPRITEMANAGER */

size_t ICE_SpriteManager_Insert(ICE_State* state)
{
	if (!state)
		state = game.current;

	ICE_SpriteManager sprite_manager = { 0 };
	sprite_manager.sprite_size = ICE_DEFAULT_SPRITE_MNGR_SIZE;
	sprite_manager.sprite = ICE_Calloc(sprite_manager.sprite_size, sizeof(ICE_Sprite)); // Label Array

	state->object.sprite_mngr_nb++;
	state->object.sprite_mngr = ICE_Realloc(state->object.sprite_mngr, state->object.sprite_mngr_nb * sizeof(ICE_SpriteManager)); // Manager Array
	state->object.sprite_mngr[state->object.sprite_mngr_nb - 1] = sprite_manager;

	ICE_Log(ICE_LOG_SUCCES, "SpriteManager]::[%d]::[Create", state->object.sprite_mngr_nb - 1);
	return state->object.sprite_mngr_nb - 1;
}

void ICE_SpriteManager_Destroy(ICE_State * state, const size_t man)
{
	if (!state)
		state = game.current;

	ICE_SpriteManager *manager = &state->object.sprite_mngr[man];

	for (size_t i = 0; i < manager->sprite_contain; i++)
	{
		//Free everything to free in Label
		ICE_Sprite_Destroy(&manager->sprite[i]);
	}

	ICE_Free(manager->sprite);
	ICE_Log(ICE_LOG_SUCCES, "SpriteManager]::[%d]::[Free", man);
}

void ICE_SpriteManager_DestroyAll(ICE_State * state)
{
	if (!state)
		state = game.current;

	ICE_SpriteManager *manager = state->object.sprite_mngr;
	size_t nb_manager = state->object.sprite_mngr_nb;

	for (size_t i = 0; i < nb_manager; i++)
	{
		if (!manager[i].isFree)
		{
			ICE_SpriteManager_Destroy(state, i);
			manager[i].isFree = ICE_True;
		}
	}
	free(manager);
}

/* SPRITE */

ICE_Sprite ICE_Sprite_Create(size_t man_texture, size_t nb_texture, unsigned int number_sprite_w, unsigned int number_sprite_h)
{
	ICE_Sprite sprite = { 0 };

	sprite.exist = ICE_True;

	sprite.have_texture_defined = ICE_True;
	sprite.texturemanager_index = man_texture;
	sprite.texture_index = nb_texture;

	sprite.size_w = asset.texture_mngr[man_texture].texture[nb_texture].w/number_sprite_w;
	sprite.size_h = asset.texture_mngr[man_texture].texture[nb_texture].h/number_sprite_h;

	return sprite;
}

size_t ICE_Sprite_Insert(ICE_State* state, const size_t man, size_t texture_manager,
						 size_t texture_nb, unsigned int number_sprite_w, unsigned int number_sprite_h)
{
	if (!state)
		state = game.current;

	// Insert sprite in array
	state->object.sprite_mngr[man].sprite[state->object.sprite_mngr[man].sprite_contain] = ICE_Sprite_Create(texture_manager, texture_nb, number_sprite_w, number_sprite_h);
	state->object.sprite_mngr[man].sprite_contain++;

	ICE_Log(ICE_LOG_SUCCES, "SpriteManager]::[%d]::[Sprite]::[%d]::[Create", texture_manager, state->object.sprite_mngr[man].sprite_contain - 1);

	// Test size to realloc more space
	if (state->object.sprite_mngr[man].sprite_size <= state->object.sprite_mngr[man].sprite_contain) {
		ICE_Sprite* tmp = ICE_Realloc(state->object.sprite_mngr[man].sprite, sizeof(ICE_Sprite)*(state->object.sprite_mngr[man].sprite_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "SpriteManager]::[%d]::[Resized]::[%d", man, state->object.sprite_mngr[man].sprite_size * 2);
		state->object.sprite_mngr[man].sprite = tmp;
		state->object.sprite_mngr[man].sprite_size *= 2;
	}

	return state->object.sprite_mngr[man].sprite_contain - 1;
}

void ICE_Sprite_Clear(ICE_Sprite * label)
{
	memset(label, 0, sizeof(ICE_Sprite));
}
void ICE_Sprite_Destroy(ICE_Sprite * ptr)
{

}