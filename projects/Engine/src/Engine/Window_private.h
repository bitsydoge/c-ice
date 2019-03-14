#ifndef DEF_ICE_WINDOW_PRIVATE_H
#define DEF_ICE_WINDOW_PRIVATE_H

#include "Window.h"

#include "../Framework/String_.h"

#include <SDL2/SDL.h>

struct ICE_Window
{
	ICE_String				title;
	int w, h;

	SDL_Window* handle;

}; typedef struct ICE_Window ICE_Window;

/**
 * \brief Set size of the window
 * \param w Width
 * \param h Height
 */
void ICE_Window_SetSize(int w, int h);

/**
 * \brief Set the window resizable or not
 * \param yn A Bool with the answer
 */
void ICE_Window_SetResizable(ICE_Bool yn);

/**
 * \brief Set the window fullscreen or not
 * \param yn A Bool with the answer
 */
void ICE_Window_SetFullscreen(int yn);

/**
 * \brief Set the window title
 * \param title The title of the window
 */
void ICE_Window_SetTitle(const char* title);

/**
 * \brief Set icon of the window from a file
 * \param path Path to the file
 */
void ICE_Window_SetIcon(char* path);

/**
 * \brief Get the width of the window
 * \return Width of the window
 */
int ICE_Window_GetW();

/**
 * \brief Get the height of the window
 * \return Height of the window
 */
int ICE_Window_GetH();

#endif