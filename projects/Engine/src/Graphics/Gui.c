#include "Gui.h"

#include "Gui_private.h"

#include "../Maths/TypesMaths.h"
#include "Texture_private.h"
#include "../Core/TypesCore.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "Texture.h"

extern ICE_Game GAME;

/* GUI */

ICE_ID ICE_Gui_Create(ICE_State * state_, const ICE_Box box_, ICE_GuiType types_)
{
	if (!state_)
		state_ = GAME.current;

	// Insert label in array
	state_->object.gui_mngr.gui[state_->object.gui_mngr.gui_contain] = ICE_Gui_Build(box_, types_);
	state_->object.gui_mngr.gui_contain++;

	ICE_Log(ICE_LOGTYPE_SUCCES, "Create Gui %d ", state_->object.gui_mngr.gui_contain-1);

	// Test size to realloc more space
	if (state_->object.gui_mngr.gui_size <= state_->object.gui_mngr.gui_contain) 
	{
		ICE_Gui* tmp = ICE_Realloc(state_->object.gui_mngr.gui, sizeof(ICE_Gui)*(state_->object.gui_mngr.gui_size * 2));
		state_->object.gui_mngr.gui = tmp;
		state_->object.gui_mngr.gui_size *= 2;
	}

	ICE_Gui_UpdateTexture(state_, state_->object.gui_mngr.gui_contain - 1);
	return state_->object.gui_mngr.gui_contain - 1;
}

void ICE_Gui_Clear(ICE_Gui * label_)
{
	ICE_Texture temp = label_->texture_cache;
	memset(label_, 0, sizeof(ICE_Gui)); 
	label_->texture_cache = temp;
}
void ICE_Gui_Destroy(ICE_Gui * ptr)
{
	ICE_Texture_Free(&ptr->texture_cache);
}

/* GUI GET */

ICE_Gui * ICE_Gui_Get(ICE_State *state, ICE_GuiID gui)
{
	if (!state)
		state = GAME.current;

	return &state->object.gui_mngr.gui[gui];
}

/* GUI SET */

void ICE_Gui_SetTexture(ICE_Gui * gui, int texture_man, int texture)
{
	gui->texture_index = texture;
	gui->texturemanager_index = texture_man;
	gui->have_texture_defined = ICE_True;
}

void ICE_Gui_SetBox(ICE_Gui * gui, ICE_Box box)
{
	gui->box = box;
}

void ICE_Gui_SetPos(ICE_Gui * gui, ICE_Vect pos)
{
	gui->box.x = pos.x;
	gui->box.y = pos.y;
}

void ICE_Gui_SetSize(ICE_Gui * gui, ICE_Vect vect)
{
	gui->box.w = vect.x;
	gui->box.h = vect.y;
}

void ICE_Gui_SetType(ICE_Gui * gui, ICE_GuiType type)
{
	gui->type = type;
}

