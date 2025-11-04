#include "Game.h"

//constructorr
Game::Game() {};

//destructor
Game::~Game()
{
		std::cout << "Game engine destroyed" << std::endl;

}

void Game::init(const char* title, int width, int height, bool fullscreenFlag) {

	if (fullscreenFlag) 
		videomode = sf::VideoMode::getDesktopMode();
	else {
		videomode = sf::VideoMode(width, height);
	};

	render.create(
		videomode,
		title,
		fullscreenFlag ? sf::Style::Fullscreen : sf::Style::Default
	);

	render.setFramerateLimit(60);
	
	isRunning = true;

	if (!charTex.loadFromFile("Char-1.png")) {
		std::cout << "Failed to load texture file" << std::endl;
	}
	else {
		std::cout << "Texture loaded successfully" << std::endl;
		charSprite.setTexture(charTex);
		charSprite.setPosition(200, 200);
	}
};
void Game::handleEvents() {
	sf::Event event;

	while (render.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			render.close();


			isRunning = false;
		};

	};


};
void Game::update() {
	cnt++ ;
	charSprite.move(0.05f, 0);
};
void Game::renderer() {
	render.clear(sf::Color::Black);
	render.draw(charSprite);
	render.display();
};


void Game::clean() {
	render.close();

};