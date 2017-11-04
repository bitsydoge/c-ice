#ifndef DEF_ICE_GAME
#define DEF_ICE_GAME
#include "Struct.h"

void ICE_SetWindowIcon(ICE_Window *window, char * path);
ICE_Game ICE_CreateGame(char *window_title, const unsigned int width_window, const unsigned int height_window);
void* ICE_AddData(ICE_Game *game, size_t _size);
void* ICE_GetData(ICE_Game *game, int nb_data);
void ICE_DestroyGame(ICE_Game *app);

#endif