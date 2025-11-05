#include "GameObj.h"
 GameObj::GameObj() {};

 GameObj::~GameObj() {};


void GameObj::setPlayer(const char* charName) {
	textureManager.loadTexture(charName);
}

void GameObj::setPosition(float x, float y) {
	textureManager.getSprite().setPosition(x, y);
}

void GameObj::updateMovement() {
	textureManager.getSprite().move(0.5f,0.5f);
}

void GameObj::draw(sf::RenderWindow& window) {
	window.draw(textureManager.getSprite());
}