#pragma once

#include "Game.h"


class TextureManager {
	sf::Texture charTex;
	sf::Sprite charSprite;

public:
	void loadTexture(const char* tex);
	void textureMovement();
	sf::Sprite& getSprite();
};