#ifndef DEF_ICE_PHYSICS_PRIVATE
#define DEF_ICE_PHYSICS_PRIVATE

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

// Physic Engine
// --------------------------

void icePhysicsSpaceStep();
cpSpace* icePhysicsGetSpace();
void icePhysicsUpdateEntity();

#endif
