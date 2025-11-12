#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "GameObj.h"

class TileMap : public sf::Drawable
{
private:
	std::vector<sf::Texture> tileTextures;
	std::vector<sf::Sprite> tileMap;
	std::vector<std::vector<int>> map;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
		for ( const auto& tile : tileMap)
		{
			target.draw(tile, states);
		}
	}

public:
	bool loadTexture();
	void createMap(int width, int height, int tilesize);

};