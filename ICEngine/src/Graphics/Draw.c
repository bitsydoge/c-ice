#include "../Core/TypesCore.h"
#include <string.h>
#include "../Core/Label_private.h"
#include "../Maths/Box.h"
#include "Texture.h"
#include "../Graphics/Camera.h"
#include "Gui_private.h"
#include "Texture_private.h"

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
					ICE_Texture_RenderExCentered(&current->object.label_mngr[i].label[j].texture, NULL, (ICE_Box[]) { ICE_Camera_WorldScreen(box) }, current->object.label_mngr[i].label[j].angle);
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
					ICE_Texture_RenderEx(&current->object.label_mngr[i].label[j].texture, NULL, &box, current->object.label_mngr[i].label[j].angle);
			}
		}
}

void ICE_Draw_Gui()
{
	ICE_State * current = game.state_mngr.current;
	for (int i = 0; i < current->object.gui_mngr_nb; i++)
		for (int j = 0; j < current->object.gui_mngr[i].gui_contain; j++)
		{
			// Fixed to screen
			if (current->object.gui_mngr[i].gui[j].exist && current->object.gui_mngr[i].gui[j].have_texture_defined)
			{
				if (
					!ICE_Box_CompareSize(current->object.gui_mngr[i].gui[j].box, current->object.gui_mngr[i].gui[j].old_box) ||
					current->object.gui_mngr[i].gui[j].texturemanager_nb != current->object.gui_mngr[i].gui[j].old_texturemanager_nb ||
					current->object.gui_mngr[i].gui[j].texture_nb != current->object.gui_mngr[i].gui[j].old_texture_nb)
				{
					ICE_Gui_UpdateTexture(i, j);

					current->object.gui_mngr[i].gui[j].old_texturemanager_nb = current->object.gui_mngr[i].gui[j].texturemanager_nb;
					current->object.gui_mngr[i].gui[j].old_texture_nb = current->object.gui_mngr[i].gui[j].texture_nb;
					current->object.gui_mngr[i].gui[j].old_box = current->object.gui_mngr[i].gui[j].box;
				}
				ICE_Texture_RenderEx(&current->object.gui_mngr[i].gui[j].texture_cache, NULL, &current->object.gui_mngr[i].gui[j].box, 0);
			}
		}
}