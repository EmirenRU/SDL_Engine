
#ifndef _Object_
#define _Object_

#include "SDL.h"
#include "../EngineUnits/TextureManager/TextureManager.hpp"



class GameObject
{
public:
	GameObject();
	GameObject(const char* textureSheet, const int& x, const int& y, const int& width, const int& height);
	~GameObject();
	
	void Update();
	void Render();


private:
	int xpos, ypos;
	float hp, armor, damage;
	
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;


	void FreeObject();
};

#endif