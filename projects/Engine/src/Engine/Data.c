#include "Data.h"
#include <stdlib.h>

#include "../Framework/Assert_.h"
#include "../Framework/Memory_.h"

#include "Types.h"
#include "Scene_private.h"

// Make a Data and create a pointer in the GAME->data array (return the pointer created)
ICE_DataID ICE_Data_Add(ICE_Size size_use_sizeof_)
{
	ICE_Scene * scene_ = ICE_Scene_GetCurrent();

	scene_->data_nb++;
	scene_->data = ICE_Realloc(scene_->data, sizeof(void*)*(scene_->data_nb));
	scene_->data[scene_->data_nb - 1] = ICE_Calloc(1, size_use_sizeof_);
	void * _pointer = scene_->data[scene_->data_nb - 1];
	return scene_->data_nb - 1;
}

/// Return pointer to a Data
void* ICE_Data_Get(ICE_DataID data_id_)
{
	ICE_Scene* scene_ = ICE_Scene_GetCurrent();

	void * _pointer;

	if (data_id_ <= scene_->data_nb)
		_pointer = scene_->data[data_id_];

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

/// Destroy a Data
void ICE_Data_Destroy(ICE_DataID data_id_)
{
	ICE_Scene* scene_ = ICE_Scene_GetCurrent();

	void * _pointer;

	if (data_id_ <= scene_->data_nb)
		_pointer = scene_->data[data_id_];

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

void ICE_Data_DestroyAll()
{
	ICE_Scene* scene_ = ICE_Scene_GetCurrent();

	for (ICE_ID i = 0; i < scene_->data_nb; i++)
	{
		ICE_Free(scene_->data[i]);
	}
	ICE_Free(scene_->data);
}