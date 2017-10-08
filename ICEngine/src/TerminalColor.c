#include "hdr/TerminalColor.h"
#include "external/rlutil.h"

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
void ICE_TC_SetBackgroundColor(int c)
{
    setBackgroundColor(c);
}