#include "hdr/Random.h"

int iceRandomInt(int min, int max)
{
	int result = 0, lowest = 0, highest = 0;

	if (min < max)
	{
		lowest = min;
		highest = max + 1;
	}
	else {
		lowest = max + 1;
		highest = min;
	}

	result = (rand() % (highest - lowest)) + lowest;
	return result;
}

// Return a random float between 0 and 1;
iceFloat iceRandomFloat()
{
	return (iceFloat)rand() / (iceFloat)RAND_MAX;
}
