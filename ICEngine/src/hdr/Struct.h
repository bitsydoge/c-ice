#ifndef DEF_ICE_STRUCT
#define DEF_ICE_STRUCT

#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>

typedef struct
{
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

} ICE_Input;

typedef struct
{
	unsigned short exist;
	unsigned int w;
	unsigned int h;
	SDL_Texture* handle;

} ICE_Texture;

typedef struct
{
	unsigned short array_size;
	unsigned short nb_existing_texture;
	ICE_Texture* texturepack;
} ICE_TextureManager;

typedef struct
{
	unsigned short size_music;
	Mix_Music *music;
	unsigned short tofill_music;
	unsigned short size_sound;
	Mix_Chunk *sound;
	unsigned short tofill_sound;
} ICE_SoundManager;

typedef struct 
{
	SDL_Window *window;
	SDL_Renderer *render;
	ICE_Input *input;
	unsigned int w, h;
	unsigned short texturemanager_size;
	ICE_TextureManager *tex_man;
	ICE_SoundManager sound_system;

} ICE_Game;

//SDL typedef layer
typedef struct SDL_Rect ICE_Rect;
typedef struct SDL_Point ICE_Point;
typedef struct SDL_Window ICE_Window;

#endif
