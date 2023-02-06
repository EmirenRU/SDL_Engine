#pragma once

#ifndef _Engine_
#define _Engine_

// Standar library
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <fstream>
#include <memory>
#include <algorithm>
#include <bitset>


// Standart Template Library
#include <vector>
#include <queue>
#include <array>

// Windows API
#include <Windows.h>

// SDL Framework
#include "SDL.h"
#include "SDL_thread.h"
#include "SDL_image.h"
#include "SDL_mixer.h"

// Engine Library
#include "../Unit/GameObject.hpp"
#include "TextureManager/TextureManager.hpp"
#include "Random/Random.hpp"




class Engine {
public:
	const enum Resolution { qHD, HD, FHD, QHD, UHD };
	Engine() { window = nullptr; renderer = nullptr; FLAG = false; SCREEN_HEIGHT = 1280; SCREEN_WIDTH = 720; Wallpaper = nullptr; }
	Engine(SDL_Window*& _win, SDL_Renderer*& _ren) { window = _win; renderer = _ren; }
	~Engine() { SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); }

	void StartGame();
	void InitEngine(const char* title,const enum Resolution res, bool fullscreen);
	void Update();
	void Render();
	void Event();
	void InitWallpaper();
	bool IsEvent();
	bool IsQuit();

	//Seting the max Frame Rate
	static void SetMaxFPS(const int _FPS);
	static void setScreenResolution(const enum Resolution res);


	static SDL_Renderer*& getRenderer();


private:

	// Player object
	GameObject* player = nullptr;

	// Pointer to our SDL_Window
	static SDL_Window* window;
	static SDL_Renderer* renderer;
	
	// Pointer to our SDL_Renderer
	// Event
	SDL_Event evt;
	// base texture of wallpaper
	SDL_Texture* Wallpaper;


	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	// SCREEN FPS, by default.
	static int SCREEN_FPS;
	static int SCREEN_TICKS_PER_FRAME;

	// SDL_FULLSCREEN OR NOT
	static int FLAG;

	// For Wallpaper rectangles
	const static SDL_Rect sourceR;
	static SDL_Rect destR;
	
	/*SDL_Thread *mainThread = SDL_CreateThread(,"Main Thread", )*/
	
    

};

#endif