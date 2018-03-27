#include "hdr/Terminal_private.h"

#include "external/rlutil.h"

void ICE_Term_SaveColor()
{
	saveDefaultColor();
}

void ICE_Term_HideCursor()
{
	hidecursor();
}