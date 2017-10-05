#include "hdr/TerminalColor.h"

void ICE_TC_SaveColor()
{
    saveDefaultColor();    
}

void ICE_TC_ResetColor()
{
    resetColor();    
}

void ICE_TC_SetColor(int c)
{
    setColor(c);
}