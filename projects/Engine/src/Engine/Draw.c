#include "Draw_private.h"
#include "Texture.h"
#include "Box.h"
#include "Scene_private.h"
#include "TextureManager_private.h"
#include "Camera.h"
#include "Graphics2D.h"

#include "GlobalData_private.h"
#include "Entity.h"
#include "Collision_Basic.h"
#include "Window.h"
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

struct ICE_Draw_EntityFinal
{
	ICE_Float rotation;
	ICE_Box dst;
	int z_order;

	ICE_Graphics2D_Types graphics2d_type;
	void* graphics2d_data;
};

void ICE_Draw_Graphics2D_Texture(struct ICE_Draw_EntityFinal * entity_processed_)
{
	ICE_Graphics2D_Data_Texture* graphics_2d_data = entity_processed_->graphics2d_data;
	if(ICE_Collision_Box_Box(ICE_Box_New(0, 0, ICE_Window_GetW(), ICE_Window_GetH()), entity_processed_->dst))
		ICE_Texture_RenderEx(ICE_Texture_Get(graphics_2d_data->texture_id), NULL, &entity_processed_->dst, entity_processed_->rotation);
}

void ICE_Draw_Graphics2D_Sprite(struct ICE_Draw_EntityFinal * entity_processed_)
{

}

void ICE_Draw_Graphics2D_Label(struct ICE_Draw_EntityFinal * entity_processed_)
{
	
}

void ICE_Draw_Graphics2D_Primitive(struct ICE_Draw_EntityFinal * entity_processed_)
{
	
}

void ICE_Draw_Entity(struct ICE_Draw_EntityFinal * entity_processed_)
{
	switch (entity_processed_->graphics2d_type)
	{
	case ICE_GRAPHICS2D_TYPES_TEXTURE:
		ICE_Draw_Graphics2D_Texture(entity_processed_);
		break;
	case ICE_GRAPHICS2D_TYPES_SPRITE:
		ICE_Draw_Graphics2D_Sprite(entity_processed_);
		break;
	case ICE_GRAPHICS2D_TYPES_LABEL:
		ICE_Draw_Graphics2D_Label(entity_processed_);
		break;
	case ICE_GRAPHICS2D_TYPES_PRIMITIVE:
		ICE_Draw_Graphics2D_Primitive(entity_processed_);
		break;
	default:
		break;
	}
}

ICE_Vect ICE_Draw_Entity_GenerateGraphSize(ICE_Graphics2D * graphics2d_)
{
	ICE_Vect generated_size = { 0 };

	switch(graphics2d_->type)
	{
	case ICE_GRAPHICS2D_TYPES_NONE: 
		generated_size.x = 0;
		generated_size.y = 0;
		break;
	case ICE_GRAPHICS2D_TYPES_TEXTURE: 
		generated_size.x = ICE_Texture_Get(((ICE_Graphics2D_Data_Texture*)graphics2d_->data)->texture_id)->w;
		generated_size.y = ICE_Texture_Get(((ICE_Graphics2D_Data_Texture*)graphics2d_->data)->texture_id)->h;
		break;
	case ICE_GRAPHICS2D_TYPES_SPRITE: 
		//TODO//generated_size.x = ICE_Sprite_Get(((ICE_Graphics2D_Data_Sprite*)graphics2d_->data)->sprite_id)->frame_h;
		//TODO//generated_size.y = ICE_Sprite_Get(((ICE_Graphics2D_Data_Sprite*)graphics2d_->data)->sprite_id)->frame_w;
		break;
	case ICE_GRAPHICS2D_TYPES_LABEL: 
		//TODO//
		break;
	case ICE_GRAPHICS2D_TYPES_PRIMITIVE: 
		//TODO//
		break;
	}

	return generated_size;
}

struct ICE_Draw_EntityFinal ICE_Draw_Entity_GenerateFinal(ICE_Entity* entity_)
{
	struct ICE_Draw_EntityFinal final_draw = { 0 };
	ICE_Vect graphics_size = ICE_Draw_Entity_GenerateGraphSize(&entity_->graphics2d);
	final_draw.rotation = fmod(entity_->control2d.rotation + entity_->graphics2d.rotation, 360.0);
	final_draw.dst.x = entity_->control2d.x * ICE_Camera_GetScaleW() - (graphics_size.x * entity_->graphics2d.anchor_position.x * entity_->control2d.scale_w * entity_->graphics2d.scale_w * ICE_Camera_GetScaleW());
	final_draw.dst.y = entity_->control2d.y * ICE_Camera_GetScaleH() - (graphics_size.y * entity_->graphics2d.anchor_position.y * entity_->control2d.scale_h * entity_->graphics2d.scale_h * ICE_Camera_GetScaleH());
	final_draw.dst.w = graphics_size.x * entity_->control2d.scale_w * entity_->graphics2d.scale_w * ICE_Camera_GetScaleW();
	final_draw.dst.h = graphics_size.y * entity_->control2d.scale_h * entity_->graphics2d.scale_h * ICE_Camera_GetScaleH();
	final_draw.graphics2d_data = entity_->graphics2d.data;
	final_draw.graphics2d_type = entity_->graphics2d.type;

	final_draw.dst = ICE_Camera_World_to_Screen(final_draw.dst);

	return final_draw;
}

void ICE_Draw_EntityAll()
{
	ICE_Scene* current = ICE_GLOBJ_SCENE_CURRENT;
	for (ICE_ID j = 0; j < current->entity_mngr.entity_contain; j++)
	{
		if (current->entity_mngr.entity[j].exist && current->entity_mngr.entity[j].control2d.isActive && current->entity_mngr.entity[j].graphics2d.isVisible)
			ICE_Draw_Entity((struct ICE_Draw_EntityFinal[]) { ICE_Draw_Entity_GenerateFinal(&current->entity_mngr.entity[j]) });
	}
}