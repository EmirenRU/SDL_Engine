#include "TextureManager.hpp"
#include <iostream>


SDL_Texture* TextureManager::LoadTexture(const char* path)
{

	SDL_Surface* loadedSurface = IMG_Load(path);

	if (loadedSurface == NULL)
	{
		std::cerr << IMG_GetError() << std::endl;
	}

	Uint32 colorKey = SDL_MapRGB(loadedSurface->format, 255, 255, 255);

	SDL_SetSurfaceBlendMode(loadedSurface, SDL_BLENDMODE_MOD);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), loadedSurface);

	SDL_FreeSurface(loadedSurface);

	return texture;
	
}

//TextureManager::TextureManager() { }