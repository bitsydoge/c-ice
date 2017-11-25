#ifndef DEF_ICE_STRUCT
#define DEF_ICE_STRUCT

#include <SDL2/SDL.h>
#include "TypesCore.h"
#include "TypesMaths.h"
#include "TypesGraphics.h"
#include "StructGraphics.h"
#include "StructAudio.h"

typedef struct
{
	
	int *tile;

} iceLayer;

typedef struct{

	// Map Size
	int w, h;
	int tile_w, tile_h;

	// Layer
	int nb_layer;
	iceLayer *layer;

} iceMap;

typedef struct{

	char key[512];
	int wheelup;
	int wheeldown;
	int quit;
	int leftclic;
	int leftclic_position_x;
	int leftclic_position_y;
	int leftclic_position_x_old;
	int leftclic_position_y_old;
	int leftclic_trigger;
	int rightclic;
	int rightclic_position_x;
	int rightclic_position_y;
	int rightclic_position_x_old;
	int rightclic_position_y_old;
	int rightclic_trigger;
	int mousex;
	int mousey;
	int focus;
	char *filedrop;
	int substate_quit;

} iceInput;

typedef struct{

	unsigned long actual;
	unsigned long last;
	double ticks;
	unsigned int ticksEllapsed;                                                                    
	double fps;
	double delta;

} iceTime;


////
//
//  I need to make a iceFont struct where
//
////

typedef struct{

	iceBool exist;
	
	// Position
	iceFloat x, y;
	iceFloat angle;

	// Size
	iceFloat w, h;
	
	// Data Array
	void **data;
	
	// Texture location
	iceBool have_texture;
	unsigned int man;
	unsigned int text;

}iceEntity;

typedef struct{

	iceEntity *entity;
	unsigned long array_size;
	unsigned long nb_existing;

}iceEntityManager;

/*! \brief Load essential module of the engine
*
*
*  Load the SDL, SDL_Mixer, SDL_TTF, srand, rlutil
*/
typedef struct {
	int returnvalue;
	iceColor background;

	// To implement
	iceDrawer drawer;

	// Input
	iceInput *input;

	// Time
	iceTime time;

	// Camera
	iceCamera camera;

	//// Manager ////
	// Texture //
	
	unsigned int texturemanager_size;
	iceTextureManager *texturemanager;

	// Sound // Only One soundmanager at a time
	iceSoundManager soundmanager;

	// Font // Only one for now
	iceFontManager fontmanager;

	// Entity // Multiple
	unsigned int entitymanager_size;
	iceEntityManager *entitymanager;

	// Data // 
	int nb_data;
	void** data;

} iceGame;

#endif
