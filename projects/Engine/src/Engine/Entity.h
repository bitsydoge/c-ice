#ifndef DEF_ICE_ENTITY_H
#define DEF_ICE_ENTITY_H

#include "Control2D.h"
#include "Graphics2D.h"
#include "Physics2D.h"

struct ICE_DataHolder
{
	ICE_DataID	data_id;
	void** data;

}; typedef struct ICE_DataHolder ICE_DataHolder;

struct ICE_Entity
{
	// Control
	ICE_Control2D	control;

	// Graphics
	ICE_Graphics2D	graphics;

	// Logic
	void			(*func_create)(ICE_EntityID);
	void			(*func_update)(ICE_EntityID);
	void			(*func_destroy)(ICE_EntityID);

	ICE_DataHolder data;

	// Physics
	ICE_Physics2D	physics;

}; typedef struct ICE_Entity ICE_Entity;

#endif