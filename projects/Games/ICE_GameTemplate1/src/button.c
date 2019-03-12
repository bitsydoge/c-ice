#pragma once
#include <ICE.h>
#include "button.h"

struct GG_Button GG_Button_Create(ICE_TextureID texture, ICE_TextureID text_hover, ICE_TextureID text_hover_clicked, ICE_Box box, ICE_StringStd string_, int size, void(*callback)(struct GG_Button*))
{
	struct GG_Button temp = { texture, text_hover, text_hover_clicked, (ICE_GuiID)-1, (ICE_LabelID)-1, size, callback };

	temp.gui_object = ICE_Gui_Create(ICE_State_Current, box, ICE_GUITYPE_IMAGE);
	ICE_Gui_SetTexture(ICE_Gui_Get(ICE_State_Current, temp.gui_object), temp.texture);

	temp.text = ICE_Label_Create(ICE_State_Current, string_, ICE_Vect_New(box.x + box.w / 2, box.y + box.h / 2), size, ICE_LABELTYPE_SCREEN);
	int heigh = ICE_Label_GetHeight(ICE_Label_Get(ICE_State_Current, temp.text));
	int width = ICE_Label_GetWidth(ICE_Label_Get(ICE_State_Current, temp.text));
	ICE_Vect pos_temp = { ICE_Label_GetX(ICE_Label_Get(ICE_State_Current, temp.text)), ICE_Label_GetY(ICE_Label_Get(ICE_State_Current, temp.text)) };
	ICE_Label_SetPos(ICE_Label_Get(ICE_State_Current, temp.text), ICE_Vect_New(pos_temp.x - width / 2, pos_temp.y - heigh / 2));

	return temp;
}

void GG_Button_Update(struct GG_Button * button)
{
	if (ICE_Collision_Box_Point(ICE_Gui_GetBox(ICE_Gui_Get(ICE_State_Current, button->gui_object)), ICE_Input_MouseVector()))
	{
		if (ICE_Input_Pressed(ICE_KEY_LEFTCLICK))
		{
			ICE_Gui_SetTexture(ICE_Gui_Get(ICE_State_Current, button->gui_object), button->texture_hover_clicked);
			button->callback(button);
		}
		else
			ICE_Gui_SetTexture(ICE_Gui_Get(ICE_State_Current, button->gui_object), button->texture_hover);
	}
	else
	{
		ICE_Gui_SetTexture(ICE_Gui_Get(ICE_State_Current, button->gui_object), button->texture);
	}
}