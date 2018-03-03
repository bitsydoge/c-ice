#include "hdr/Terminal_private.h"

#include "external/rlutil.h"

void ICE_TermSaveColor()
{
	saveDefaultColor();
}

void ICE_TermHideCursor()
{
	hidecursor();
}