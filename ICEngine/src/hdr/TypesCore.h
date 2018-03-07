#ifndef DEF_ICE_TYPESCORE
#define DEF_ICE_TYPESCORE

#include "String_.h"
#include "TypesMaths.h"
#include "TypesGraphics.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Typedef
// --------------------------------------

#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED
	typedef int ICE_Bool;
	#define ICE_True 1
	#define ICE_TRUE 1
	#define ICE_true 1
	#define ICE_False 0
	#define ICE_FALSE 0
	#define ICE_false 0
	#define ICE_BOOLNONE -1	
	#define ICE_BoolNone -1
	#define ICE_boolnone -1
#endif

// Struct
// --------------------------------------

struct ICE_Time {

	//unsigned long actual;
	//unsigned long last;
	//double ticks;
	//unsigned int ticksEllapsed;
	ICE_Float fps;
	ICE_Float delta;

}; typedef struct ICE_Time ICE_Time;

// --------------------------------------

struct ICE_Input {

	int key[512];
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

}; typedef struct ICE_Input ICE_Input;

// --------------------------------------

struct ICE_Window
{
	ICE_String title;
	unsigned int w, h;

	SDL_Window *handle;
	SDL_Renderer *render;
	ICE_Color background;
	ICE_Input input;

}; typedef struct ICE_Window ICE_Window;

// --------------------------------------

struct ICE_Camera
{
	ICE_Float x, y, w, h;

}; typedef struct ICE_Camera ICE_Camera;

// --------------------------------------

struct ICE_Font
{
	TTF_Font* size[256];

}; typedef struct ICE_Font ICE_Font;

// --------------------------------------

typedef struct
{
	// Main
	ICE_Bool active;
	ICE_Float x, y;

	// Label Value
	ICE_String text;
	int size;
	ICE_Color color;

	ICE_String old_text;
	int old_size;
	ICE_Color old_color;
	
	//ICE_Texture texture;
	ICE_Bool isFixedToWorld;


} ICE_Label;

typedef struct
{
	ICE_Bool isFree;
	unsigned int label_size;
	unsigned int label_contain;
	ICE_Label* label;

} ICE_LabelManager;





// BIG OBJECT
// --------------------------------------
// --------------------------------------
// --------------------------------------
// --------------------------------------
// --------------------------------------
// --------------------------------------
// --------------------------------------
// --------------------------------------
// --------------------------------------





struct ICE_Game {
	
	// Main
	ICE_Window window;
	ICE_Camera camera;
	ICE_Time time;

	// Label
	unsigned int label_mngr_nb;
	ICE_LabelManager *label_mngr;

}; typedef struct ICE_Game ICE_Game;



// --------------------------------------
// --------------------------------------
// --------------------------------------



struct ICE_Asset
{
	ICE_Font font;

}; typedef struct ICE_Asset ICE_Asset;

#endif
