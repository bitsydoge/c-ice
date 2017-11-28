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

	// Polar Movement Save
	iceBool already_moved_polar;

	iceFloat x_polar_destination_move;
	iceFloat y_polar_destination_move;
	iceFloat r_polar_destination_move;

	iceFloat x_polar_shift_move;
	iceFloat y_polar_shift_move;
	iceFloat polar_distance_r_r;
	////////////////////////////

	// Size
	iceFloat w, h;
	
	// Texture location
	iceBool have_texture;
	unsigned int man;
	unsigned int text;

	// Sprite
	iceBool have_sprite;
	unsigned int man_sprite;
	unsigned int sprite_nb;

	// Data Array
	int data_nb;
	void **data;

}iceEntity;

typedef struct{

	iceEntity *entity;
	unsigned long array_size;
	unsigned long nb_existing;

}iceEntityManager;

typedef struct {

	    ///////////// CORE //////////////


	//// Entity ////
	unsigned int entitymanager_size;
	iceEntityManager *entitymanager;
	
	//// Data //// 
	int nb_data;
	void** data;

	//// Input ////
	iceInput *input;

	//// Time ////
	iceTime time;

	//// OTHER ////
	int returnvalue;
	iceColor background;



	    ///////////// GRAPHICS ///////////


	//// Drawer ////
	iceDrawer drawer;

	//// Texture ////
	unsigned int texturemanager_size;
	iceTextureManager *texturemanager;

	//// Font ////
	iceFontManager fontmanager;

	//// Text ////
	unsigned int textmanager_size;
	iceLabelManager *textmanager;

	//// Gui ////
	unsigned int guimanager_size;
	iceGuiManager *guimanager;

	// Camera
	iceCamera camera;



	    ///////////// AUDIO //////////////
	

	//// Sound //// 
	iceSoundManager soundmanager;



} iceGame;

#endif
