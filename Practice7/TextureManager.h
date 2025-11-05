#pragma once

#include "Game.h"


class TextureManager {
	sf::Texture charTex;
	sf::Sprite charSprite;

public:
	bool loadTexture(const char* texPath);
	void move(float dx, float dy);
	sf::Sprite& getSprite();
};