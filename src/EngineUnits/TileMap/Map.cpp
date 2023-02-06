#include "Map.hpp"


Map::Map()
{
	grass = TextureManager::LoadTexture("assets/Free_Assets/NinjaAdventure/Backgrounds/Tilesets/grass.png");
	dirt  = TextureManager::LoadTexture("assets/Free_Assets/NinjaAdventure/Backgrounds/Tilesets/dirt.png");
	water = TextureManager::LoadTexture("assets/Free_Assets/NinjaAdventure/Backgrounds/Tilesets/water.png");

}

Map::~Map()
{

}

void Map::LoadMap()
{

}

void Map::DrawMap()
{

}