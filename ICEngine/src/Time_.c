#include "hdr/Time_.h"
#include <time.h>

ICE_Float ICE_Time_Clock(){
	return (ICE_Float)clock()/1000.0;
}
