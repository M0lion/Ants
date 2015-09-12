#pragma once
#include <SFML\Graphics.hpp>
#include "Hex.h"

class World
{
	public:
		World(int xSize, int ySize);
		~World();

		void Draw(sf::RenderWindow *window);
	private:
		int xSize, ySize;

		Hex ***tiles;
};