#ifndef _TextureManager_
#define _TextureManager_

#include "../Engine.hpp"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* path);
};

#endif //_TextureManager_