#ifndef DEF_ICE_TYPESGRAPHICS
#define DEF_ICE_TYPESGRAPHICS
#include <SDL2/SDL.h>
#include "../Maths/TypesMaths.h"

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

/**
 * \brief Color in the Engine, it's a uint32_t for 8 bits per value (R, G, B, A)
 */
typedef Uint32 ICE_Color;

/**
 * \brief Texture struct handling sdl texture
 */
struct ICE_Texture
{
	ICE_Bool			exist;
	size_t w, h;
	SDL_Texture* handle;
};

typedef struct ICE_Texture ICE_Texture;

/**
 * \brief Texture Manager
 */
struct ICE_TextureManager
{
	ICE_Bool isFree;

	size_t texture_size;
	size_t texture_contain;
	ICE_Texture* texture;
};

typedef struct ICE_TextureManager ICE_TextureManager;

typedef struct
{
	unsigned int sprite_index;
	ICE_Float duration;
	ICE_Float actual_time;

} ICE_AnimationStep;

typedef struct
{
	unsigned int actual_step;

	size_t step_size;
	size_t step_contain;
	ICE_AnimationStep * step;

} ICE_Animation;

typedef struct
{
	ICE_Bool exist;

	ICE_Bool have_texture_defined;
	size_t texture_index;
	size_t texturemanager_index;

	unsigned int size_w, size_h;

	size_t animation_size;
	size_t animation_contain;
	ICE_Animation * animation;

} ICE_Sprite;

typedef struct
{
	ICE_Bool isFree;

	size_t sprite_size;
	size_t sprite_contain;
	ICE_Sprite* sprite;

} ICE_SpriteManager;

typedef enum
{
	ICE_GUI_RECTANGLE,
	ICE_GUI_IMAGE

} ICE_GuiType;

typedef struct
{
	ICE_Bool exist;
	ICE_Bool have_texture_defined;
	size_t texture_index;
	size_t old_texture_index;
	size_t texturemanager_index;
	size_t old_texturemanager_index;
	ICE_Box box;
	ICE_Box old_box;

	ICE_GuiType type;
	ICE_Texture texture_cache;

} ICE_Gui;

typedef struct
{
	ICE_Bool isFree;

	size_t gui_size;
	size_t gui_contain;
	ICE_Gui* gui;

} ICE_GuiManager;

#endif

