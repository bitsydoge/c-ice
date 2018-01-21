#ifndef DEF_ICE_TYPES
#define DEF_ICE_TYPES

#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED
typedef char iceBool;
#define iceTrue 1
#define iceTRUE 1
#define icetrue 1
#define iceFalse 0
#define iceFALSE 0
#define icefalse 0
#endif

#include "TypesCore.h"
#include "TypesMaths.h"
#include "TypesGraphics.h"
#include "TypesAudio.h"
#include "TypesPhysics.h"

typedef struct
{

	int *tile;

} iceLayer;

typedef struct {

	// Map Size
	int w, h;
	int tile_w, tile_h;

	// Layer
	int nb_layer;
	iceLayer *layer;

} iceMap;

typedef struct {

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

typedef struct {

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

typedef struct {

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

	// Physics
	icePhysicsObject physics;

}iceEntity;

typedef struct {

	iceEntity *entity;
	unsigned int array_size;
	unsigned int nb_existing;

}iceEntityManager;

typedef struct {

// Core
// -------------------------------


	// Entity 
	unsigned int entitymanager_nb;
	iceEntityManager *entitymanager;

	// Data 
	unsigned int data_nb;
	void** data;

	// Input 
	iceInput *input;

	// Time 
	iceTime time;

	// OTHER 
	int returnvalue;
	iceColor background;



// Graphics
// -------------------------------


	// Drawer 
	iceDrawer drawer;

	// Texture 
	unsigned int texturemanager_nb;
	iceTextureManager *texturemanager;

	// Font 
	iceFontManager fontmanager;

	// Text 
	unsigned int labelmanager_nb;
	iceLabelManager *labelmanager;

	// Gui 
	unsigned int guimanager_nb;
	iceGuiManager *guimanager;

	// Camera
	iceCamera camera;


// Audio
// -------------------------------

	// Sound 
	iceSoundManager soundmanager;

// Physics
// -------------------------------

	// Physics
	icePhysicsManager physicsmanager;

} iceGame;


#endif