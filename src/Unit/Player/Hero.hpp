#ifndef _HERO_
#define _HERO_

#include <string>

#include "../GameObject.hpp"
#include "../../EngineUnits/Engine.hpp"


class Hero : public GameObject
{
public:
	Hero();
	void InitHero();
	void Render();
	void Update();
	void Event();

private:
	SDL_Texture* texture = nullptr;
	std::vector<std::pair<std::string, SDL_Texture*>> textureHolder;
	
};


#endif //_HERO_