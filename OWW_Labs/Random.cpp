#include "Random.h"

int generate_random(int min, int max)
{
	return rand() % ((max - min) + 1) + min;
}

double generate_random(double min, double max)
{
	return (max - min) * ((double)rand() / (double)RAND_MAX) + min;
}