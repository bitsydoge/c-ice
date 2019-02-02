#include "../Core/TypesCore.h"
#include <string.h>
#include "../Core/Label_private.h"
#include "../Maths/Box.h"
#include "Texture.h"
#include "../Graphics/Camera.h"
#include "Gui_private.h"
#include "Texture_private.h"
#include "Sprite.h"
#include "../Core/Converter_private.h"
#include "../ICE.h"

extern ICE_Game GAME;
extern ICE_Asset ASSET;

void ICE_Draw_LabelWorld()
{
	ICE_State * current = GAME.current;

		for (ICE_ID j = 0; j < current->object.label_mngr.label_contain; j++)
		{
			if (current->object.label_mngr.label[j].active)
			{
				if (
				    strcmp(current->object.label_mngr.label[j].text, current->object.label_mngr.label[j].old_text) ||
					current->object.label_mngr.label[j].size != current->object.label_mngr.label[j].old_size ||
					current->object.label_mngr.label[j].color != current->object.label_mngr.label[j].old_color ||
					current->object.label_mngr.label->wrap_width != current->object.label_mngr.label->wrap_width_old
					)
				{
					ICE_Label_UpdateTexture(ICE_Label_Get(NULL, j));
					current->object.label_mngr.label[j].old_color = current->object.label_mngr.label[j].color;
					current->object.label_mngr.label[j].old_size = current->object.label_mngr.label[j].size;

					ICE_String_Free(current->object.label_mngr.label[j].old_text);
					current->object.label_mngr.label[j].old_text = ICE_String_Init(current->object.label_mngr.label[j].text);
					current->object.label_mngr.label[j].wrap_width_old = current->object.label_mngr.label[j].wrap_width;
				}

				ICE_Box box = ICE_Box_New(
					current->object.label_mngr.label[j].x,
					current->object.label_mngr.label[j].y,
					current->object.label_mngr.label[j].texture.w,
					current->object.label_mngr.label[j].texture.h
				);
 
				if (current->object.label_mngr.label[j].labelType)
					ICE_Texture_RenderExCentered(&current->object.label_mngr.label[j].texture, NULL, (ICE_Box[]) { ICE_Camera_WorldScreen(box) }, current->object.label_mngr.label[j].angle);
			}
		}

}
void ICE_Draw_LabelScreen() {
	ICE_State * current = GAME.current;

		for (ICE_ID j = 0; j < current->object.label_mngr.label_contain; j++)
		{
			if (current->object.label_mngr.label[j].active)
			{
				if (
					strcmp(current->object.label_mngr.label[j].text, current->object.label_mngr.label[j].old_text) ||
					current->object.label_mngr.label[j].size != current->object.label_mngr.label[j].old_size ||
					current->object.label_mngr.label[j].color != current->object.label_mngr.label[j].old_color
					)
				{
					ICE_Label_UpdateTexture(ICE_Label_Get(NULL, j));
					current->object.label_mngr.label[j].old_color = current->object.label_mngr.label[j].color;
					current->object.label_mngr.label[j].old_size = current->object.label_mngr.label[j].size;

					ICE_String_Free(current->object.label_mngr.label[j].old_text);
					current->object.label_mngr.label[j].old_text = ICE_String_Init(current->object.label_mngr.label[j].text);
				}

				ICE_Box box = ICE_Box_New(
					current->object.label_mngr.label[j].x,
					current->object.label_mngr.label[j].y,
					current->object.label_mngr.label[j].texture.w,
					current->object.label_mngr.label[j].texture.h
				);

				// Fixed to screen
				if (!current->object.label_mngr.label[j].labelType)
					ICE_Texture_RenderEx(&current->object.label_mngr.label[j].texture, NULL, &box, current->object.label_mngr.label[j].angle);
			}
		}
}

void ICE_Draw_Gui()
{
	ICE_State * current = GAME.current;

		for (ICE_ID j = 0; j < current->object.gui_mngr.gui_contain; j++)
		{
			if (current->object.gui_mngr.gui[j].active && current->object.gui_mngr.gui[j].have_texture_defined)
			{

				if (
					!ICE_Box_CompareSize(current->object.gui_mngr.gui[j].box, current->object.gui_mngr.gui[j].old_box) ||
					current->object.gui_mngr.gui[j].texturemanager_index != current->object.gui_mngr.gui[j].old_texturemanager_index ||
					current->object.gui_mngr.gui[j].texture_index != current->object.gui_mngr.gui[j].old_texture_index)
				{
					ICE_Gui_UpdateTexture(current, j);

					current->object.gui_mngr.gui[j].old_texturemanager_index = current->object.gui_mngr.gui[j].texturemanager_index;
					current->object.gui_mngr.gui[j].old_texture_index = current->object.gui_mngr.gui[j].texture_index;
					current->object.gui_mngr.gui[j].old_box = current->object.gui_mngr.gui[j].box;
				}
				ICE_Texture_RenderEx(&current->object.gui_mngr.gui[j].texture_cache, NULL, &current->object.gui_mngr.gui[j].box, 0);
			}
		}
}

void ICE_Draw_Entity()
{
	ICE_State * current = GAME.current;

	for (ICE_ID j = 0; j < current->object.entity_mngr.entity_contain; j++)
	{
		// With just texture
		if (current->object.entity_mngr.entity[j].graphics_type == ICE_ENTITYGRAPHICSTYPES_TEXTURE && current->object.entity_mngr.entity[j].active)
		{
			ICE_Box rect = ICE_Camera_WorldScreen
			(
				ICE_Box_New
				(
					current->object.entity_mngr.entity[j].x,
					current->object.entity_mngr.entity[j].y,
					current->object.entity_mngr.entity[j].w,
					current->object.entity_mngr.entity[j].h
				)
			);

			ICE_Texture_RenderExCentered
			(
				ICE_Texture_Get(current->object.entity_mngr.entity[j].graphics_index),
				NULL,
				&rect,
				current->object.entity_mngr.entity[j].angle
			);
		}

		// With a sprite
		if (current->object.entity_mngr.entity[j].graphics_type == ICE_ENTITYGRAPHICSTYPES_SPRITE && current->object.entity_mngr.entity[j].active)
		{
			ICE_Box rect = ICE_Camera_WorldScreen(ICE_Box_New(
				current->object.entity_mngr.entity[j].x,
				current->object.entity_mngr.entity[j].y,
				current->object.entity_mngr.entity[j].w,
				current->object.entity_mngr.entity[j].h));

			ICE_Texture_RenderExCentered
			(
				ICE_Texture_Get(ASSET.sprite_mngr.sprite[current->object.entity_mngr.entity[j].graphics_index].texture_index),
				&current->object.entity_mngr.entity[j].graphics_box_render,
				&rect,
				current->object.entity_mngr.entity[j].angle
			);
		}
	}
			// With a label
}
