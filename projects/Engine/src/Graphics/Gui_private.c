#include "Gui_private.h"
#include "Gui.h"
#include "../Core/TypesCore.h"
#include "../Graphics/TypesGraphics.h"
#include "../Graphics/Texture.h"
#include "Texture_private.h"
#include "../Framework/Log.h"
#include "../Framework/Memory_.h"

extern ICE_Game GAME;
extern ICE_Core CORE;
extern ICE_Asset ASSET;
/* GUIMANAGER */

void ICE_GuiManager_Init(ICE_State* state)
{
	if (!state)
		state = GAME.current;

	ICE_GuiManager gui_manager = { 0 };
	gui_manager.gui_size = ICE_DEFAULT_GUI_MNGR_SIZE;
	gui_manager.gui = ICE_Calloc(gui_manager.gui_size, sizeof(ICE_Gui)); // Label Array

	state->object.gui_mngr = gui_manager;

	ICE_Log(ICE_LOGTYPE_SUCCES, "Create GuiManager");
}

void ICE_GuiManager_Destroy(ICE_State * state)
{
	if (!state)
		state = GAME.current;

	ICE_GuiManager *manager = &state->object.gui_mngr;

	for (ICE_ID i = 0; i < manager->gui_contain; i++)
		ICE_Gui_Destroy(&manager->gui[i]);

	ICE_Free(manager->gui);
	ICE_Log(ICE_LOGTYPE_SUCCES, "Destroy GuiManager");
}

ICE_Gui ICE_Gui_Build(ICE_Box box, ICE_TextureID nb_texture)
{
	ICE_Gui gui = { 0 };

	gui.type = ICE_GUITYPE_RECTANGLE;

	if(nb_texture == (ICE_TextureID)-1)
		gui.have_texture_defined = ICE_False;
	else
		gui.have_texture_defined = ICE_True;

	gui.active = ICE_True;
	gui.box = box;
	gui.texture_index = nb_texture;

	return gui;
}

void ICE_Gui_UpdateTexture(ICE_State* state_, ICE_ID gui)
{
	if (state_ == 0)
		state_ = GAME.current;

	ICE_Texture texture = { 0 };
	texture.handle = SDL_CreateTexture(CORE.window.render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, (int)state_->object.gui_mngr.gui[gui].box.w, (int)state_->object.gui_mngr.gui[gui].box.h);
	SDL_SetRenderTarget(CORE.window.render, texture.handle);
	SDL_SetTextureBlendMode(texture.handle, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(CORE.window.render, 0, 0, 0, 0);
	SDL_RenderClear(CORE.window.render);
	ICE_Box box2 = state_->object.gui_mngr.gui[gui].box;
	box2.x = 0; box2.y = 0;

	// TYPE DRAW
	if(state_->object.gui_mngr.gui[gui].type == ICE_GUITYPE_RECTANGLE)
		if(state_->object.gui_mngr.gui[gui].texture_index == (ICE_TextureID)-1 || !state_->object.gui_mngr.gui[gui].have_texture_defined)
			ICE_Gui_Rect(&ASSET.texture_gui_default, box2);
		else
			ICE_Gui_Rect(ICE_Texture_Get(state_->object.gui_mngr.gui[gui].texture_index), box2);

	if (state_->object.gui_mngr.gui[gui].type == ICE_GUITYPE_IMAGE)
		ICE_Texture_RenderEx(
			ICE_Texture_Get(state_->object.gui_mngr.gui[gui].texture_index),
			NULL,
			&state_->object.gui_mngr.gui[gui].box,
			0
		);
	
	SDL_SetRenderTarget(CORE.window.render, NULL);
	if (state_->object.gui_mngr.gui[gui].texture_cache.handle)
		SDL_DestroyTexture(state_->object.gui_mngr.gui[gui].texture_cache.handle);
	state_->object.gui_mngr.gui[gui].texture_cache = texture;
}

// Deprecated
// Unoptimized function
void ICE_Gui_Rect(ICE_Texture * texture, ICE_Box rect)
{
	ICE_Box src, dst;
	int wtext3 = texture->w / 3;
	int htext3 = texture->h / 3;

	src.w = wtext3; src.h = htext3;

	// CENTER

	src.x = wtext3; src.y = htext3;
	dst.x = rect.x + wtext3; dst.y = rect.y + htext3;
	dst.w = rect.w - (wtext3) * 2; dst.h = rect.h - (htext3) * 2;

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.w = wtext3; dst.h = htext3;

	// UPMID

	src.x = wtext3; src.y = 0; dst.y = rect.y; dst.x = rect.x + wtext3;
	dst.w = rect.w - (wtext3 * 2);

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.w = wtext3; dst.h = htext3;

	// LEFTMID

	src.x = 0; src.y = htext3;
	dst.x = rect.x; dst.y = rect.y + htext3;
	dst.h = rect.h - (htext3 * 2);

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.w = wtext3; dst.h = htext3;

	// RIGHT MID

	src.x = wtext3 * 2; src.y = htext3;
	dst.x = rect.x + rect.w - wtext3; dst.y = rect.y + htext3;
	dst.h = rect.h - (htext3 * 2);

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.w = wtext3; dst.h = htext3;


	// DOWNMID

	src.x = wtext3; src.y = htext3 * 2; dst.y = rect.y + rect.h - htext3; dst.x = rect.x + wtext3;
	dst.w = rect.w - (wtext3 * 2);

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.w = wtext3; dst.h = htext3;

	// UPLEFT

	src.x = 0; src.y = 0;
	dst.x = rect.x; dst.y = rect.y;

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.w = wtext3;

	// UPRIGHT

	src.x = wtext3 * 2; src.y = 0;
	dst.x = rect.x + rect.w - wtext3; dst.y = rect.y;

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	dst.h = htext3;

	// DOWNLEFT

	src.x = 0; src.y = htext3 * 2;
	dst.x = rect.x; dst.y = rect.y + rect.h - htext3;

	ICE_Texture_RenderEx(texture, &src, &dst, 0);

	// DOWNRIGHT

	src.x = wtext3 * 2; src.y = htext3 * 2;
	dst.x = rect.x + rect.w - wtext3; dst.y = rect.y + rect.h - htext3;

	ICE_Texture_RenderEx(texture, &src, &dst, 0);
}