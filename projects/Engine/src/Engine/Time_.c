#include "Time_.h"

#include "../Framework/BasicTypes.h"
#include <time.h>

ICE_Float ICE_Time_GetMS() 
{
	return (ICE_Float)clock();
}

ICE_Float ICE_Time_GetS() 
{
	return (ICE_Float)clock() / 1000.0;
}
