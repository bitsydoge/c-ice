#ifndef DEF_ICE_GRAPHICS2D_H
#define DEF_ICE_GRAPHICS2D_H

#include "Types.h"
#include "../Framework/String_.h"
#include "Color.h"
#include "Vector.h"

enum ICE_Graphics2D_Types
{
	ICE_GRAPHICS2D_TYPES_NONE = 0,
	ICE_GRAPHICS2D_TYPES_TEXTURE = 1,
	ICE_GRAPHICS2D_TYPES_SPRITE = 2,
	ICE_GRAPHICS2D_TYPES_LABEL = 3,
	ICE_GRAPHICS2D_TYPES_PRIMITIVE = 4

}; typedef enum ICE_Graphics2D_Types ICE_Graphics2D_Types;

typedef struct ICE_Graphics2D ICE_Graphics2D;

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// -------------------------------- Graphics2D  ---------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

void ICE_Graphics2D_Destroy(ICE_Graphics2D* graphics2d_);
void ICE_Graphics2D_SetType(ICE_Graphics2D* graphics2d_, ICE_Graphics2D_Types types_);
void ICE_Graphics2D_SetData_Texture(ICE_Graphics2D* graphics2d_, ICE_TextureID texture_id_);
void ICE_Graphics2D_SetData_Sprite(ICE_Graphics2D* graphics2d_, ICE_SpriteID sprite_id_, ICE_FrameID frame_id_);
void ICE_Graphics2D_SetData_Label(ICE_Graphics2D* graphics2d_, ICE_FontID font_id_, ICE_StringStd text_, ICE_Color text_color_, int text_size_, int text_warp_size_);
void ICE_Graphics2D_SetData_Primitive(ICE_Graphics2D* graphics2d_);

///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// -------------------------------- Graphics2D Control --------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

// ---------------------------------------   Set     ----------------------------------- //
void ICE_Graphics2D_SetVisibility(ICE_Graphics2D* graphics2d_, ICE_Bool isVisible_);
void ICE_Graphics2D_SetRotation(ICE_Graphics2D* graphics2d_, ICE_Bool rotation_angle_);
void ICE_Graphics2D_SetScale(ICE_Graphics2D* graphics2d_, ICE_Vect scale_);
void ICE_Graphics2D_SetScaleW(ICE_Graphics2D* graphics2d_, ICE_Float scale_w_);
void ICE_Graphics2D_SetScaleH(ICE_Graphics2D* graphics2d_, ICE_Float scale_h_);
void ICE_Graphics2D_SetAnchorPostion(ICE_Graphics2D* graphics2d_, ICE_Vect anchor_postion_);
void ICE_Graphics2D_SetAnchorRotation(ICE_Graphics2D* graphics2d_, ICE_Vect anchor_rotation_);
// -------------------------------------     Get     ----------------------------------- //
ICE_Bool ICE_Graphics2D_GetVisibility(ICE_Graphics2D* graphics2d_);
ICE_Float ICE_Graphics2D_GetRotation(ICE_Graphics2D* graphics2d_);
ICE_Vect ICE_Graphics2D_GetScale(ICE_Graphics2D* graphics2d_);
ICE_Float ICE_Graphics2D_GetScaleW(ICE_Graphics2D* graphics2d_);
ICE_Float ICE_Graphics2D_GetScaleH(ICE_Graphics2D* graphics2d_);
ICE_Vect ICE_Graphics2D_GetAnchorPosition(ICE_Graphics2D* graphics2d_);
ICE_Vect ICE_Graphics2D_GetAnchorRotation(ICE_Graphics2D* graphics2d_);

#endif