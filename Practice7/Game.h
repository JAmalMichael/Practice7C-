#ifndef GAME_H
#define	GAME_H

#include <iostream>

class Game
{
private:

public:

	Game() {};
	~Game() {
		std::cout << "Game engine destroyed" << std::endl;
	};
	void init( ) {};
	void handleEvents();
	void running() {};
	void update();
	void render();
	void clean();

};



#endif