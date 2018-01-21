#include "hdr/Data.h"
#include "hdr/Debug.h"
#include "hdr/Game.h"


extern iceGame game;

// Make a Data and create a pointer in the game->data array (return the pointer created)
void* iceDataAdd(size_t _size)
{
	game.data_nb++;
	game.data = realloc(game.data, sizeof(void*)*game.data_nb);
	game.data[game.data_nb - 1] = calloc(1, _size);
	void * _pointer = game.data[game.data_nb - 1];
	return _pointer;
}

/// Return pointer to a Data
void* iceDataGet(int nb_data)
{
	void * _pointer;

	if (nb_data <= game.data_nb)
		_pointer = game.data[nb_data];

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
		iceAssert(_pointer != NULL, "Pointer is null so there is no data at this number");
	}

	return _pointer;
}

/// Destroy a Data
void iceDataDestroy(int nb_data)
{
	void * _pointer;

	if (nb_data <= game.data_nb)
		_pointer = game.data[nb_data];

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
		iceAssert(_pointer != NULL, "Pointer is null so there is no data at this number");
	}

	free(_pointer);
}

////////////////////////
////////////////////////
/// DATA FOR ENTITY ////
////////////////////////
////////////////////////

// Make a Data and create a pointer in the game->data array (return the pointer created)
void* iceDataEntityAdd(int entity_man, int entity_nb, size_t _size)
{
	game.entitymanager[entity_man].entity[entity_nb].data_nb++;
	game.entitymanager[entity_man].entity[entity_nb].data = realloc(game.entitymanager[entity_man].entity[entity_nb].data, sizeof(void*)*game.entitymanager[entity_man].entity[entity_nb].data_nb);
	game.entitymanager[entity_man].entity[entity_nb].data[game.entitymanager[entity_man].entity[entity_nb].data_nb - 1] = calloc(1, _size);
	void * _pointer = game.entitymanager[entity_man].entity[entity_nb].data[game.entitymanager[entity_man].entity[entity_nb].data_nb - 1];
	return _pointer;
}

void* iceDataEntityGet(int entity_man, int entity_nb, int nb_data)
{
	void * _pointer;

	if (nb_data <= game.entitymanager[entity_man].entity[entity_nb].data_nb)
		_pointer = game.entitymanager[entity_man].entity[entity_nb].data[nb_data];

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
		iceAssert(_pointer != NULL, "Pointer is null so there is no data at this number");
	}

	return _pointer;
}

/// Destroy a Data
void iceDataEntityDestroy(int entity_man, int entity_nb, int nb_data)
{
	void * _pointer;

	if (nb_data <= game.entitymanager[entity_man].entity[entity_nb].data_nb)
		_pointer = game.entitymanager[entity_man].entity[entity_nb].data[nb_data];

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
		iceAssert(_pointer != NULL, "Pointer is null so there is no data at this number");
	}

	free(_pointer);
}