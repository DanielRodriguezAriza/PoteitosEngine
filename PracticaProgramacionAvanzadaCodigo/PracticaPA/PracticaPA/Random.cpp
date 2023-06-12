#include "Random.h"

void Random::setSeed(time_t seed)
{
	srand(seed);
}