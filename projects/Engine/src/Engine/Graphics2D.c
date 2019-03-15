#include "Graphics2D.h"
#include "Graphics2D_private.h"
#include "../Framework/Memory_.h"

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

void ICE_Graphics2D_SetType(ICE_Graphics2D* graphics2d_, ICE_Graphics2D_Types types_)
{
	if (graphics2d_->type != ICE_GRAPHICS2D_TYPES_NONE && graphics2d_->type != types_)
		ICE_Free(graphics2d_->data);

	graphics2d_->type = types_;

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
}

void ICE_Graphics2D_Destroy(ICE_Graphics2D * graphics2d_)
{
	if(graphics2d_->type != ICE_GRAPHICS2D_TYPES_NONE)
	{
		if (graphics2d_->data != 0)
			ICE_Free(graphics2d_->data);
		graphics2d_->type = ICE_GRAPHICS2D_TYPES_NONE;
	}
		
}
