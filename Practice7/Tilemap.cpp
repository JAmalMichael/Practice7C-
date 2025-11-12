#include "TileMap.h"


bool TileMap::loadTexture() {
	const std::vector<std::string> texturePaths = {
		"landmap.jpg",
		"mudmap.jpg",
		"watermap.jpg"
	};

	for (const auto& path : texturePaths)
	{
		sf::Texture tex;
		if (!tex.loadFromFile(path))
		{
			std::cerr << "Error loading file" << path << std::endl;
			return false;
		}
		tileTextures.push_back(tex);
	}
}


void TileMap::createMap(int width, int height, int tilesize) {
	//map for holding the tiles
	map = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
	};

	tileMap.clear();
	for (size_t y = 0; y < map.size(); ++y)
	{
		for (size_t x = 0; x < map[y].size(); ++x)
		{
			int tileType = map[y][x];
			if ( tileType >= 0 && tileType < (int)tileTextures.size())
			{
				sf::Sprite sprite;
				sprite.setTexture(tileTextures[tileType]);
				sprite.setPosition(x * tilesize, y * tilesize);
				sprite.setScale(
					static_cast<float>(tilesize) / tileTextures[tileType].getSize().x,
					static_cast<float>(tilesize) / tileTextures[tileType].getSize().y
				);
				tileMap.push_back(sprite);
			}
		}
	}
};

