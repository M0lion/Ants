#pragma once
#include <SFML/Graphics.hpp>
#include "Block.h"

typedef char pixel;

class Chunk
{
public:
	Chunk(float xPos, float yPos, int size);
	~Chunk();

	void Draw(sf::RenderWindow *window);

private:
	pixel *pixels;

	Block **blocks;

	sf::Sprite renderedChunk;
	sf::RenderTexture target;

	float xPos;
	float yPos;

	sf::Transform transform;

	int size;
	int numberofpixels;

	void redraw();

	pixel getPixel(int x, int y);
};