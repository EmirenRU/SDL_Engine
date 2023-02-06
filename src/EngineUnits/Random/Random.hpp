#pragma once

#include <ctime>
#include <cstdlib>

class Random
{
public:
	Random();
	static int randomNumber(int start, int end);
	static int randomColor();
};

