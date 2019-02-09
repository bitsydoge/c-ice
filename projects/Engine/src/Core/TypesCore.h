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

#ifndef ICE_INDEX_DEFINED
#define ICE_INDEX_DEFINED
typedef size_t ICE_ID;
typedef size_t ICE_Index;
typedef size_t ICE_Timer;
#endif

#ifndef ICE_INDEX_CORETYPE_DEFINED
#define ICE_INDEX_CORETYPE_DEFINED

typedef ICE_ID ICE_EntityID;
typedef ICE_ID ICE_LabelID;
typedef ICE_ID ICE_GuiID;

typedef ICE_ID ICE_SpriteID;
typedef ICE_ID ICE_TextureID;
typedef ICE_ID ICE_FontID;
typedef ICE_ID ICE_SoundID;
typedef ICE_ID ICE_MusicID;
typedef ICE_ID ICE_DataID;

#endif

#ifndef ICE_BOOL_DEFINED
#define ICE_BOOL_DEFINED
typedef _Bool ICE_Bool;
#define ICE_True 1
#define ICE_TRUE 1
#define ICE_true 1
#define ICE_False 0
#define ICE_FALSE 0
#define ICE_false 0
#define ICE_BOOL_BITFIELD(S) ICE_Bool S : 1
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

	ICE_Bool				Pressed[512];
	ICE_Bool				OnPress[512];
	ICE_Bool				OnRelease[512];
	ICE_BOOL_BITFIELD		(wheelup);
	ICE_BOOL_BITFIELD		(wheeldown);
	ICE_BOOL_BITFIELD		(quit);

	ICE_BOOL_BITFIELD		(leftclic_pressed);
	ICE_BOOL_BITFIELD		(rightclic_pressed);
	ICE_BOOL_BITFIELD		(leftclic_OnPress);
	ICE_BOOL_BITFIELD		(rightclic_OnPress);
	ICE_BOOL_BITFIELD		(leftclic_OnRelease);
	ICE_BOOL_BITFIELD       (rightclic_OnRelease);

	ICE_BOOL_BITFIELD		(focus);
	unsigned int			mousex;
	unsigned int			mousey;
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
	ICE_LABELTYPE_SCREEN = 0,
	ICE_LABELTYPE_WORLD = 1
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

	ICE_ID				label_size;
	ICE_ID				label_contain;
	ICE_Label*				label;

}; typedef struct ICE_LabelManager ICE_LabelManager;

// --------------------------------------

enum ICE_EntityGraphicsType
{
	ICE_ENTITYGRAPHICSTYPES_NONE = 0,
	ICE_ENTITYGRAPHICSTYPES_TEXTURE = 1,
	ICE_ENTITYGRAPHICSTYPES_SPRITE = 2,
	ICE_ENTITYGRAPHICSTYPES_TEXT = 3,
	ICE_ENTITYGRAPHICSTYPES_PRIMITIVES = 4

}; typedef enum ICE_EntityGraphicsType ICE_EntityGraphicsType;

/**
* \brief A struct that is a text on screen, contain Size, Color and String in it
*/
struct ICE_Entity
{
	// Main
	ICE_EntityID			id;
	ICE_Uint32				timestamp;
	ICE_Bool				exist;
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
	// Graphics

	ICE_EntityGraphicsType  graphics_type;
	ICE_ID					graphics_mngr_index;
	ICE_ID					graphics_index;	
	ICE_ID					sprite_frame;
	ICE_Box					graphics_box_render;

	// Data Array
	ICE_ID					data_nb;
	void **					data;

	// Function
	ICE_Bool				haveFunctionDefined;
	ICE_Bool				alreadyRunnedCreate;
	void					(*func_create)(struct ICE_Entity*);
	void					(*func_update)(struct ICE_Entity*);
	void					(*func_destroy)(struct ICE_Entity*);

}; typedef struct ICE_Entity ICE_Entity;

/**
* \brief Manager of Label
*/
struct ICE_EntityManager
{
	ICE_Bool				isFree;

	ICE_ID				entity_size;
	ICE_ID				entity_contain;
	ICE_Entity*				entity;

}; typedef struct ICE_EntityManager ICE_EntityManager;

// BIG OBJECT
// --------------------------------------

struct ICE_GameObjectManager
{
	// Camera
	ICE_Camera			camera;

	// Label
	ICE_LabelManager 	label_mngr;
	
	// Gui
	ICE_GuiManager	gui_mngr;

	// Entity
	ICE_EntityManager entity_mngr;

	// Data
	ICE_ID				data_nb;
	void**				data;

}; typedef struct ICE_GameObjectManager ICE_ObjectManager;

/**
* \brief Current function used by the engine
*/
struct ICE_State
{
	ICE_String name;
	ICE_Bool				quit;
	ICE_Bool				isPaused;
	ICE_Bool				isFree;

	void					(*func_create)(void);
	void					(*func_update)(void);
	void					(*func_destroy)(void);

	void					(*func_OnResume)(void);
	void					(*func_OnPause)(void);

	ICE_ObjectManager		object;

	ICE_Color				background;

	struct ICE_State *		parent;

}; typedef struct ICE_State ICE_State;


struct ICE_Core
{
	// Main
	ICE_Window				window;
	ICE_Time				time;

	// Path
	ICE_Char				basePath[1024];
	ICE_Char				dataPath[1024];

	// Args
	int						argc;
	char					**argv;

#if defined(_DEBUG)

	// Debug
	void(*lateDrawDebug)();

#endif

}; typedef struct ICE_Core ICE_Core;


/**
 * \brief The god object of the GAME with everything in it exept for Assets
 */
struct ICE_Game {
	
	// State
	ICE_State state_main;
	ICE_State* current;

}; typedef struct ICE_Game ICE_Game;



// --------------------------------------

struct ICE_Config
{
	unsigned int window_w, window_h;

	unsigned int refresh_rate;

	ICE_Uint8 fullscreen;
	ICE_Bool resizable;
	ICE_Bool vsync;

	ICE_StringStd editor_name;
	ICE_StringStd product_name;
	ICE_StringStd title;
	ICE_StringStd window_icon;
	ICE_StringStd game_version;

	int argc;
	char ** argv;

}; typedef struct ICE_Config ICE_Config;

/**
 * \brief Assets of the GAME (Image, Sound, Font ...)
 */
struct ICE_Asset
{

	// GRAPHICS //
	// Font
	ICE_Font font;
	// Texture
	ICE_TextureManager texture_mngr;
	ICE_Texture texture_error;

	// Sprite
	ICE_SpriteManager sprite_mngr;

	// AUDIO //
	// Sound
	ICE_SoundManager sound_mngr;
	// Music
	ICE_MusicManager music_mngr;

}; typedef struct ICE_Asset ICE_Asset;

#endif
