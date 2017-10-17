#ifndef DEF_ICE_GAME
#define DEF_ICE_GAME

#include "Struct.h"


void ICE_SetWindowIcon(ICE_Window *window, char * path);
ICE_Game ICE_CreateApp(char *window_title, const unsigned int width_window, const unsigned int height_window);
void ICE_DestroyGame(ICE_Game *app);


#endif