#ifndef DEF_ICE_WINDOW
#define DEF_ICE_WINDOW

#include "TypesCore.h"

void ICE_Window_SetSize(int w, int h);
void ICE_Window_SetResizable(ICE_Bool yn);
void ICE_Window_SetFullscreen(ICE_Bool yn);
void ICE_Window_SetTitle(const char *title);
void ICE_Window_SetIcon(char * path);

int ICE_Window_GetW();
int ICE_Window_GetH();

#endif