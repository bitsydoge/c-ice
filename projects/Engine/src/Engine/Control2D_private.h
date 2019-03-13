#ifndef DEF_ICE_CONTROL2D_PRIVATE_H
#define DEF_ICE_CONTROL2D_PRIVATE_H

#include "Control2D.h"

#include "../Framework/TypesFramework.h"

struct ICE_Control2D
{
	ICE_Bool isActive; // IS PROCESSED ?
	ICE_Float x, y; // POSITION
	ICE_Float rotation; // ROTATION DEGREE
	ICE_Float scale_w, scale_h; // SCALE, 1,1 default


	//Polar Movement LEGACY MOVEMENT 
	ICE_Bool				already_moved_polar;
	ICE_Float				x_polar_destination_move;
	ICE_Float				y_polar_destination_move;
	ICE_Float				r_polar_destination_move;
	ICE_Float				x_polar_shift_move;
	ICE_Float				y_polar_shift_move;
	ICE_Float				polar_distance_r_r;

}; typedef struct ICE_Control2D ICE_Control2D;

#endif