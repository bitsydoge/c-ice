#include "Collision_Basic.h"


ICE_Bool ICE_Collision_Box_Point(ICE_Box box, ICE_Vect point)
{
	return point.x > box.x && point.x < box.x+box.w && point.y > box.y && point.y < box.y+box.h;
}

ICE_Bool ICE_P_inside(int value, int min, int max)
{
	return (value >= min) && (value <= max);
}

ICE_Bool ICE_Collision_Box_Box(ICE_Box box_a, ICE_Box box_b)
{
	const ICE_Bool x_overlap = ICE_P_inside(box_a.x, box_b.x, box_b.x + box_b.w) ||
		ICE_P_inside(box_b.x, box_a.x, box_a.x + box_a.w);

	const ICE_Bool y_overlap = ICE_P_inside(box_a.y, box_b.y, box_b.y + box_b.h) ||
		ICE_P_inside(box_b.y, box_a.y, box_a.y + box_a.h);

	return x_overlap && y_overlap;
}