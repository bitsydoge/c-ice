#include "Terminal_private.h"

#if defined(_DEBUG)

#include "../External/rlutil/rlutil.h"

void ICE_Term_SaveColor()
{
	saveDefaultColor();
}

void ICE_Term_HideCursor()
{
	hidecursor();
}

#endif