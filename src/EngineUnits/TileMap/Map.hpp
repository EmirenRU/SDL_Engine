#ifndef _MAP_
#define _MAP_

#include "../Engine.hpp"

class Map
{
public:

	Map();
	~Map();

	void LoadMap();
	void DrawMap();


private:

	SDL_Rect src, dest;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];
};

#endif //_MAP_