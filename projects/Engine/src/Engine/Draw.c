#include "Draw_private.h"
#include "Texture.h"
#include "Box.h"
#include "Scene_private.h"
#include "TextureManager_private.h"
#include "Camera.h"
#include "Graphics2D.h"

#include "GlobalData_private.h"
ICE_GLOBALDATA_SCENE_CURRENT

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// --------------------------------    LabelDraw    ------------------------------------ //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

/*
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
*/



///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// --------------------------------    GuiDraw      ------------------------------------ //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

/*
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
*/



///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// --------------------------------    EntityDraw   ------------------------------------ //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

void ICE_Draw_Graphics2D_Texture(ICE_Graphics2D* graphics2d_, ICE_Control2D* control2d_)
{

}

void ICE_Draw_Graphics2D_Sprite(ICE_Graphics2D* graphics2d_, ICE_Control2D* control2d_)
{

}

void ICE_Draw_Graphics2D_Label(ICE_Graphics2D* graphics2d_, ICE_Control2D* control2d_)
{
	
}

void ICE_Draw_Graphics2D_Primitive(ICE_Graphics2D* graphics2d_, ICE_Control2D* control2d_)
{
	
}

void ICE_Draw_Entity(ICE_Graphics2D * graphics2d_, ICE_Control2D * control2d_)
{
	switch (graphics2d_->type)
	{
	case ICE_GRAPHICS2D_TYPES_TEXTURE:
		ICE_Draw_Graphics2D_Texture(graphics2d_, control2d_);
		break;
	case ICE_GRAPHICS2D_TYPES_SPRITE:
		ICE_Draw_Graphics2D_Sprite(graphics2d_, control2d_);
		break;
	case ICE_GRAPHICS2D_TYPES_LABEL:
		ICE_Draw_Graphics2D_Label(graphics2d_, control2d_);
		break;
	case ICE_GRAPHICS2D_TYPES_PRIMITIVE:
		ICE_Draw_Graphics2D_Primitive(graphics2d_, control2d_);
		break;
	default:
		break;
	}
}

void ICE_Draw_EntityAll()
{
	ICE_Scene * current = ICE_GLOBJ_SCENE_CURRENT;
	for (ICE_ID j = 0; j < current->entity_mngr.entity_contain; j++)
	{
		if (current->entity_mngr.entity[j].exist && current->entity_mngr.entity[j].control2d.isActive && current->entity_mngr.entity[j].graphics2d.isVisible)
			ICE_Draw_Entity(&current->entity_mngr.entity[j].graphics2d, &current->entity_mngr.entity[j].control2d);
	}
}