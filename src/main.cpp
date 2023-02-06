
#include "EngineUnits/Engine.hpp"

Engine* en = new Engine();

int main(int argv, char* args[])
{

	// Initialization the window and renderer
	en->InitEngine("Emiren's Engine", Engine::HD, true);

	// Start Main Loop
	en->StartGame();

	// Quiting SDL Framework

	return 0;
}
