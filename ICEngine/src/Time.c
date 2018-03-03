#include "hdr/Time.h"
#include <time.h>

ICE_Float ICE_TimeClock()
{
	return (ICE_Float)clock() / 1000;
}
