#include "World.h"

World::World(int xSize, int ySize)
{
	this->xSize = xSize;
	this->ySize = ySize;

	tiles = new Hex**[xSize];
	for (int i = 0; i < xSize; i++)
	{
		tiles[i] = new Hex*[ySize];
		for (int j = 0; j < ySize; j++)
		{
			if (j % 2 == 0)
				tiles[i][j] = new Hex(i * Hex::getWidth(), j * (Hex::getHeight() * 0.75));
			else
				tiles[i][j] = new Hex(i * Hex::getWidth() + (Hex::getWidth()/2), j * (Hex::getHeight() * 0.75));
		}	
	}
}

World::~World() 
{
	this->xSize = xSize;
	this->ySize = ySize;

	for (int i = 0; i < xSize; i++)
	{
		for (int j = 0; j < ySize; j++)
		{
			delete tiles[i][j];
		}
		delete tiles[i];
	}

	delete tiles;
}

void World::Draw(sf::RenderWindow *window)
{
	for (int i = 0; i < xSize; i++)
	{
		for (int j = 0; j < ySize; j++)
		{
			tiles[i][j]->Draw(window);
		}
	}
}