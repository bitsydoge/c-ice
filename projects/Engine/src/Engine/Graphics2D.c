#include "Graphics2D.h"
#include "Graphics2D_private.h"
#include "../Framework/Memory_.h"
#include "../Framework/Log.h"

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// -------------------------------- Graphics2D Data ------------------------------------ //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

// ---------------------------------------   Init    ----------------------------------- //

ICE_Graphics2D_Data_Texture* ICE_Graphics2D_Data_Texture_Init()
{
	ICE_Graphics2D_Data_Texture * ptr = ICE_Calloc(1, sizeof(ICE_Graphics2D_Data_Texture));

	return ptr;
}

ICE_Graphics2D_Data_Sprite* ICE_Graphics2D_Data_Sprite_Init()
{
	ICE_Graphics2D_Data_Sprite* ptr = ICE_Calloc(1, sizeof(ICE_Graphics2D_Data_Sprite));
	
	return ptr;
}

ICE_Graphics2D_Data_Label * ICE_Graphics2D_Data_Label_Init()
{
	ICE_Graphics2D_Data_Label* ptr = ICE_Calloc(1, sizeof(ICE_Graphics2D_Data_Label));

	return ptr;
}

ICE_Graphics2D_Data_Primitive * ICE_Graphics2D_Data_Primitive_Init()
{
	ICE_Graphics2D_Data_Primitive* ptr = ICE_Calloc(1, sizeof(ICE_Graphics2D_Data_Primitive));

	return ptr;
}

// ---------------------------------------   Destroy   ----------------------------------- //

void ICE_Graphics2D_Data_Texture_Destroy(ICE_Graphics2D_Data_Texture* data_)
{
	
}

void ICE_Graphics2D_Data_Sprite_Destroy(ICE_Graphics2D_Data_Sprite* data_)
{

}

void ICE_Graphics2D_Data_Label_Destroy(ICE_Graphics2D_Data_Label* data_)
{
	ICE_String_Destroy(&data_->actual.text);
	ICE_String_Destroy(&data_->old.text);
}

void ICE_Graphics2D_Data_Primitive_Destroy(ICE_Graphics2D_Data_Primitive* data_)
{

}

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// -------------------------------- Graphics2D  ---------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

struct ICE_Graphics2D ICE_Graphics2D_Build()
{
	struct ICE_Graphics2D temp = { 1, ICE_GRAPHICS2D_TYPES_NONE, NULL, 1, 0,1, 1, ICE_Vect_New(0.5,0.5), ICE_Vect_New(0.5,0.5), ICE_Color_New(0,0,0),1 };
	return temp;
}

void ICE_Graphics2D_SetType(ICE_Graphics2D* graphics2d_, ICE_Graphics2D_Types types_)
{
	// Check if data is not empty and if it's not the same type. Free everything inside if needed then free the data ptr
	if (graphics2d_->type != types_ && graphics2d_->type != ICE_GRAPHICS2D_TYPES_NONE) 
		ICE_Graphics2D_Destroy(graphics2d_);

	// Add the new Data
	switch (types_)
	{
	case ICE_GRAPHICS2D_TYPES_TEXTURE:
		graphics2d_->data = ICE_Graphics2D_Data_Texture_Init();
			break;
	case ICE_GRAPHICS2D_TYPES_SPRITE:
		graphics2d_->data = ICE_Graphics2D_Data_Sprite_Init();
		break;
	case ICE_GRAPHICS2D_TYPES_LABEL:
		graphics2d_->data = ICE_Graphics2D_Data_Label_Init();
		break;
	case ICE_GRAPHICS2D_TYPES_PRIMITIVE:
		graphics2d_->data = ICE_Graphics2D_Data_Primitive_Init();
		break;
	default:;
	}

	// Set the enum to show the type the void* is
	graphics2d_->type = types_;
}

void ICE_Graphics2D_SetData_Texture(ICE_Graphics2D* graphics2d_, ICE_TextureID texture_id_)
{
	if (graphics2d_->type == ICE_GRAPHICS2D_TYPES_TEXTURE)
	{
		((ICE_Graphics2D_Data_Texture*)graphics2d_->data)->texture_id = texture_id_;
	}
	else
		ICE_Log_Error("This Graphics2D is not type : Texture");
}

void ICE_Graphics2D_SetData_Sprite(ICE_Graphics2D* graphics2d_, ICE_SpriteID sprite_id_, ICE_FrameID frame_id_)
{
	if (graphics2d_->type == ICE_GRAPHICS2D_TYPES_SPRITE)
	{
		((ICE_Graphics2D_Data_Sprite*)graphics2d_->data)->sprite_id = sprite_id_;
		((ICE_Graphics2D_Data_Sprite*)graphics2d_->data)->frame= frame_id_;
	}
	else
		ICE_Log_Error("This Graphics2D is not type : Sprite");
}

void ICE_Graphics2D_SetData_Label(ICE_Graphics2D* graphics2d_, ICE_FontID font_id_, ICE_StringStd text_,
	ICE_Color text_color_, int text_size_, int text_warp_size_)
{
	if (graphics2d_->type == ICE_GRAPHICS2D_TYPES_LABEL)
	{
		((ICE_Graphics2D_Data_Label*)graphics2d_->data)->actual.font_id = font_id_;
		((ICE_Graphics2D_Data_Label*)graphics2d_->data)->actual.text = ICE_String_Init(text_);
		((ICE_Graphics2D_Data_Label*)graphics2d_->data)->actual.color = text_color_;
		((ICE_Graphics2D_Data_Label*)graphics2d_->data)->actual.size = text_size_;
		((ICE_Graphics2D_Data_Label*)graphics2d_->data)->actual.warp_size = text_warp_size_;
	}
	else
		ICE_Log_Error("This Graphics2D is not type : Font");
}

void ICE_Graphics2D_SetData_Primitive(ICE_Graphics2D* graphics2d_)
{
	if (graphics2d_->type == ICE_GRAPHICS2D_TYPES_PRIMITIVE)
	{

	}
	else
		ICE_Log_Error("This Graphics2D is not type : Font");
}

void ICE_Graphics2D_Destroy(ICE_Graphics2D* graphics2d_)
{
	if (graphics2d_->type != ICE_GRAPHICS2D_TYPES_NONE)
	{
		switch (graphics2d_->type)
		{
		case ICE_GRAPHICS2D_TYPES_TEXTURE:
			ICE_Graphics2D_Data_Texture_Destroy(graphics2d_->data);
			break;
		case ICE_GRAPHICS2D_TYPES_SPRITE:
			ICE_Graphics2D_Data_Sprite_Destroy(graphics2d_->data);
			break;
		case ICE_GRAPHICS2D_TYPES_LABEL:
			ICE_Graphics2D_Data_Label_Destroy(graphics2d_->data);
			break;
		case ICE_GRAPHICS2D_TYPES_PRIMITIVE:
			ICE_Graphics2D_Data_Primitive_Destroy(graphics2d_->data);
			break;
		default:
			break;
		}

		ICE_Free(graphics2d_->data);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// -------------------------------- Graphics2D Control --------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

// ---------------------------------------   Set     ----------------------------------- //

void ICE_Graphics2D_SetVisibility(ICE_Graphics2D* graphics2d_, ICE_Bool isVisible_)
{
	graphics2d_->isVisible = isVisible_;
}

void ICE_Graphics2D_SetRotation(ICE_Graphics2D* graphics2d_, ICE_Float rotation_angle_)
{
	graphics2d_->rotation = fmod(rotation_angle_, 360.00);
}

void ICE_Graphics2D_AddRotation(ICE_Graphics2D* graphics2d_, ICE_Float rotation_angle_to_add_)
{
	graphics2d_->rotation = fmod(graphics2d_->rotation + rotation_angle_to_add_, 360.00);
}

void ICE_Graphics2D_SetScale(ICE_Graphics2D* graphics2d_, ICE_Vect scale_)
{
	graphics2d_->scale_h = scale_.y;
	graphics2d_->scale_w = scale_.x;
}

void ICE_Graphics2D_SetScaleW(ICE_Graphics2D* graphics2d_, ICE_Float scale_w_)
{
	graphics2d_->scale_w = scale_w_;
}

void ICE_Graphics2D_SetScaleH(ICE_Graphics2D* graphics2d_, ICE_Float scale_h_)
{
	graphics2d_->scale_h = scale_h_;
}

void ICE_Graphics2D_SetAnchorPostion(ICE_Graphics2D * graphics2d_, ICE_Vect anchor_postion_)
{
	graphics2d_->anchor_position = anchor_postion_;
}

void ICE_Graphics2D_SetAnchorRotation(ICE_Graphics2D* graphics2d_, ICE_Vect anchor_rotation_)
{
	graphics2d_->anchor_position = anchor_rotation_;
}

void ICE_Graphics2D_SetZ_Order(ICE_Graphics2D* graphics2d_, int z_order_)
{
	graphics2d_->z_order = z_order_;
}

// ---------------------------------------   Get     ----------------------------------- //

ICE_Bool ICE_Graphics2D_GetVisibility(ICE_Graphics2D* graphics2d_)
{
	return graphics2d_->isVisible;
}

ICE_Float ICE_Graphics2D_GetRotation(ICE_Graphics2D* graphics2d_)
{
	return graphics2d_->rotation;
}

ICE_Vect ICE_Graphics2D_GetScale(ICE_Graphics2D* graphics2d_)
{
	return ICE_Vect_New(graphics2d_->scale_w, graphics2d_->scale_h);
}

ICE_Float ICE_Graphics2D_GetScaleW(ICE_Graphics2D* graphics2d_)
{
	return graphics2d_->scale_w;
}

ICE_Float ICE_Graphics2D_GetScaleH(ICE_Graphics2D* graphics2d_)
{
	return graphics2d_->scale_h;
}

ICE_Vect ICE_Graphics2D_GetAnchorPosition(ICE_Graphics2D* graphics2d_)
{
	return graphics2d_->anchor_position;
}

ICE_Vect ICE_Graphics2D_GetAnchorRotation(ICE_Graphics2D* graphics2d_)
{
	return graphics2d_->anchor_rotation;
}

int ICE_Graphics2D_GetZ_Order(ICE_Graphics2D* graphics2d_)
{
	return graphics2d_->z_order = 1;
}