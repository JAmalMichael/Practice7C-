#include "TextureManager.h"

void TextureManager::loadTexture(const char* tex) {
	if (!charTex.loadFromFile(tex)) {
		std::cout << "Error Loading Texture" << std::endl;
	}
	else {
		charSprite.setTexture(charTex);
		charSprite.setPosition(200, 200);
	}
}

void TextureManager::textureMovement() {
	charSprite.move(1.5f, 0);
}

sf::Sprite& TextureManager::getSprite() {
	return charSprite;
}