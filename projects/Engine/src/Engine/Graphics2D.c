#include "Graphics2D.h"
#include "Graphics2D_private.h"
#include "../Framework/Memory_.h"

// INIT DATA

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

// DESTROY DATA

void ICE_Graphics2D_Data_Texture_Destroy(ICE_Graphics2D_Data_Texture* data_)
{
	
}

void ICE_Graphics2D_Data_Sprite_Destroy(ICE_Graphics2D_Data_Sprite* data_)
{

}

void ICE_Graphics2D_Data_Label_Destroy(ICE_Graphics2D_Data_Label* data_)
{

}

void ICE_Graphics2D_Data_Primitive_Destroy(ICE_Graphics2D_Data_Primitive* data_)
{

}

// DESTROY DATA PTR

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

// SET DATA

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
