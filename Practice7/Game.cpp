#include "Game.h"
#include "TextureManager.h"
#include "GameObj.h"
#include "TileMap.h"

//global level texture manaer intance
TextureManager textureManager;

//Player & enemy
GameObj player;
GameObj enemy;

//tilemap instace
TileMap tileMap;

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

	/*if (!charTex.loadFromFile("Char-1.png")) {
		std::cout << "Failed to load texture file" << std::endl;
	}
	else {
		std::cout << "Texture loaded successfully" << std::endl;
		charSprite.setTexture(charTex);
		charSprite.setPosition(200, 200);
	}*/

	/*textureManager.loadTexture("Char-1.png");
	textureManager.loadTexture("Enemy.png");*/
	tileMap.loadTexture();
	tileMap.createMap(5, 5, 100);

	player.setPlayer("Char-1.png");
	player.setPosition(50, 50);
	enemy.setPlayer("Enemy.png");
	enemy.setPosition(100, 100);
	
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
	player.updateMovement();
	enemy.updateMovement();
};

void Game::renderer() {
	render.clear(sf::Color::Black);
	render.draw(tileMap);
	/*render.draw(textureManager.getSprite());*/
	player.draw(render);
	enemy.draw(render);
	render.display();
};


void Game::clean() {
	render.close();

};