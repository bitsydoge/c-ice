#ifndef DEF_ICE_GRAPHICS2D_PRIVATE_H
#define DEF_ICE_GRAPHICS2D_PRIVATE_H

#include "../Framework/TypesFramework.h"

#include "TypesCore.h"
#include "Vector.h"
#include "Color.h"
#include "Label.h"
#include "Texture.h"

enum ICE_Graphics2D_Types
{
	ICE_GRAPHICS2D_TYPES_NONE = 0,
	ICE_GRAPHICS2D_TYPES_TEXTURE = 1,
	ICE_GRAPHICS2D_TYPES_SPRITE = 2,
	ICE_GRAPHICS2D_TYPES_LABEL = 3,
	ICE_GRAPHICS2D_TYPES_PRIMITIVE = 4

}; typedef enum ICE_Graphics2D_Types ICE_Graphics2D_Types;

struct ICE_Graphics2D_Control
{
	ICE_Bool isVisible; // PROCESS GRAPHICS ?
	ICE_Float rotation; // Graphics Rotation
	ICE_Float scale_w, scale_h; // Graphics only, scale
	ICE_Vect anchor_position, anchor_rotation; //

}; typedef struct ICE_Graphics2D_Control ICE_Graphics2D_Control;

struct ICE_Graphics2D_Modulator
{
	ICE_Color color; // rgb
	ICE_Float transparency; // 0-1

}; typedef struct ICE_Graphics2D_Modulator ICE_Graphics2D_Modulator;

struct ICE_Graphics2D
{
	ICE_Graphics2D_Types type;
	void* data;
	ICE_Graphics2D_Control control;
	ICE_Graphics2D_Modulator modulator;

}; typedef struct ICE_Graphics2D ICE_Graphics2D;

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


#endif