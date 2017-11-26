#ifndef DEF_ICE_STRUCTGRAPHICS
#define DEF_ICE_STRUCTGRAPHICS

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "StructMaths.h"

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

	int man;

} iceCameraManager;

typedef struct {

	float x, y;
	int w, h;
	float speed;

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
	int texture_nb;
	int texturemanager;
	iceBox box;
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

