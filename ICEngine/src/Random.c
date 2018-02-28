#include "hdr/Random.h"
#include <time.h>

void iceRandomInit()
{
	static iceBool triggered = iceFalse;
	if(!triggered)
	{
		srand(time(NULL));
		triggered = iceTrue;
	}
}

int iceRandomInt(int min, int max)
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
iceFloat iceRandomFloat()
{
	return (iceFloat)rand() / (iceFloat)RAND_MAX;
}

