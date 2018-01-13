#ifndef DEF_ICE_TYPESGRAPHICS
#define DEF_ICE_TYPESGRAPHICS

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "TypesMaths.h"

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

#ifndef ICE_FLOAT_DEFINED
#define ICE_FLOAT_DEFINED
typedef double iceFloat;
#endif

typedef SDL_Window iceWindow;
typedef SDL_Renderer iceRenderer;
typedef Uint32 iceColor;


///////////////////////////////////////////////////////////////////
//                                                               //
// Drawer                                                        //
//                                                               //
///////////////////////////////////////////////////////////////////


typedef struct
{
	iceWindow *window;
	iceRenderer *render;
	iceBox pos;

	// State
	iceBool isVisible;
	iceBool isResizable;
	iceBool isFullScreen;
	iceBool isBorderLess;

} iceDrawer;


///////////////////////////////////////////////////////////////////
//                                                               //
// Camera                                                       //
//                                                               //
///////////////////////////////////////////////////////////////////

typedef struct {
	float x, y;
	int w, h;
	float speed;

	// Entity Attachement
	iceBool isAttachedToEntity;
	int entity_manager_attached;
	int entity_attached;
	iceFloat attach_shift_x;
	iceFloat attach_shift_y;

} iceCamera;


///////////////////////////////////////////////////////////////////
//                                                               //
// Texture                                                       //
//                                                               //
///////////////////////////////////////////////////////////////////


typedef struct {

	int exist;
	int w;
	int h;
	SDL_Texture* handle;

} iceTexture;

typedef struct {

	int array_size;
	int nb_existing;
	iceTexture* texture;
	iceRenderer *ren;

} iceTextureManager;


///////////////////////////////////////////////////////////////////
//                                                               //
// Sprite made from charset or sprite made from different texture//
//                                                               //
///////////////////////////////////////////////////////////////////


typedef enum
{
	ICE_SPRITE_CHARSET,
	ICE_SPRITE_ADDITIVE
} iceSpriteType;

typedef struct
{
	iceSpriteType type;
	iceTexture *handle_texture;
	int w_size;
	int h_size;
	int w_size_tile;
	int h_size_tile;

} iceSprite;

typedef struct
{
	int x;
} iceSpriteManager;


///////////////////////////////////////////////////////////////////
//                                                               //
// Gui : rectangle 9x9, background fixed to camera,              //
// background movable                                            //
//                                                               //
///////////////////////////////////////////////////////////////////


typedef enum
{
	ICE_RECTANGLE,
	ICE_GUI_BACKGROUND_FIXED,
	ICE_GUI_BACKGROUND_FREE

} iceGuiType;

typedef struct
{
	iceBool exist;
	iceBool have_texture_defined;

	int texture_nb;
	int old_texture_nb;
	int texturemanager;
	int old_texturemanager;
	iceBox box;
	iceBox old_box;

	iceGuiType type;
	iceTexture texture_cache;

} iceGui;

typedef struct
{
	int array_size;
	int nb_existing;
	iceGui* gui;

} iceGuiManager;


///////////////////////////////////////////////////////////////////
//                                                               //
// Text and Text with border                                     //
//                                                               //
///////////////////////////////////////////////////////////////////


typedef enum
{
	ICE_TEXT_NORMAL,
	ICE_TEXT_BLACK_BG

} iceTextType;

typedef struct
{
	iceBool exist;
	iceVect pos;

	char * text;
	char * old_text;
	int old_size;
	int size;
	iceColor color;
	iceColor old_color;

	iceTexture texture;
	iceBool isFixedToWorld;


} iceLabel;

typedef struct
{
	int array_size;
	int nb_existing;
	iceLabel* text;

} iceLabelManager;


///////////////////////////////////////////////////////////////////
//                                                               //
// To change, for now we only use the Font in the                //
//                                                               //
///////////////////////////////////////////////////////////////////


typedef struct
{
	TTF_Font* size[256];

}iceFont;

typedef struct {

	TTF_Font* size[256];

}iceFontManager;


#endif
