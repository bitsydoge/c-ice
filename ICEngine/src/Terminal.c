#include "hdr/Terminal.h"

void ICE_TermSaveColor()
{
    saveDefaultColor();    
}
void ICE_TermResetColor()
{
    resetColor(); 
}
void ICE_TermSetColor(int c)
{
    setColor(c);
}
void ICE_TermSetBgColor(int c)
{
    setBackgroundColor(c);
}