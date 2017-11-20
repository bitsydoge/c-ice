#ifndef DEF_ICE_STRUCT
#define DEF_ICE_STRUCT

#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

//SDL typedef layer
typedef SDL_Rect ICE_Rect;
typedef SDL_Point ICE_Point;
typedef SDL_Window ICE_Window;
typedef SDL_Renderer ICE_Renderer;
typedef Uint32 ICE_Color;
typedef char ICE_Bool;

typedef struct
{
	
	int *tile;

} ICE_Layer;

typedef struct{

	// Map Size
	int w, h;
	int tile_w, tile_h;

	// Layer
	int nb_layer;
	ICE_Layer *layer;

} ICE_Map;

typedef struct{

	float x, y;
	int w, h;
	float speed;

} ICE_Camera;

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

} ICE_Input;

typedef struct{

	int exist;
	int w;
	int h;
	SDL_Texture* handle;

} ICE_Texture;

typedef struct{

	int array_size;
	int nb_existing_texture;
	ICE_Texture* texture;
	SDL_Renderer *ren;

} ICE_TextureManager;

typedef struct{

	Mix_Music* music;
	char *filename;

} ICE_Music;

typedef struct{

	Mix_Chunk* sound;
	char *filename;

} ICE_Sound;


typedef struct{

	unsigned short size_musicpack;
	ICE_Music* musicpack;
	unsigned short tofill_music;
	unsigned short size_soundpack;
	ICE_Sound* soundpack;
	unsigned short tofill_soundpack;

} ICE_SoundManager;

typedef struct{

	unsigned long actual;
	unsigned long last;
	double ticks;
	unsigned int ticksEllapsed;                                                                    
	double fps;
	double delta;

} ICE_Time;


////
//
//  I need to make a ICE_Font struct where
//
////

typedef struct{

	TTF_Font* size[256];

}ICE_FontManager;

typedef struct{

	int exist;
	
	// Position
	float x, y;
	float angle;

	// Size
	float w, h;
	
	// Data Array
	void **data;
	
	// Texture location
	short has_texture;
	int man;
	int text;

}ICE_Entity;

typedef struct{

	ICE_Entity *entity;
	unsigned long array_size;
	unsigned long nb_existing;

}ICE_EntityManager;

typedef struct {
	int returnvalue;


	// Window
	ICE_Window *window;
	ICE_Renderer *render;
	
	// Input
	ICE_Input *input;

	// Time
	ICE_Time time;

	// Camera
	ICE_Camera camera;

	//// Manager ////
	// Texture //
	
	unsigned short texturemanager_size;
	ICE_TextureManager *texturemanager;

	// Sound // Only One soundmanager at a time
	ICE_SoundManager soundmanager;

	// Font // Only one for now
	ICE_FontManager fontmanager;

	// Entity // Multiple
	unsigned short entitymanager_size;
	ICE_EntityManager *entitymanager;

	// Data // 
	int nb_data;
	void** data;

} ICE_Game;

#endif
