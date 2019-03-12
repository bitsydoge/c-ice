#ifndef DEF_ICE_CONTROL2D_H
#define DEF_ICE_CONTROL2D_H

#include "../Framework/TypesFramework.h"

struct ICE_Control2D
{
	ICE_Bool isActive; // IS PROCESSED ?
	ICE_Float x, y; // POSITION
	ICE_Float rotation; // ROTATION DEGREE
	ICE_Float scale_w, scale_h; // SCALE, 1,1 default

}; typedef struct ICE_Control2D ICE_Control2D;

#endif