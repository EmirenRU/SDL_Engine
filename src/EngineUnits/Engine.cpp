#include "Engine.hpp"

SDL_Window*   Engine::window       = nullptr;
SDL_Renderer* Engine::renderer     = nullptr;

//Default
int Engine::SCREEN_WIDTH           = 1280;
int Engine::SCREEN_HEIGHT		   = 720;
int Engine::SCREEN_FPS			   = 30;
int Engine::SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
int Engine::FLAG                   = 0;
const SDL_Rect Engine::sourceR	   = { 0, 0, 3840, 2160 };
SDL_Rect Engine::destR	   = { 0, 0 , SCREEN_HEIGHT, SCREEN_WIDTH };



void Engine::InitEngine(const char* title, const enum Resolution res, const bool fullscreen)
{
	// Pre Initialization of SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_JPG);

	this->setScreenResolution(res);
	
	
	
	if (fullscreen) 
		int FLAG = SDL_WINDOW_FULLSCREEN;
	else
		int FLAG = SDL_WINDOW_BORDERLESS;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, FLAG);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	}

	
	SDL_Surface* loadedWallpaper = IMG_Load("assets/Wallpapers/base.jpg");

	Wallpaper = SDL_CreateTextureFromSurface(renderer, loadedWallpaper);

	SDL_FreeSurface(loadedWallpaper);

	player = new GameObject("assets/Free_Assets/Adventurer Pack/Adventurer Pack 2/Individual Sprites/adventurer-idle-2-01.png", 0, 0, 50, 37);
}

void Engine::StartGame()
{
	
	while (!IsQuit())
	{
		// Start of the caping of FPS and something...
		Uint32 START_TIME = SDL_GetTicks();
		
		// Wallpaper init
		InitWallpaper();
		
		// Renderer
		Render();
		// If event then we do something
		if (IsEvent())
		{
			Event();
		}
		//Update something...
		Update();
		
		// Elapsed time to compare the ticks
		Uint32 ELAPSED_TIME = SDL_GetTicks() - START_TIME;
		
		// Delaying the ticks 
		if (ELAPSED_TIME < SCREEN_TICKS_PER_FRAME)
		{
			SDL_Delay(SCREEN_TICKS_PER_FRAME - ELAPSED_TIME);
		}


		// How much FPS we have
		std::cout << 1000 / (SCREEN_TICKS_PER_FRAME - ELAPSED_TIME) << std::endl;

		// Clearing the renderer to recreate the scene
		SDL_RenderClear(renderer);
	}

	IMG_Quit();
	SDL_Quit();
}


void Engine::Update()
{
	player->Update();
}

void Engine::Render()
{
	player->Render();
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, Random::randomColor(), Random::randomColor(), Random::randomColor(), Random::randomColor());


}

void Engine::InitWallpaper()
{
	SDL_RenderCopy(renderer, Wallpaper, &sourceR, &destR);
	SDL_RenderPresent(renderer);
}

bool Engine::IsEvent()
{
	if (SDL_PollEvent(&evt))
		return true;
	return false;
}

void Engine::Event()
{
	if (evt.type == SDL_KEYDOWN) {
		switch (evt.key.keysym.sym)
		{
		case SDLK_a:
			break;
		case SDLK_w:
			break;
		case SDLK_s:
			break;
		case SDLK_d:
			break;
		}
	}
	else if (evt.type == SDL_MOUSEBUTTONDOWN)
	{
		switch (evt.button.button)
		{
		case SDL_BUTTON_LEFT:
			break;
		case SDL_BUTTON_RIGHT:
			break;
		case SDL_BUTTON_MIDDLE:
			break;
		}
	}

}

bool Engine::IsQuit()
{
	if (SDL_PollEvent(&evt))
	{
		// Pressing the X in the window
		if ( evt.type == SDL_QUIT )
		{
			return true;
		}

		// Press the ESC key 
		else if (evt.type == SDL_KEYDOWN && evt.key.keysym.sym == SDLK_ESCAPE)
		{
			return true;
		}
	}

	return false;
}

void Engine::SetMaxFPS(const int _FPS)
{
	SCREEN_FPS = _FPS;
	SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
}

SDL_Renderer*& Engine::getRenderer()
{
	return renderer;
}


void Engine::setScreenResolution(const enum Resolution res)
{
	switch (res)
	{
	case Resolution::qHD:
		SCREEN_HEIGHT = 540;
		SCREEN_WIDTH  = 960;
		break;
	case Resolution::HD:
		SCREEN_HEIGHT = 720;
		SCREEN_WIDTH = 1280;
		break;
	case Resolution::FHD:
		SCREEN_HEIGHT = 1080;
		SCREEN_WIDTH = 1920;
		break;
	case Resolution::QHD:
		SCREEN_HEIGHT = 1440;
		SCREEN_WIDTH = 2560;
		break;
	case Resolution::UHD:
		SCREEN_HEIGHT = 2160;
		SCREEN_WIDTH = 3840;
		break;
	default:
		break;
	}

	destR.h = SCREEN_HEIGHT;
	destR.w = SCREEN_WIDTH;

}
