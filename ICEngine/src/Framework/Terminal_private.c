#include "Terminal_private.h"

#include "../External/rlutil/rlutil.h"

void ICE_Term_SaveColor()
{
	saveDefaultColor();
}

void ICE_Term_HideCursor()
{
	hidecursor();
}