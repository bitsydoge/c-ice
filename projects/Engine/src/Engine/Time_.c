#include "Time_.h"
#include <time.h>

ICE_Uint64 ICE_Time_GetMS() 
{
	return (ICE_Float)clock();
}

ICE_Float ICE_Time_GetS() 
{
	return (ICE_Float)clock() / 1000.0;
}
