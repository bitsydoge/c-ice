#ifndef DEF_ICE_TYPESGRAPHICS
#define DEF_ICE_TYPESGRAPHICS

#include "../Maths/TypesMaths.h"
#include "../Framework/TypesFramework.h"
#include "../Core/SDL2_Includer.h"

#include ICE_INCLUDE_SDL2_TTF

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

/**
 * \brief Color in the Engine, it's a uint32_t for 8 bits per value (R, G, B, A)
 */
typedef uint32_t ICE_Color;

/**
 * \brief Texture struct handling sdl texture
 */
struct ICE_Texture
{
	ICE_ID id;
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

	ICE_ID texture_size;
	ICE_ID texture_contain;
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
	ICE_ID step_size;
	ICE_ID step_contain;
	ICE_AnimationStep * step;

} ICE_Animation;

typedef struct
{
	ICE_ID index;
	ICE_Bool exist;

	ICE_Bool have_texture_defined;
	ICE_ID texture_index;

	unsigned int size_w, size_h;
	ICE_Index number_frame_w, number_frame_h;

	ICE_ID animation_size;
	ICE_ID animation_contain;
	ICE_Animation * animation;

} ICE_Sprite;

typedef struct
{
	ICE_Bool isFree;

	ICE_ID sprite_size;
	ICE_ID sprite_contain;
	ICE_Sprite * sprite;

} ICE_SpriteManager;

typedef enum
{
	ICE_GUITYPE_9PATCH,
	ICE_GUITYPE_IMAGE,
	ICE_GUITYPE_TEXT

} ICE_GuiType;

typedef struct
{
	ICE_BOOL_BITFIELD(exist);
	ICE_BOOL_BITFIELD(active);

	ICE_BOOL_BITFIELD(have_texture_defined);
	ICE_ID texture_index;
	ICE_ID old_texture_index;
	ICE_ID texturemanager_index;
	ICE_ID old_texturemanager_index;
	ICE_Box box;
	ICE_Box old_box;

	ICE_GuiType type;
	ICE_Texture texture_cache;

} ICE_Gui;

typedef struct
{
	ICE_Bool isFree;

	ICE_ID gui_size;
	ICE_ID gui_contain;
	ICE_Gui* gui;

} ICE_GuiManager;

#endif
