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


// ------------------------------------    Management    ------------------------------------------ //

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

	ICE_Log(ICE_LOGTYPE_SUCCES, "Create Entity %d in scene", avaible_slot);

	// Resize Manager
	if (scene_->entity_mngr.entity_size <= scene_->entity_mngr.entity_contain)
	{
		ICE_Entity* tmp = ICE_Realloc(scene_->entity_mngr.entity, sizeof(ICE_Entity) * (scene_->entity_mngr.entity_size * 2));
		scene_->entity_mngr.entity = tmp;
		scene_->entity_mngr.entity_size *= 2;
	}

	return avaible_slot;
}

void ICE_Entity_Clear(ICE_Entity* entity)
{
	memset(entity, 0, sizeof(ICE_Entity));
}

void ICE_Entity_Destroy(ICE_Entity* ptr)
{
	if (ptr->exist)
	{
		ptr->exist = ICE_False;
		ptr->control2d.isActive = ICE_False;

		ptr->func_create = NULL;
		ptr->func_update = NULL;
		if (ptr->func_destroy != NULL)
			ptr->func_destroy(ptr->id);

		ICE_Graphics2D_SetType(&ptr->graphics2d, ICE_GRAPHICS2D_TYPES_NONE);

		ICE_Entity_DataDestroyAll(ptr);

		ptr->func_destroy = NULL;
	}
}




// ------------------------------------    Data    ------------------------------------------ //

void* ICE_Entity_DataAdd_(ICE_Entity* entity_, ICE_ID size_)
{
	entity_->data_nb++;
	entity_->data = ICE_Realloc(entity_->data, sizeof(void*) * (entity_->data_nb));
	entity_->data[entity_->data_nb - 1] = ICE_Calloc(1, size_);
	void* _pointer = entity_->data[entity_->data_nb - 1];
	return _pointer;
}

void* ICE_Entity_DataGet(ICE_Entity* entity_, ICE_DataID id_data_)
{
	void* _pointer;

	if (id_data_ <= entity_->data_nb)
		_pointer = entity_->data[id_data_];

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

void ICE_Entity_DataDestroy(ICE_Entity* entity_, ICE_DataID id_data_)
{
	void* _pointer;

	if (id_data_ <= entity_->data_nb)
		_pointer = entity_->data[id_data_];

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

void ICE_Entity_DataDestroyAll(ICE_Entity* entity_)
{
	for (ICE_ID i = 0; i < entity_->data_nb; i++)
	{
		if (entity_->data)
			if (entity_->data[i])
			{
				ICE_Free(entity_->data[i]);
				entity_->data[i] = NULL;
			}
	}
	if (entity_->data)
	{
		ICE_Free(entity_->data);
		entity_->data = NULL;
	}
}

ICE_Graphics2D* ICE_Entity_GetGraphics2D(ICE_EntityID entity_id_)
{
	return &ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_].graphics2d;
}

ICE_Control2D* ICE_Entity_GetControl2D(ICE_EntityID entity_id_)
{
	return &ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_].control2d;
}


//// ------------------------------------ Graphics2D ------------------------------------------ //
//
//void ICE_Entity_Graphics2D_SetType(ICE_EntityID entity_id_, ICE_Graphics2D_Types types_)
//{
//	ICE_Graphics2D_SetType(&ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_].graphics2d, types_);
//}
//
//void ICE_Entity_Graphics2D_SetData_Texture(ICE_EntityID entity_id_, ICE_TextureID texture_id_)
//{
//	ICE_Graphics2D_SetData_Texture(&ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_].graphics2d, texture_id_);
//}
//
//void ICE_Entity_Graphics2D_SetData_Sprite(ICE_EntityID entity_id_, ICE_SpriteID sprite_id_, ICE_FrameID frame_id_)
//{
//	ICE_Graphics2D_SetData_Sprite(&ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_].graphics2d, sprite_id_, frame_id_);
//}
//
//void ICE_Entity_Graphics2D_SetData_Label(ICE_EntityID entity_id_, ICE_FontID font_id_, ICE_StringStd text_,
//	ICE_Color text_color_, int text_size_, int text_warp_size_)
//{
//	ICE_Graphics2D_SetData_Label(&ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_].graphics2d, font_id_, text_, text_color_, text_size_, text_warp_size_);
//}
//
//void ICE_Entity_Graphics2D_SetData_Primitive(ICE_EntityID entity_id_)
//{
//	ICE_Graphics2D_SetData_Primitive(&ICE_GLOBJ_SCENE_CURRENT->entity_mngr.entity[entity_id_].graphics2d);
//}
//
//
//
//// ------------------------------------ Control2D ------------------------------------------ //