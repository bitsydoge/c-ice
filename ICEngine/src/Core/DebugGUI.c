#include "DebugGUI.h"

#if defined(_DEBUG) && !defined(__APPLE__) && defined (_IUP_DEBUGUI_USE)
#include "IUP/iup.h"
#include "Game.h"
#include <string.h>

extern ICE_Game game;

void ICE_DebugGUI_Init()
{
	IupOpen(&game.argc, &game.argv);
	game.guiDebugThread = SDL_CreateThread(ICE_DebugGUI_ThreadFunction, "DebugGUI_IUP", NULL);
}

void ICE_DebugGUI_ThreadFunction()
{
	IupMessageError(NULL, "Hello !!");
}

void ICE_DebugGUI_Close()
{
	IupClose();
}

#endif

