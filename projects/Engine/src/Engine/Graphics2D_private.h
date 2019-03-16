#ifndef DEF_ICE_GRAPHICS2D_PRIVATE_H
#define DEF_ICE_GRAPHICS2D_PRIVATE_H

#include "../Framework/BasicTypes.h"

#include "Types.h"
#include "Vector.h"
#include "Color.h"
#include "Label.h"
#include "Texture_private.h"

#include "Graphics2D.h"

struct ICE_Graphics2D
{
	ICE_Bool isVisible; // PROCESS GRAPHICS ?

	ICE_Graphics2D_Types type;
	void* data;

	ICE_Float rotation; // Graphics Rotation
	ICE_Float scale_w, scale_h; // Graphics only, scale
	ICE_Vect anchor_position, anchor_rotation; //

	ICE_Color modulation_color; // rgb
	ICE_Float modulation_transparency; // 0-1

};

struct ICE_Graphics2D_Data_Texture
{
	ICE_TextureID texture_id;

}; typedef struct ICE_Graphics2D_Data_Texture ICE_Graphics2D_Data_Texture;

struct ICE_Graphics2D_Data_Sprite
{
	ICE_SpriteID sprite_id;
	ICE_ID frame;
	void* animation_dumies;

}; typedef struct ICE_Graphics2D_Data_Sprite ICE_Graphics2D_Data_Sprite;

struct ICE_Graphics2D_Data_Label
{
	ICE_Label actual;
	ICE_Label old;

	ICE_Texture* generated;

}; typedef struct ICE_Graphics2D_Data_Label ICE_Graphics2D_Data_Label;

struct ICE_Graphics2D_Data_Primitive
{
	int dummies;

}; typedef struct ICE_Graphics2D_Data_Primitive ICE_Graphics2D_Data_Primitive;

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// -------------------------------- Graphics2D ----------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

struct ICE_Graphics2D ICE_Graphics2D_Build();

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// -------------------------------- Graphics2D Data ------------------------------------ //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

// ---------------------------------------   Init    ----------------------------------- //

ICE_Graphics2D_Data_Texture* ICE_Graphics2D_Data_Texture_Init();
ICE_Graphics2D_Data_Sprite* ICE_Graphics2D_Data_Sprite_Init();
ICE_Graphics2D_Data_Label* ICE_Graphics2D_Data_Label_Init();
ICE_Graphics2D_Data_Primitive* ICE_Graphics2D_Data_Primitive_Init();

// ---------------------------------------   Destroy   ----------------------------------- //

void ICE_Graphics2D_Data_Texture_Destroy(ICE_Graphics2D_Data_Texture* data_);
void ICE_Graphics2D_Data_Sprite_Destroy(ICE_Graphics2D_Data_Sprite* data_);
void ICE_Graphics2D_Data_Label_Destroy(ICE_Graphics2D_Data_Label* data_);
void ICE_Graphics2D_Data_Primitive_Destroy(ICE_Graphics2D_Data_Primitive* data_);

#endif