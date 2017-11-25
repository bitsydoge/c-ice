#include "hdr/Terminal.h"
#include "external/rlutil.h"

void iceTermSaveColor()
{
    saveDefaultColor();    
}
void iceTermResetColor()
{
    resetColor(); 
}
void iceTermSetColor(int c)
{
    setColor(c);
}
void iceTermSetBgColor(int c)
{
    setBackgroundColor(c);
}