#ifndef DEF_ICE_GAME
#define DEF_ICE_GAME

#include "Input.h"
#include "Type.h"
#include "TextureManager.h"

struct ICE_Game
{
	SDL_Window *window;
	SDL_Renderer *render;
	ICE_Input *input;
	unsigned int w, h;
	unsigned short texturemanager_size;
	ICE_TextureManager *tex_man;

};


ICE_Game ICE_CreateApp(char *window_title, const unsigned int width_window, const unsigned int height_window);
void ICE_DestroyGame(ICE_Game *app);


#endif