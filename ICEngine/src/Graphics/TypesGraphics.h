﻿#ifndef DEF_ICE_TYPESGRAPHICS
#define DEF_ICE_TYPESGRAPHICS

#include "../Maths/TypesMaths.h"
#include "../Framework/TypesFramework.h"
#include "../Core/SDL2_Includer.h"

#include ICE_INCLUDE_SDL2_TTF

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

/**
 * \brief Color in the Engine, it's a uint32_t for 8 bits per value (R, G, B, A)
 */
typedef uint32_t ICE_Color;

/**
 * \brief Texture struct handling sdl texture
 */
struct ICE_Texture
{
	ICE_Id id;

	ICE_Bool	 exist;
	unsigned int w, h;
	SDL_Texture* handle;
};

typedef struct ICE_Texture ICE_Texture;

/**
 * \brief Texture Manager
 */
struct ICE_TextureManager
{
	ICE_Bool isFree;

	ICE_Id texture_size;
	ICE_Id texture_contain;
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
	ICE_Id step_size;
	ICE_Id step_contain;
	ICE_AnimationStep * step;

} ICE_Animation;

typedef struct
{
	ICE_Id index;
	ICE_Bool exist;

	ICE_Bool have_texture_defined;
	ICE_Id texture_index;

	unsigned int size_w, size_h;
	ICE_Id number_frame_w, number_frame_h;

	ICE_Id animation_size;
	ICE_Id animation_contain;
	ICE_Animation * animation;

} ICE_Sprite;

typedef struct
{
	ICE_Bool isFree;

	ICE_Id sprite_size;
	ICE_Id sprite_contain;
	ICE_Sprite* sprite;

} ICE_SpriteManager;

typedef enum
{
	ICE_GUITYPE_RECTANGLE,
	ICE_GUITYPE_IMAGE

} ICE_GuiType;

typedef struct
{
	ICE_Bool exist;
	ICE_Bool have_texture_defined;
	ICE_Id texture_index;
	ICE_Id old_texture_index;
	ICE_Id texturemanager_index;
	ICE_Id old_texturemanager_index;
	ICE_Box box;
	ICE_Box old_box;

	ICE_GuiType type;
	ICE_Texture texture_cache;

} ICE_Gui;

typedef struct
{
	ICE_Bool isFree;

	ICE_Id gui_size;
	ICE_Id gui_contain;
	ICE_Gui* gui;

} ICE_GuiManager;

#endif

