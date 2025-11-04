#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
using namespace std;

int main(int argc, char* argv[])
{
	Game* game = nullptr;
	game = new Game();
	game->init("New Practice Game", 800, 600, false);

	while (game->running())
	{
		game->handleEvents();
		game->renderer();
		game->update();
	}

	return 0;
}