#include "DebugGUI.h"

#if defined(_DEBUG) && !defined(__APPLE__) && defined (_IUP_DEBUGUI_USE)
#include "IUP/iup.h"
#include "Game.h"
#include <string.h>

extern ICE_Game game;

void ICE_DebugGUI_ThreadStart()
{
	IupOpen(&game.argc, &game.argv);
	game.guiDebugThread = SDL_CreateThread(ICE_DebugGUI_ThreadFunction, "DebugGUI_IUP", NULL);
}

int btn_exit_cb(Ihandle *self)
{
	/* Exits the main loop */
	return IUP_CLOSE;
}

void ICE_DebugGUI_ThreadFunction()
{
	Ihandle *dlg, *button, *label, *vbox;

	label = IupLabel("Hello world from IUP.");
	button = IupButton("OK", NULL);
	vbox = IupVbox(
		label,
		button,
		NULL);
	IupSetAttribute(vbox, "ALIGNMENT", "ACENTER");
	IupSetAttribute(vbox, "GAP", "10");
	IupSetAttribute(vbox, "MARGIN", "10x10");

	dlg = IupDialog(vbox);
	IupSetAttribute(dlg, "TITLE", "Hello World 5");

	/* Registers callbacks */
	IupSetCallback(button, "ACTION", (Icallback)btn_exit_cb);

	IupShowXY(dlg, IUP_CENTER, IUP_CENTER);

	IupMainLoop();
}

void ICE_DebugGUI_Close()
{
	IupClose();
}

#endif

