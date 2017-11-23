#ifndef DEF_iceSTRUCT
#define DEF_iceSTRUCT

#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Rect.h"

//SDL typedef layer
typedef SDL_Window iceWindow;
typedef SDL_Renderer iceRenderer;

typedef struct
{
	
	int *tile;

} iceLayer;

typedef struct{

	// Map Size
	int w, h;
	int tile_w, tile_h;

	// Layer
	int nb_layer;
	iceLayer *layer;

} iceMap;

typedef struct{

	float x, y;
	int w, h;
	float speed;

} iceCamera;

typedef struct{

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

} iceInput;

typedef struct{

	int exist;
	int w;
	int h;
	SDL_Texture* handle;

} iceTexture;

typedef struct{

	int array_size;
	int nb_existing_texture;
	iceTexture* texture;
	SDL_Renderer *ren;

} iceTextureManager;

typedef struct{

	Mix_Music* music;
	char *filename;

} iceMusic;

typedef struct{

	Mix_Chunk* sound;
	char *filename;

} iceSound;


typedef struct{

	unsigned short size_musicpack;
	iceMusic* musicpack;
	unsigned short tofill_music;
	unsigned short size_soundpack;
	iceSound* soundpack;
	unsigned short tofill_soundpack;

} iceSoundManager;

typedef struct{

	unsigned long actual;
	unsigned long last;
	double ticks;
	unsigned int ticksEllapsed;                                                                    
	double fps;
	double delta;

} iceTime;


////
//
//  I need to make a iceFont struct where
//
////

typedef struct{

	TTF_Font* size[256];

}iceFontManager;

typedef struct{

	iceBool exist;
	
	// Position
	iceFloat x, y;
	iceFloat angle;

	// Size
	iceFloat w, h;
	
	// Data Array
	void **data;
	
	// Texture location
	iceBool have_texture;
	unsigned int man;
	unsigned int text;

}iceEntity;

typedef struct{

	iceEntity *entity;
	unsigned long array_size;
	unsigned long nb_existing;

}iceEntityManager;

typedef struct {
	int returnvalue;

	// Window
	iceWindow *window;
	iceRenderer *render;
	
	// Input
	iceInput *input;

	// Time
	iceTime time;

	// Camera
	iceCamera camera;

	//// Manager ////
	// Texture //
	
	unsigned int texturemanager_size;
	iceTextureManager *texturemanager;

	// Sound // Only One soundmanager at a time
	iceSoundManager soundmanager;

	// Font // Only one for now
	iceFontManager fontmanager;

	// Entity // Multiple
	unsigned int entitymanager_size;
	iceEntityManager *entitymanager;

	// Data // 
	int nb_data;
	void** data;

} iceGame;

#endif
