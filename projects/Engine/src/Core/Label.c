#include "Label.h"

#include "TypesCore.h"

#include "../Framework/Log.h"
#include "../Graphics/Color.h"
#include "../Framework/Memory_.h"
#include "../Framework/String_.h"
#include "../Maths/TypesMaths.h"
#include "Label_private.h"
#include "../Graphics/Texture.h"
#include <string.h>
#include <stdio.h>

extern ICE_Game GAME;

/* LABEL MANAGER */

void ICE_LabelManager_Init(ICE_State* state)
{
	if (!state)
		state = GAME.current;

	ICE_LabelManager text_manager = { 0 };
	text_manager.label_size = ICE_DEFAULT_LABEL_MNGR_SIZE;
	text_manager.label = ICE_Calloc(text_manager.label_size, sizeof(ICE_Label)); // Label Array

	state->object.label_mngr = text_manager;

	ICE_Log(ICE_LOGTYPE_SUCCES, "Create LabelManager in state %s", state->name);
}

void ICE_LabelManager_Destroy(ICE_State * state)
{
	if (!state)
		state = GAME.current;

	for (ICE_ID i = 0; i < state->object.label_mngr.label_contain; i++)
		ICE_Label_Destroy(&state->object.label_mngr.label[i]);

	ICE_Free(state->object.label_mngr.label);
	ICE_Log(ICE_LOGTYPE_SUCCES, "Free LabelManager in state %s", state->name);
}

/* LABEL */

ICE_Label ICE_Label_Build(ICE_StringStd text, ICE_Vect pos, int size, enum ICE_LabelType type)
{
	ICE_Label label = { 0 };

	// Assigne
	label.active = ICE_True;
	label.color = ICE_Color_New(255, 255, 255);
	label.old_color = ICE_Color_New(255, 255, 255);
	label.text = ICE_String_Init(text);
	label.old_text = ICE_String_Init(text);
	label.size = size;
	label.old_size = 200;
	label.x = pos.x;
	label.y = pos.y;
	label.labelType = type;

	return label;
}

ICE_ID ICE_Label_Create(ICE_State * state, ICE_StringStd text, const ICE_Vect pos, int size, enum ICE_LabelType type)
{
	if (!state)
		state = GAME.current;

	// Insert label in array
	state->object.label_mngr.label[state->object.label_mngr.label_contain] = ICE_Label_Build(text, pos, size, type);
	ICE_Label_UpdateTexture(ICE_Label_Get(state, state->object.label_mngr.label_contain));
	state->object.label_mngr.label_contain++;

	ICE_Log(ICE_LOGTYPE_SUCCES, "Create Label %d with text \"%s\" in State %s", state->object.label_mngr.label_contain - 1, text, state->name);

	// Test size to realloc more space
	if (state->object.label_mngr.label_size <= state->object.label_mngr.label_contain) 
	{
		ICE_Label* tmp = ICE_Realloc(state->object.label_mngr.label, sizeof(ICE_Label)*(state->object.label_mngr.label_size * 2));
		state->object.label_mngr.label = tmp;
		state->object.label_mngr.label_size *= 2;
	}

	return state->object.label_mngr.label_contain - 1;
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
	ICE_Texture_Free(&ptr->texture);
}

/* LABEL GET FUNCTION */

ICE_Label * ICE_Label_Get(ICE_State * state, const ICE_ID nb)
{
	if(state)
		return &state->object.label_mngr.label[nb];
	return &GAME.current->object.label_mngr.label[nb];
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

void ICE_Label_SetString(ICE_Label * label, ICE_StringStd format, ...)
{
	va_list args;
	va_start(args, format);

	ICE_Char buffer[1024];
	vsprintf(buffer, format, args);

	ICE_String_Delete(label->text);
	label->text = ICE_String_Init(buffer);

	va_end(args);
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

void ICE_Label_SetWrapWidth(ICE_Label * label, int wrap_width)
{
	label->wrap_width = wrap_width;
}

void ICE_Label_FixToWorld(ICE_Label * label, ICE_Bool yn)
{
	label->labelType = yn;
}

unsigned ICE_Label_GetWidth(ICE_Label* label)
{
	return label->texture.w;
}

unsigned ICE_Label_GetHeight(ICE_Label* label)
{
	return label->texture.h;
}

ICE_Float ICE_Label_GetX(ICE_Label * label)
{
	return label->x;
}

ICE_Float ICE_Label_GetY(ICE_Label * label)
{
	return label->y;
}