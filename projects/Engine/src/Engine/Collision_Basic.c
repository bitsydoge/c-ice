#include "Collision_Basic.h"


ICE_Bool ICE_Collision_Box_Point(ICE_Box box, ICE_Vect point)
{
	return point.x > box.x && point.x < box.x+box.w && point.y > box.y && point.y < box.y+box.h;
}