#include "Draw_private.h"


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//									LABEL DRAW
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ICE_Draw_LabelWorld()
{
	ICE_State* current = GAME.current;

	for (ICE_ID j = 0; j < current->object.label_mngr.label_contain; j++)
	{
		if (current->object.label_mngr.label[j].active)
		{
			if (
				strcmp(current->object.label_mngr.label[j].text, current->object.label_mngr.label[j].old_text) != 0
				||
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
				ICE_Texture_RenderEx2(&current->object.label_mngr.label[j].texture, NULL, (ICE_Box[]) { ICE_Camera_WorldScreen(box) }, current->object.label_mngr.label[j].angle);
		}
	}

}
void ICE_Draw_LabelScreen() {
	ICE_State* current = GAME.current;

	for (ICE_ID j = 0; j < current->object.label_mngr.label_contain; j++)
	{
		if (current->object.label_mngr.label[j].active)
		{
			if (
				strcmp(current->object.label_mngr.label[j].text, current->object.label_mngr.label[j].old_text) != 0
				||
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//									GUI DRAW
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ICE_Draw_Gui_9patch(ICE_GuiID id_)
{
	ICE_State* current = GAME.current;
	if (!ICE_Box_CompareSize(current->object.gui_mngr.gui[id_].box, current->object.gui_mngr.gui[id_].old_box) ||
		current->object.gui_mngr.gui[id_].texture_index != current->object.gui_mngr.gui[id_].old_texture_index)
	{
		ICE_Gui_UpdateTexture(current, id_);
		current->object.gui_mngr.gui[id_].old_texture_index = current->object.gui_mngr.gui[id_].texture_index;
		current->object.gui_mngr.gui[id_].old_box = current->object.gui_mngr.gui[id_].box;
	}
	ICE_Texture_RenderEx(&current->object.gui_mngr.gui[id_].texture_cache, NULL, &current->object.gui_mngr.gui[id_].box, 0);
}

void ICE_Draw_Gui_Image(ICE_GuiID id_)
{
	ICE_State* current = GAME.current;

	if (!ICE_Box_CompareSize(current->object.gui_mngr.gui[id_].box, current->object.gui_mngr.gui[id_].old_box) ||
		current->object.gui_mngr.gui[id_].texture_index != current->object.gui_mngr.gui[id_].old_texture_index)
	{
		ICE_Gui_UpdateTexture(current, id_);
		current->object.gui_mngr.gui[id_].old_texture_index = current->object.gui_mngr.gui[id_].texture_index;
		current->object.gui_mngr.gui[id_].old_box = current->object.gui_mngr.gui[id_].box;
	}

	ICE_Texture_RenderEx(&current->object.gui_mngr.gui[id_].texture_cache, NULL, &current->object.gui_mngr.gui[id_].box, 0);
}

void ICE_Draw_Gui_Label(ICE_GuiID id_)
{
	ICE_State* current = GAME.current;

}

void ICE_Draw_Gui(ICE_GuiID id_)
{
	ICE_State* current = GAME.current;

	switch (current->object.gui_mngr.gui[id_].type)
	{
	case ICE_GUITYPE_9PATCH:
		ICE_Draw_Gui_9patch(id_);
		break;
	case ICE_GUITYPE_IMAGE:
		ICE_Draw_Gui_Image(id_);
		break;
	case ICE_GUITYPE_LABEL:
		ICE_Draw_Gui_Label(id_);
		break;
	default:
		break;
	}
}

void ICE_Draw_AllGui()
{
	ICE_State* current = GAME.current;
	for (ICE_ID j = 0; j < current->object.gui_mngr.gui_contain; j++)
	{
		if (current->object.gui_mngr.gui[j].active)
			ICE_Draw_Gui(j);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//									ENTITY DRAW
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ICE_Draw_Entity_Texture(ICE_TextureID id_)
{
	ICE_State* current = GAME.current;
	ICE_Box rect = ICE_Camera_WorldScreen
	(
		ICE_Box_New
		(
			current->object.entity_mngr.entity[id_].x,
			current->object.entity_mngr.entity[id_].y,
			current->object.entity_mngr.entity[id_].w,
			current->object.entity_mngr.entity[id_].h
		)
	);

	ICE_Texture_RenderEx2 // Draw Texture or Error Texture
	(
		current->object.entity_mngr.entity[id_].graphics_index != (ICE_TextureID)-1 ? ICE_Texture_Get(current->object.entity_mngr.entity[id_].graphics_index) : &ASSET.texture_error, // trinaire
		NULL,
		&rect,
		current->object.entity_mngr.entity[id_].angle
	);
}

void ICE_Draw_Entity_Sprite(ICE_TextureID id_)
{
	ICE_State* current = GAME.current;
	ICE_Box rect = ICE_Camera_WorldScreen(ICE_Box_New
	(current->object.entity_mngr.entity[id_].x,
		current->object.entity_mngr.entity[id_].y,
		current->object.entity_mngr.entity[id_].w,
		current->object.entity_mngr.entity[id_].h));

	if (current->object.entity_mngr.entity[id_].graphics_index != (ICE_TextureID)-1)
	{
		ICE_Texture_RenderEx2
		(
			ICE_Texture_Get(ASSET.sprite_mngr.sprite[current->object.entity_mngr.entity[id_].graphics_index].texture_index),
			&current->object.entity_mngr.entity[id_].graphics_box_render,
			&rect,
			current->object.entity_mngr.entity[id_].angle
		);
	}
	else
	{
		ICE_Texture_RenderEx2
		(
			&ASSET.texture_error,
			NULL,
			&rect,
			current->object.entity_mngr.entity[id_].angle
		);
	}
}

void ICE_Draw_Entity_Label(ICE_TextureID id_)
{
	ICE_State* current = GAME.current;
}

void ICE_Draw_Entity_Primitives(ICE_TextureID id_)
{
	ICE_State* current = GAME.current;
}

void ICE_Draw_Entity(ICE_TextureID id_)
{
	ICE_State* current = GAME.current;
	switch (current->object.entity_mngr.entity[id_].graphics_type)
	{
	case ICE_ENTITYGRAPHICSTYPES_TEXTURE:
		ICE_Draw_Entity_Texture(id_);
		break;
	case ICE_ENTITYGRAPHICSTYPES_SPRITE:
		ICE_Draw_Entity_Sprite(id_);
		break;
	case ICE_ENTITYGRAPHICSTYPES_LABEL:
		ICE_Draw_Entity_Label(id_);
		break;
	case ICE_ENTITYGRAPHICSTYPES_PRIMITIVES:
		ICE_Draw_Entity_Primitives(id_);
		break;
	default:
		break;
	}
}

void ICE_Draw_AllEntity()
{
	ICE_State* current = GAME.current;
	for (ICE_ID j = 0; j < current->object.entity_mngr.entity_contain; j++)
	{
		if (current->object.entity_mngr.entity[j].active)
			ICE_Draw_Entity(j);
	}
}