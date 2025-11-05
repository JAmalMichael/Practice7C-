#include "TextureManager.h"

bool TextureManager::loadTexture(const char* texPath) {
	if (!charTex.loadFromFile(texPath)) {
		std::cout << "Error Loading Texture" << std::endl;
		return false;
	}
	else {
		charSprite.setTexture(charTex);
		std::cout << "Texture loaded succesfully" << std::endl;
		return true;
	}
}

		void TextureManager::move(float dx, float dy) {
			charSprite.move(dx, dy);
		}

		sf::Sprite& TextureManager::getSprite() {
			return charSprite;
		}