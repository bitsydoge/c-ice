#include "hdr/Physics.h"

/// return 1 if it colide
iceBool icePhysicsBoxCollision(const iceBox box1, const iceBox box2)
{
	if (
		box1.p.x<(box2.p.x + box2.w) && 
		box1.p.x + box1.w>box2.p.x &&
		box1.p.y<box2.p.y + box2.h &&
		box1.h + box1.p.y>box2.p.y
		)
		return iceTrue;
	return iceFalse;
}