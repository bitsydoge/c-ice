#include "Data.h"
#include <stdlib.h>
#include "Game.h"
#include "../Framework/Assert_.h"
#include "../Framework/Memory_.h"

extern ICE_Game GAME;

// Make a Data and create a pointer in the GAME->data array (return the pointer created)
void* ICE_Data_Insert_(ICE_State * state, ICE_ID _size)
{
	if (!state)
		state = GAME.current;

	state->object.data_nb++;
	state->object.data = ICE_Realloc(state->object.data, sizeof(void*)*(state->object.data_nb));
	state->object.data[state->object.data_nb - 1] = ICE_Calloc(1, _size);
	void * _pointer = state->object.data[state->object.data_nb - 1];
	return _pointer;
}

/// Return pointer to a Data
void* ICE_Data_Get(ICE_State * state, ICE_ID nb_data)
{
	if (!state)
		state = GAME.current;

	void * _pointer;

	if (nb_data <= state->object.data_nb)
		_pointer = state->object.data[nb_data];

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
void ICE_Data_Destroy(ICE_State * state, ICE_ID nb_data)
{
	if (!state)
		state = GAME.current;

	void * _pointer;

	if (nb_data <= state->object.data_nb)
		_pointer = state->object.data[nb_data];

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

void ICE_Data_DestroyAll(ICE_State * state)
{
	if (!state)
		state = GAME.current;

	for(ICE_ID i = 0; i < state->object.data_nb; i++)
	{
		ICE_Free(state->object.data[i]);
	}
	ICE_Free(state->object.data);
}