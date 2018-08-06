#ifndef DEF_ICE_TYPESCORE
#define DEF_ICE_TYPESCORE

#include "../Framework/String_.h"
#include "../Graphics/TypesGraphics.h"
#include "../Audio/TypesAudio.h"

#include "SDL2_Includer.h"

#include ICE_INCLUDE_SDL2
#include ICE_INCLUDE_SDL2_TTF

// Typedef
// --------------------------------------

#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED
/**
* \brief A special bool that can be equal to 0(ICE_False) 1(ICE_True)
*/
typedef _Bool ICE_Bool;
#define ICE_True 1
#define ICE_TRUE 1
#define ICE_true 1
#define ICE_False 0
#define ICE_FALSE 0
#define ICE_false 0

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
struct ICE_Input 
{

	ICE_Bool				key[512];
	ICE_Bool				wheelup;
	ICE_Bool				wheeldown;
	ICE_Bool				quit;
	ICE_Bool				leftclic;
	ICE_Bool				rightclic;
	unsigned int			mousex;
	unsigned int			mousey;
	ICE_Bool				focus;
	ICE_String				filedrop;

}; typedef struct ICE_Input ICE_Input;

// --------------------------------------

/**
 * \brief A struct that keep SDL handler (Window, renderer), Values (Title, Size ...) and Input struct
 */
struct ICE_Window
{
	ICE_String				title;
	ICE_Float				w, h;

	SDL_Window *			handle;
	SDL_Renderer *			render;
	ICE_Bool				auto_render;
	ICE_Bool				auto_clear;
	ICE_Input				input;

}; typedef struct ICE_Window ICE_Window;

// --------------------------------------

/**
 * \brief Camera that render the scene
 */
struct ICE_Camera
{
	ICE_Float				x, y;

}; typedef struct ICE_Camera ICE_Camera;

// --------------------------------------

/**
 * \brief A ICE Font that keep the font from 1 to 255 in size
 */
struct ICE_Font
{
	TTF_Font*				size[256];

}; typedef struct ICE_Font ICE_Font;

// --------------------------------------


enum ICE_LabelType
{
	ICE_LabelType_Screen = 0,
	ICE_LabelType_World = 1
};

/**
 * \brief A struct that is a text on screen, contain Size, Color and String in it
 */
struct ICE_Label
{
	// Main
	ICE_Bool				active;
	ICE_Float				x, y;

	// Label Value
	ICE_String				text;
	int						size;
	ICE_Color				color;
	int						wrap_width;

	ICE_String				old_text;
	int						old_size;
	ICE_Color				old_color;
	int						wrap_width_old;

	ICE_Float				angle;



	//ICE_Texture texture;
	enum ICE_LabelType		labelType;

	ICE_Texture				texture;


}; typedef struct ICE_Label ICE_Label;

/**
 * \brief Manager of Label
 */
struct ICE_LabelManager
{
	ICE_Bool				isFree;

	ICE_Index					label_size;
	ICE_Index					label_contain;
	ICE_Label*				label;

}; typedef struct ICE_LabelManager ICE_LabelManager;

// --------------------------------------

/**
* \brief A struct that is a text on screen, contain Size, Color and String in it
*/
struct ICE_Entity
{
	// Main
	ICE_Bool				active;

	ICE_Float				x, y;
	ICE_Float				w, h;
	ICE_Float				angle;

	// Polar Movement Save
	ICE_Bool				already_moved_polar;
	ICE_Float				x_polar_destination_move;
	ICE_Float				y_polar_destination_move;
	ICE_Float				r_polar_destination_move;
	ICE_Float				x_polar_shift_move;
	ICE_Float				y_polar_shift_move;
	ICE_Float				polar_distance_r_r;
	////////////////////////////

	ICE_Bool				have_graphics;
	ICE_Bool				use_sprite;

	// Texture location
	ICE_Index					graphics_mngr_index;
	ICE_Index					graphics_index;

	// Data Array
	ICE_Index					data_nb;
	void **					data;

}; typedef struct ICE_Entity ICE_Entity;

/**
* \brief Manager of Label
*/
struct ICE_EntityManager
{
	ICE_Bool				isFree;

	ICE_Index					entity_size;
	ICE_Index					entity_contain;
	ICE_Entity*				entity;

}; typedef struct ICE_EntityManager ICE_EntityManager;

// BIG OBJECT
// --------------------------------------

struct ICE_ObjectManager
{
	// Camera
	ICE_Camera				camera;

	// Label
	ICE_Index					label_mngr_nb;
	ICE_LabelManager *		label_mngr;
	
	// Gui
	ICE_Index					gui_mngr_nb;
	ICE_GuiManager *		gui_mngr;

	// Entity
	ICE_Index					entity_mngr_nb;
	ICE_EntityManager *		entity_mngr;

	// Sprite
	ICE_Index					sprite_mngr_nb;
	ICE_SpriteManager *		sprite_mngr;

	// Data
	ICE_Index					data_nb;
	void**					data;

}; typedef struct ICE_ObjectManager ICE_ObjectManager;

/**
* \brief Current function used by the engine
*/
struct ICE_State
{
	ICE_Bool				quit;
	ICE_Bool				isPaused;
	ICE_Bool				isFree;

	void					(*func_create)(void);
	void					(*func_update)(void);
	void					(*func_destroy)(void);

	void					(*func_resume)(void);
	void					(*func_pause)(void);

	ICE_ObjectManager		object;

	ICE_Color				background;

	struct ICE_State *		parent;

}; typedef struct ICE_State ICE_State;


/**
 * \brief The god object of the game with everything in it exept for Assets
 */
struct ICE_Game {
	
	// Main
	ICE_Window				window;
	ICE_Time				time;

	// State
	ICE_State				state_main;
	ICE_State*				current;

	// Debug
	void(*lateDrawDebug)();

	// Args
	int argc; 
	char **argv;

}; typedef struct ICE_Game ICE_Game;



// --------------------------------------



/**
 * \brief Assets of the game (Image, Sound, Font ...)
 */
struct ICE_Asset
{
	// Font
	ICE_Index					font_mngr_nb; // todo
	ICE_Font				font;

	// Texture
	ICE_Index					texture_mngr_nb;
	ICE_TextureManager *	texture_mngr;

	// Sound
	ICE_Index					sound_mngr_nb;
	ICE_SoundManager *		sound_mngr;

	// Music
	ICE_Index					music_mngr_nb;
	ICE_MusicManager *		music_mngr;

}; typedef struct ICE_Asset ICE_Asset;

#endif
