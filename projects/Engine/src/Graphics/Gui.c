#include "Gui.h"

#include "Gui_private.h"

#include "../Maths/TypesMaths.h"
#include "Texture_private.h"
#include "../Core/TypesCore.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

extern ICE_Game GAME;

/* GUI */

ICE_ID ICE_Gui_Create(ICE_State * state, const ICE_Box box, ICE_TextureID texture_nb)
{
	if (!state)
		state = GAME.current;

	// Insert label in array
	state->object.gui_mngr.gui[state->object.gui_mngr.gui_contain] = ICE_Gui_Build(box, texture_nb);
	state->object.gui_mngr.gui_contain++;

	ICE_Log(ICE_LOG_SUCCES, "Create Gui %d ", state->object.gui_mngr.gui_contain-1);

	// Test size to realloc more space
	if (state->object.gui_mngr.gui_size <= state->object.gui_mngr.gui_contain) 
	{
		ICE_Gui* tmp = ICE_Realloc(state->object.gui_mngr.gui, sizeof(ICE_Gui)*(state->object.gui_mngr.gui_size * 2));
		state->object.gui_mngr.gui = tmp;
		state->object.gui_mngr.gui_size *= 2;
	}

	ICE_Gui_UpdateTexture(state, state->object.gui_mngr.gui_contain - 1);
	return state->object.gui_mngr.gui_contain - 1;
}

void ICE_Gui_Clear(ICE_Gui * label)
{
	ICE_Texture temp = label->texture_cache;
	memset(label, 0, sizeof(ICE_Gui)); 
	label->texture_cache = temp;
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
