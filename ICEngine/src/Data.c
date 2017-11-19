#include "hdr/Data.h"

// Make a Data and create a pointer in the game->data array (return the pointer created)
void* ICE_AddData(ICE_Game *game, size_t _size)
{
	game->nb_data++;
	game->data = realloc(game->data, sizeof(void*)*game->nb_data);
	game->data[game->nb_data - 1] = calloc(1, _size);
	void * _pointer = game->data[game->nb_data - 1];
	return _pointer;
}

/// Return pointer to a Data
void* ICE_GetData(ICE_Game *game, int nb_data)
{
	void * _pointer;

	if (nb_data <= game->nb_data)
		_pointer = game->data[nb_data];

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
void ICE_DestroyData(ICE_Game *game, int nb_data)
{
	void * _pointer;

	if (nb_data <= game->nb_data)
		_pointer = game->data[nb_data];

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

	free(_pointer);
}
