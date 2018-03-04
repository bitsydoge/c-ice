#include "hdr/Random.h"

#include "hdr/TypesCore.h"
#include "hdr/TypesMaths.h"

#include <time.h>


void ICE_RandomInit()
{
	static ICE_Bool triggered = ICE_False;
	if (!triggered)
	{
		srand(time(NULL));
		triggered = ICE_True;
	}
}

int ICE_RandomInt(int min, int max)
{
	int lowest, highest;
	if (min < max)
	{
		lowest = min;
		highest = max + 1;
	}
	else {
		lowest = max + 1;
		highest = min;
	}
	return (rand() % (highest - lowest)) + lowest;
}

// Return a random float between 0 and 1;
ICE_Float ICE_RandomFloat()
{
	return (ICE_Float)rand() / (ICE_Float)RAND_MAX;
}
