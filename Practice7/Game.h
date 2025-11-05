#ifndef GAME_H
#define	GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>>

class Game
{
private:
	sf::VideoMode videomode;
	sf::RenderWindow render;
	
	bool isRunning = false;
	int cnt = 0;

public:

	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreenFlag);
	void handleEvents();
	void update();
	void renderer();
	void clean();
	bool running() const { return isRunning; };

};



#endif