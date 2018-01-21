#ifndef DEF_ICE_TYPESPHYSICS
#define DEF_ICE_TYPESPHYSICS

#include <chipmunk/chipmunk.h>

typedef enum
{
	ICE_PHYSICS_NONE = 0,
	ICE_PHYSICS_RIGID_BODY = 1,
	ICE_PHYSICS_RIGID_BODY_isKINEMATIC = 2

} icePhysicsObjectTypes;

typedef enum
{
	ICE_PHYSICS_SHAPE_NONE = 0,
	ICE_PHYSICS_SHAPE_CIRCLE = 1,
	ICE_PHYSICS_SHAPE_BOX = 2

} icePhysicsObjectShapes;

typedef struct
{
	icePhysicsObjectTypes body_types;
	cpBody *body;
	
	icePhysicsObjectShapes shape_types;
	cpShape *shape;

	cpFloat mass;

	cpFloat radius;
	cpFloat w;
	cpFloat h;

} icePhysicsObject;

typedef struct
{
	cpSpace *space;
	cpVect gravity;

} icePhysicsManager;

#endif