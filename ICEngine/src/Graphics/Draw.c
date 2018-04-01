#include "../Core/TypesCore.h"
#include <string.h>
#include "../Core/Label_private.h"
#include "../Maths/Box.h"
#include "Texture.h"
#include "../Graphics/Camera.h"

extern ICE_Game game;

void ICE_Draw_LabelWorld()
{
	ICE_State * current = game.state_mngr.current;

	for (int i = 0; i < current->object.label_mngr_nb; i++)
		for (int j = 0; j < current->object.label_mngr[i].label_contain; j++)
		{
			if (current->object.label_mngr[i].label[j].active)
			{
				if (
					strcmp(current->object.label_mngr[i].label[j].text, current->object.label_mngr[i].label[j].old_text) ||
					current->object.label_mngr[i].label[j].size != current->object.label_mngr[i].label[j].old_size ||
					current->object.label_mngr[i].label[j].color != current->object.label_mngr[i].label[j].old_color
					)
				{
					ICE_Label_UpdateTexture(ICE_Label_Get(NULL, i, j));
					current->object.label_mngr[i].label[j].old_color = current->object.label_mngr[i].label[j].color;
					current->object.label_mngr[i].label[j].old_size = current->object.label_mngr[i].label[j].size;

					ICE_String_Delete(current->object.label_mngr[i].label[j].old_text);
					current->object.label_mngr[i].label[j].old_text = ICE_String_Init(current->object.label_mngr[i].label[j].text);
				}

				ICE_Box box = ICE_Box_New(
					current->object.label_mngr[i].label[j].x,
					current->object.label_mngr[i].label[j].y,
					current->object.label_mngr[i].label[j].texture.w,
					current->object.label_mngr[i].label[j].texture.h
				);
 
				if (current->object.label_mngr[i].label[j].isFixedToWorld)
					ICE_Texture_RenderCenteredTexture(&current->object.label_mngr[i].label[j].texture, NULL, (ICE_Box[]) { ICE_Camera_WorldScreen(box) });
			}
		}

}
void ICE_Draw_LabelScreen() {
	ICE_State * current = game.state_mngr.current;

	for (int i = 0; i < current->object.label_mngr_nb; i++)
		for (int j = 0; j < current->object.label_mngr[i].label_contain; j++)
		{
			if (current->object.label_mngr[i].label[j].active)
			{
				if (
					strcmp(current->object.label_mngr[i].label[j].text, current->object.label_mngr[i].label[j].old_text) ||
					current->object.label_mngr[i].label[j].size != current->object.label_mngr[i].label[j].old_size ||
					current->object.label_mngr[i].label[j].color != current->object.label_mngr[i].label[j].old_color
					)
				{
					ICE_Label_UpdateTexture(ICE_Label_Get(NULL, i, j));
					current->object.label_mngr[i].label[j].old_color = current->object.label_mngr[i].label[j].color;
					current->object.label_mngr[i].label[j].old_size = current->object.label_mngr[i].label[j].size;

					ICE_String_Delete(current->object.label_mngr[i].label[j].old_text);
					current->object.label_mngr[i].label[j].old_text = ICE_String_Init(current->object.label_mngr[i].label[j].text);
				}

				ICE_Box box = ICE_Box_New(
					current->object.label_mngr[i].label[j].x,
					current->object.label_mngr[i].label[j].y,
					current->object.label_mngr[i].label[j].texture.w,
					current->object.label_mngr[i].label[j].texture.h
				);

				// Fixed to screen
				if (!current->object.label_mngr[i].label[j].isFixedToWorld)
					ICE_Texture_RenderCenteredTexture(&current->object.label_mngr[i].label[j].texture, NULL, &box);
			}
		}
}