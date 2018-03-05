#ifndef DEF_ICE_TYPESCORE
#define DEF_ICE_TYPESCORE

#include "Array.h"
#include "StringDyn.h"
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
	#define ICE_NULL -1	
	#define ICE_Null -1
	#define ICE_null -1
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

enum ICE_NodeType
{
	ICE_NODETYPE_VOID = 0,
	ICE_NODETYPE_SPRITE = 1,
	ICE_NODETYPE_COLLIDER = 2,
	ICE_NODETYPE_LABEL = 3,
	ICE_NODETYPE_MAP = 4,
	ICE_NODETYPE_GUI = 5

}; typedef enum ICE_NodeType ICE_NodeType;

// --------------------------------------

struct ICE_Node
{
	// Attribute
	// ----------------------
	ICE_String name;
	ICE_Float x, y;

	ICE_NodeType type;
	unsigned int man, item;
	void* component;

	// Tree
	// ----------------------
	ICE_Bool haveParent;
	//ICE_Node *parent;

	ICE_Bool haveChild;
	//ICE_Node *childArray;

}; typedef struct ICE_Node ICE_Node;

// --------------------------------------

struct ICE_Game {
	
	ICE_Window window;
	ICE_Camera camera;
	ICE_Time time;

	// Config
	ICE_Bool debug;

}; typedef struct ICE_Game ICE_Game;

// --------------------------------------

struct ICE_Asset
{
	ICE_Font font;

}; typedef struct ICE_Asset ICE_Asset;

#endif
