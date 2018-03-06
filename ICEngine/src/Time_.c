#include "hdr/Time_.h"
#include <SDL2/SDL.h>

ICE_Float ICE_TimeClock(){
	return (ICE_Float)SDL_GetTicks()/1000.0;
}
