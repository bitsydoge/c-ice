#ifndef DEF_ICE_TYPESCORE
#define DEF_ICE_TYPESCORE

#include "Array.h"
#include "StringDyn.h"
#include <SDL2/SDL.h>

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
#endif

// Struct
// --------------------------------------

struct ICE_Time {

	unsigned long actual;
	unsigned long last;
	double ticks;
	unsigned int ticksEllapsed;
	double fps;
	double delta;

}; typedef struct ICE_Time ICE_Time;

// --------------------------------------

struct ICE_Input {

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

}; typedef struct ICE_Input ICE_Input;

// --------------------------------------

struct ICE_Window
{
	ICE_String title;
	int width, height;

	SDL_Window *handle;
	SDL_Renderer *render;
	ICE_Input input;
}; typedef struct ICE_Window ICE_Window;

// --------------------------------------

struct ICE_Game {
	
	ICE_Window window;

	ICE_Time time;

	// Config
	ICE_Bool debug;

}; typedef struct ICE_Game ICE_Game;

struct ICE_Asset
{
	int a;
}; typedef struct ICE_Asset ICE_Asset;

#endif
