#include "Entity.h"

#include <string.h>

#include "../Framework/Memory_.h"
#include "../Framework/Log.h"
#include "../Framework/Assert_.h"
#include "Types.h"



#include "Scene_private.h"
extern ICE_Scene* ICE_GLOBJ_SCENE_CURRENT;


#include "Graphics2D_private.h"
#include "Control2D_private.h"


///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// -------------------------------- Management  ---------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

ICE_Entity ICE_Entity_Build(ICE_Vect vect_)
{
	ICE_Entity entity = { 0 };

	entity.exist = ICE_True;
	entity.control2d = ICE_Control2D_Build(vect_);
	entity.graphics2d = ICE_Graphics2D_Build();
	entity.timestamp = SDL_GetTicks();

	return entity;
}

ICE_ID ICE_Entity_Create(ICE_Vect vect_)
{
	//if (!scene_)
	ICE_Scene * scene_ = ICE_GLOBJ_SCENE_CURRENT;

	ICE_EntityID avaible_slot = 0;
	ICE_Bool no_avaible_slot = ICE_False;

	for (ICE_EntityID i = 0; i < scene_->entity_mngr.entity_contain; i++)
	{
		if (scene_->entity_mngr.entity[i].exist == ICE_False)
		{
			avaible_slot = i;
			no_avaible_slot = ICE_True;
			break;
		}
	}
	if (!no_avaible_slot)
	{
		avaible_slot = scene_->entity_mngr.entity_contain;
		scene_->entity_mngr.entity_contain++;
	}


	scene_->entity_mngr.entity[avaible_slot] = ICE_Entity_Build(vect_);
	scene_->entity_mngr.entity[avaible_slot].id = avaible_slot;
	scene_->entity_mngr.entity_total++;


	ICE_Log(ICE_LOGTYPE_SUCCES, "Create Entity : ID(%d), Pos(%d, %d), Scene(\"%s\")", avaible_slot, vect_.x, vect_.y, ICE_GLOBJ_SCENE_CURRENT->name);

	// Resize Manager
	if (scene_->entity_mngr.entity_size <= scene_->entity_mngr.entity_contain)
	{
		ICE_Entity* tmp = ICE_Realloc(scene_->entity_mngr.entity, sizeof(ICE_Entity) * (scene_->entity_mngr.entity_size * 2));
		scene_->entity_mngr.entity = tmp;
		scene_->entity_mngr.entity_size *= 2;
	}

	return avaible_slot;
}

void ICE_Entity_Destroy(ICE_EntityID entity_id_)
{
	ICE_Entity * entity_ptr = &ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_];

	if (entity_ptr->exist)
	{
		if (entity_ptr->func_destroy != NULL)
			entity_ptr->func_destroy(entity_ptr->id);
		
		//Data Destroy
		ICE_Entity_DataDestroyAll(entity_ptr->id);

		// Component Destroy
		ICE_Graphics2D_Destroy(&entity_ptr->graphics2d);
		entity_ptr->graphics2d.type = ICE_GRAPHICS2D_TYPES_NONE;
		ICE_Control2D_Destroy(&entity_ptr->control2d);

		entity_ptr->func_create = NULL;
		entity_ptr->func_update = NULL;
		entity_ptr->func_destroy = NULL;
		entity_ptr->exist = ICE_False;
		ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity_total--;
	}
}




///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// -------------------------------- Data        ---------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

void* ICE_Entity_DataAdd_(ICE_EntityID entity_id_, ICE_ID size_)
{
	ICE_Entity* entity_ptr = &ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_];

	entity_ptr->data_nb++;
	entity_ptr->data = ICE_Realloc(entity_ptr->data, sizeof(void*) * (entity_ptr->data_nb));
	entity_ptr->data[entity_ptr->data_nb - 1] = ICE_Calloc(1, size_);
	void* _pointer = entity_ptr->data[entity_ptr->data_nb - 1];

	return _pointer;
}

void* ICE_Entity_DataGet(ICE_EntityID entity_id_, ICE_DataID id_data_)
{
	ICE_Entity* entity_ptr = &ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_];


	void* _pointer;

	if (id_data_ <= entity_ptr->data_nb)
		_pointer = entity_ptr->data[id_data_];

	////////////////////////////////////////////
	//                                        //
	// If you see this assert, you choosed    //
	// a data that doesn't exist              //
	//                                        //
	////////////////////////////////////////////

	else
	{
		_pointer = NULL;
		//assert(("Pointer is null so there is no data at this number", _pointer));
		ICE_Assert(_pointer != NULL, "Pointer is null so there is no data at this number");
	}

	return _pointer;
}

void ICE_Entity_DataDestroy(ICE_EntityID entity_id_, ICE_DataID id_data_)
{
	ICE_Entity* entity_ptr = &ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_];

	void* _pointer;

	if (id_data_ <= entity_ptr->data_nb)
		_pointer = entity_ptr->data[id_data_];

	////////////////////////////////////////////
	//                                        //
	// If you see this assert, you choosed    //
	// a data that doesn't exist              //
	//                                        //
	////////////////////////////////////////////

	else
	{
		_pointer = NULL;
		//assert("Pointer is null so there is no data at this number", _pointer);
		ICE_Assert(_pointer != NULL, "Pointer is null so there is no data at this number");
	}

	ICE_Free(_pointer);
}

void ICE_Entity_DataDestroyAll(ICE_EntityID entity_id_)
{
	ICE_Entity* entity_ptr = &ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_];

	for (ICE_ID i = 0; i < entity_ptr->data_nb; i++)
	{
		if (entity_ptr->data)
			if (entity_ptr->data[i])
			{
				ICE_Free(entity_ptr->data[i]);
				entity_ptr->data[i] = NULL;
			}
	}
	if (entity_ptr->data)
	{
		ICE_Free(entity_ptr->data);
		entity_ptr->data = NULL;
	}
}




///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// -------------------------------- GetComponent  -------------------------------------- //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

ICE_Graphics2D* ICE_Entity_GetGraphics2D(ICE_EntityID entity_id_)
{
	return &ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_].graphics2d;
}

ICE_Control2D* ICE_Entity_GetControl2D(ICE_EntityID entity_id_)
{
	return &ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_].control2d;
}



///////////////////////////////////////////////////////////////////////////////////////////
// ------------------------------------------------------------------------------------- //
// -------------------------------- EntityFunction  ------------------------------------ //
// ------------------------------------------------------------------------------------- //
///////////////////////////////////////////////////////////////////////////////////////////

void ICE_Entity_FunctionSet(ICE_EntityID entity_id_, void(*call_create)(ICE_EntityID), void(*call_update)(ICE_EntityID), void(*call_destroy)(ICE_EntityID))
{
	ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_].func_create = call_create;
	ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_].func_update = call_update;
	ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_].func_destroy = call_destroy;
}