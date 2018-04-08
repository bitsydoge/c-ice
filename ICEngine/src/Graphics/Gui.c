#include "Gui.h"

#include "Gui_private.h"

#include "../Maths/TypesMaths.h"
#include "Texture_private.h"
#include "../Core/TypesCore.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "../ICE.h"

extern ICE_Game game;

/* GUIMANAGER */

unsigned int ICE_GuiManager_Insert(ICE_State * state)
{
	if (!state)
		state = game.state_mngr.current;

	ICE_GuiManager gui_manager = { 0 };
	gui_manager.gui_size = ICE_DEFAULT_GUI_MNGR_SIZE;
	gui_manager.gui = ICE_Calloc(gui_manager.gui_size, sizeof(ICE_Gui)); // Label Array

	state->object.gui_mngr_nb++;
	state->object.gui_mngr = ICE_Realloc(state->object.gui_mngr, state->object.gui_mngr_nb * sizeof(ICE_GuiManager)); // Manager Array
	state->object.gui_mngr[state->object.gui_mngr_nb - 1] = gui_manager;

	ICE_Log(ICE_LOG_SUCCES, "GuiManager]::[%d]::[Create", state->object.gui_mngr_nb - 1);
	return state->object.gui_mngr_nb - 1;
}

void ICE_GuiManager_Destroy(ICE_State * state, const unsigned int man)
{
	if (!state)
		state = game.state_mngr.current;

	ICE_GuiManager *manager = &state->object.gui_mngr[man];

	for (unsigned int i = 0; i < manager->gui_contain; i++)
	{
		//Free everything to free in Label
		ICE_Gui_Destroy(&manager->gui[i]);
	}

	ICE_Free(manager->gui);
	ICE_Log(ICE_LOG_SUCCES, "GuiManager]::[%d]::[Free", man);
}

void ICE_GuiManager_DestroyAll(ICE_State * state)
{
	if (!state)
		state = game.state_mngr.current;

	ICE_GuiManager *manager = state->object.gui_mngr;
	unsigned int nb_manager = state->object.gui_mngr_nb;

	for (unsigned int i = 0; i < nb_manager; i++)
	{
		if (!manager[i].isFree)
		{
			ICE_GuiManager_Destroy(state, i);
			manager[i].isFree = ICE_True;
		}
	}
	free(manager);
}

/* GUI */

ICE_Gui ICE_Gui_Create(ICE_Box box, unsigned int man_texture, unsigned int nb_texture)
{
	ICE_Gui gui = { 0 };

	gui.type = ICE_GUI_RECTANGLE;

	gui.have_texture_defined = ICE_True;
	gui.exist = ICE_True;
	gui.box = box;
	gui.texturemanager_nb = man_texture;
	gui.texture_nb = nb_texture;

	return gui;
}

unsigned int ICE_Gui_Insert(ICE_State * state, const unsigned int man, const ICE_Box box, unsigned int texture_manager, unsigned int texture_nb)
{
	if (!state)
		state = game.state_mngr.current;

	// Insert label in array
	state->object.gui_mngr[man].gui[state->object.gui_mngr[man].gui_contain] = ICE_Gui_Create(box, texture_manager, texture_nb);
	state->object.gui_mngr[man].gui_contain++;

	ICE_Log(ICE_LOG_SUCCES, "GuiManager]::[%d]::[Gui]::[%d]::[Create", texture_manager, state->object.gui_mngr[man].gui_contain-1);

	// Test size to realloc more space
	if (state->object.gui_mngr[man].gui_size <= state->object.gui_mngr[man].gui_contain) {
		ICE_Gui* tmp = ICE_Realloc(state->object.gui_mngr[man].gui, sizeof(ICE_Gui)*(state->object.gui_mngr[man].gui_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "GuiManager]::[%d]::[Resized]::[%d", man, state->object.gui_mngr[man].gui_size * 2);
		state->object.gui_mngr[man].gui = tmp;
		state->object.gui_mngr[man].gui_size *= 2;
	}

	ICE_Gui_UpdateTexture(man, state->object.gui_mngr[man].gui_contain - 1);
	return state->object.gui_mngr[man].gui_contain - 1;
}

void ICE_Gui_Clear(ICE_Gui * label)
{
	ICE_Texture temp = label->texture_cache;
	memset(label, 0, sizeof(ICE_Gui)); 
	label->texture_cache = temp;
}
void ICE_Gui_Destroy(ICE_Gui * ptr)
{
	ICE_Texture_Destroy(&ptr->texture_cache);
}

/* GUI GET */

ICE_Gui * ICE_Gui_Get(ICE_State *state, int man, int gui)
{
	if (!state)
		state = game.state_mngr.current;

	return &state->object.gui_mngr[man].gui[gui];
}

/* GUI SET */

void ICE_Gui_SetTexture(ICE_Gui * gui, int texture_man, int texture)
{
	gui->texture_nb = texture;
	gui->texturemanager_nb = texture_man;
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
