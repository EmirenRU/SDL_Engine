#include "Random.hpp"

Random::Random()
{
	std::srand( std::time(0) );
}

int Random::randomNumber(int start, int end)
{
	return (rand() % end) + start;
}

int Random::randomColor()
{
	return randomNumber(0, 255 + 1);
}