#ifndef DEF_ICE_PHYSICS
#define DEF_ICE_PHYSICS

#include "TypesMaths.h"
#include <chipmunk/chipmunk.h>

// Converter
// --------------------------

inline iceVect cpVect_to_iceVect(cpVect vect)
{
	iceVect ice = { vect.x, vect.y };
	return ice;
}

inline cpVect iceVect_to_cpVect(iceVect vect)
{
	cpVect cp = { vect.x, vect.y };
	return cp;
}

// --------------------------

iceBool icePhysicsBoxCollision(const iceBox box1, const iceBox box2);
void icePhysicsSetGravity(iceVect vect);
void icePhysicsSpaceStep();
cpSpace* icePhysicsGetSpace();
void icePhysicsUpdateEntity();

#endif
