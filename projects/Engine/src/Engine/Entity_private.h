#ifndef DEF_ICE_ENTITY_NXT_PRIVATE_H
#define DEF_ICE_ENTITY_NXT_PRIVATE_H

#include "TypesCore.h"
#include "Control2D_private.h"
#include "Graphics2D_private.h"
#include "Physics2D_private.h"

struct ICE_Entity
{
	// Identity
	ICE_EntityID	id;
	ICE_Uint32		timestamp;
	ICE_Bool		exist;

	// Control
	ICE_Control2D	control;

	// Graphics
	ICE_Graphics2D	graphics;

	// Logic
	void			(*func_create)(ICE_EntityID);
	void			(*func_update)(ICE_EntityID);
	void			(*func_destroy)(ICE_EntityID);

	ICE_DataID		data_id;
	void** data;

	// Physics
	ICE_Physics2D	physics;

}; typedef struct ICE_Entity ICE_Entity;



#endif