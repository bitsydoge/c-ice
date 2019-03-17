#ifndef DEF_ICE_BASIC_COLLISION
#define DEF_ICE_BASIC_COLLISION

#include "Vector.h"
#include "Box.h"

ICE_Bool ICE_Collision_Box_Point(ICE_Box box, ICE_Vect point);
ICE_Bool ICE_Collision_Box_Box(ICE_Box box_a, ICE_Box box_b);

#endif