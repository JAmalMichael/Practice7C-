#pragma once
#include "Game.h"
#include "TextureManager.h"



class GameObj {
	int xpos, ypos;
	sf::RectangleShape sourceRect, destRect;
	Game game;
	TextureManager textureManager;


public:
	GameObj();
	~GameObj();


	void setPlayer(const char* charName);
	void setPosition(float x, float y);
	void updateMovement();
	void draw(sf::RenderWindow& window);

	sf::Sprite& getSprite() {
		return textureManager.getSprite();
	}

};
