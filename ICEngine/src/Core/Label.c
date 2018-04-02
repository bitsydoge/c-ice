#include "Label.h"

#include "TypesCore.h"

#include "../Framework/Log.h"
#include "../Graphics/Color.h"
#include "../Framework/Memory_.h"
#include "../Framework/String_.h"
#include "../Maths/TypesMaths.h"
#include "Label_private.h"

#include <string.h>
#include "../ICE.h"

extern ICE_Game game;

/* LABEL MANAGER */

unsigned int ICE_LabelManager_Insert(ICE_State * state)
{
	if (!state)
		state = game.state_mngr.current;

	ICE_LabelManager text_manager = { 0 };
	text_manager.label_size = ICE_DEFAULT_LABEL_MNGR_SIZE;
	text_manager.label = ICE_Calloc(text_manager.label_size, sizeof(ICE_Label)); // Label Array

	state->object.label_mngr_nb++;
	state->object.label_mngr = ICE_Realloc(state->object.label_mngr, state->object.label_mngr_nb * sizeof(ICE_LabelManager)); // Manager Array
	state->object.label_mngr[state->object.label_mngr_nb - 1] = text_manager;

	ICE_Log(ICE_LOG_SUCCES, "LabelManager]::[%d]::[Create", state->object.label_mngr_nb - 1);
	return state->object.label_mngr_nb - 1;
}

void ICE_LabelManager_Destroy(ICE_State * state, const unsigned int man)
{
	if (!state)
		state = game.state_mngr.current;

	ICE_LabelManager *manager = &state->object.label_mngr[man];

	for (unsigned int i = 0; i < manager->label_contain; i++)
	{
		//Free everything to free in Label
		ICE_Label_Destroy(&manager->label[i]);
	}

	ICE_Free(manager->label);
	ICE_Log(ICE_LOG_SUCCES, "LabelManager]::[%d]::[Free", man);
}

void ICE_LabelManager_DestroyAll(ICE_State * state)
{
	if (!state)
		state = game.state_mngr.current;

	ICE_LabelManager *manager = state->object.label_mngr;
	unsigned int nb_manager = state->object.label_mngr_nb;
	
	for (unsigned int i = 0; i < nb_manager; i++)
	{
		if (!manager[i].isFree)
		{
			ICE_LabelManager_Destroy(state, i);
			manager[i].isFree = ICE_True;
		}
	}
	free(manager);
}

/* LABEL */

ICE_Label ICE_Label_Create(char* text, ICE_Vect pos)
{
	ICE_Label label = { 0 };

	// Assigne
	label.active = ICE_True;
	label.isFixedToWorld = ICE_False;
	label.color = ICE_Color_New(255, 255, 255);
	label.old_color = ICE_Color_New(255, 255, 255);
	label.text = ICE_String_Init(text);
	label.old_text = ICE_String_Init(text);
	label.size = 200;
	label.old_size = 200;
	label.x = pos.x;
	label.y = pos.y;

	return label;
}

unsigned int ICE_Label_Insert(ICE_State * state, const unsigned int man, char *text, const ICE_Vect pos)
{
	if (!state)
		state = game.state_mngr.current;

	// Insert label in array
	state->object.label_mngr[man].label[state->object.label_mngr[man].label_contain] = ICE_Label_Create(text, pos);
	ICE_Label_UpdateTexture(ICE_Label_Get(state, man, state->object.label_mngr[man].label_contain));
	state->object.label_mngr[man].label_contain++;

	ICE_Log(ICE_LOG_SUCCES, "LabelManager]::[%d]::[Label]::[%d]::[Create]::[String=\"%s\"", man, state->object.label_mngr[man].label_contain - 1, text);

	// Test size to realloc more space
	if (state->object.label_mngr[man].label_size <= state->object.label_mngr[man].label_contain) {
		ICE_Label* tmp = ICE_Realloc(state->object.label_mngr[man].label, sizeof(ICE_Label)*(state->object.label_mngr[man].label_size * 2));
		// Test if realloc succes
		ICE_Log(ICE_LOG_WARNING, "LabelManager]::[%d]::[Resized]::[%d", man, state->object.label_mngr[man].label_size * 2);
		state->object.label_mngr[man].label = tmp;
		state->object.label_mngr[man].label_size *= 2;
	}

	return state->object.label_mngr[man].label_contain - 1;
}

void ICE_Label_Clear(ICE_Label * label)
{
	ICE_String temp = label->text;
	ICE_String temp2 = label->old_text;
	memset(label, 0, sizeof(ICE_Label));
	label->text = temp;
	label->old_text = temp2;
	ICE_String_Resize(&temp, 1);
	ICE_String_Resize(&temp2, 1);
}

void ICE_Label_Destroy(ICE_Label * ptr)
{
	ICE_String_Delete(ptr->text);
	ICE_String_Delete(ptr->old_text);
	ICE_Texture_Destroy(&ptr->texture);
}

/* LABEL GET FUNCTION */

ICE_Label * ICE_Label_Get(ICE_State * state, const unsigned man, const unsigned nb)
{
	if(state)
		return &state->object.label_mngr[man].label[nb];
	return &game.state_mngr.current->object.label_mngr[man].label[nb];
}

ICE_String ICE_Label_GetString(ICE_Label* ptr)
{
	return ptr->text;
}

/* LABEL SET FUNCTION */

void ICE_Label_SetSize(ICE_Label *label, int size)
{
	label->size = size;
}

void ICE_Label_SetString(ICE_Label * label, ICE_String string)
{
	ICE_String_Delete(label->text);
	label->text = ICE_String_Init(string);
}

void ICE_Label_SetPos(ICE_Label * label, ICE_Vect vect)
{
	label->x = vect.x;
	label->y = vect.y;
}

void ICE_Label_SetColor(ICE_Label * label, ICE_Color color)
{
	label->color = color;
}

void ICE_Label_SetAngle(ICE_Label * label, ICE_Float angle)
{
	label->angle = angle;
}

void ICE_Label_FixToWorld(ICE_Label * label, ICE_Bool yn)
{
	label->isFixedToWorld = yn;
}