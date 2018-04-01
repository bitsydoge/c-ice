#ifndef DEF_ICE_TYPESCORE
#define DEF_ICE_TYPESCORE

#include "../Framework/String_.h"
#include "../Graphics/TypesGraphics.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Typedef
// --------------------------------------

#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED
/**
	 * \brief A special bool that can be equal to 0(ICE_False) 1(ICE_True) or -1(ICE_BoolNone).
	 * The last one is for some function where the use of ICE_BoolNone is documented
	 */
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

#ifndef ICE_FLOAT_DEFINED
#define ICE_FLOAT_DEFINED
	typedef double ICE_Float;
#endif

// Struct
// --------------------------------------

/**
 * \brief Fps and Delta are here
 */
struct ICE_Time {

	ICE_Float fps;
	ICE_Float delta;

}; typedef struct ICE_Time ICE_Time;

// --------------------------------------

/**
 * \brief Input struct where every key state are kept
 */
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

/**
 * \brief A struct that keep SDL handler (Window, renderer), Values (Title, Size ...) and Input struct
 */
struct ICE_Window
{
	ICE_String title;
	unsigned int w, h;

	SDL_Window *handle;
	SDL_Renderer *render;
	ICE_Bool auto_render;
	ICE_Bool auto_clear;
	ICE_Color background;
	ICE_Input input;

}; typedef struct ICE_Window ICE_Window;

// --------------------------------------

/**
 * \brief Camera that render the scene
 */
struct ICE_Camera
{
	ICE_Float x, y, w, h;

}; typedef struct ICE_Camera ICE_Camera;

// --------------------------------------

/**
 * \brief A ICE Font that keep the font from 1 to 255 in size
 */
struct ICE_Font
{
	TTF_Font* size[256];

}; typedef struct ICE_Font ICE_Font;

// --------------------------------------

/**
 * \brief A struct that is a text on screen, contain Size, Color and String in it
 */
struct ICE_Label
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

	ICE_Texture texture;


}; typedef struct ICE_Label ICE_Label;

/**
 * \brief Manager of Label
 */
struct ICE_LabelManager
{
	ICE_Bool isFree;

	unsigned int label_size;
	unsigned int label_contain;
	ICE_Label* label;

}; typedef struct ICE_LabelManager ICE_LabelManager;



// BIG OBJECT
// --------------------------------------
// --------------------------------------
// --------------------------------------

struct ICE_ObjectManager
{
	// Label
	unsigned int label_mngr_nb;
	ICE_LabelManager *label_mngr;

}; typedef struct ICE_ObjectManager ICE_ObjectManager;

/**
* \brief Current function used by the engine
*/
struct ICE_State
{
	ICE_Bool quit;
	ICE_Bool hasBeenAlreadyRunOnce;

	void (*func_create)(void);
	void (*func_update)(void);
	void (*func_destroy)(void);

	ICE_ObjectManager object;

	struct ICE_State * parent;

}; typedef struct ICE_State ICE_State;


/**
* \brief Manager of State
*/
struct ICE_StateManager
{
	ICE_State * current;

}; typedef struct ICE_StateManager ICE_StateManager;

/**
 * \brief The god object of the game with everything in it exept for Assets
 */
struct ICE_Game {
	
	// Main
	ICE_Window window;
	ICE_Camera camera;
	ICE_Time time;

	// State
	ICE_State state_main;
	ICE_StateManager state_mngr;

}; typedef struct ICE_Game ICE_Game;



// --------------------------------------
// --------------------------------------
// --------------------------------------



/**
 * \brief Assets of the game (Image, Sound, Font ...)
 */
struct ICE_Asset
{
	ICE_Font font;

	unsigned int texture_mngr_nb;
	ICE_TextureManager *texture_mngr;

}; typedef struct ICE_Asset ICE_Asset;

#endif
