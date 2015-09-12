#include "Chunk.h"

Chunk::Chunk(float xPos, float yPos, int size)
{
	this->xPos = xPos;
	this->yPos = yPos;

	this->size = size;
	this->numberofpixels = size * size;

	pixels = new pixel[numberofpixels];
	for (int i = 0; i < numberofpixels; i += 2)
	{
		pixels[i] = 1;
		pixels[i + 1] = 0;
	}

	renderedChunk.setPosition(xPos, yPos);

	redraw();
}

void Chunk::Draw(sf::RenderWindow *window)
{
	window->draw(renderedChunk, transform);
}

void Chunk::redraw()
{
	target.create(size, size);
	

	sf::RectangleShape rect(sf::Vector2f(1,1));
	rect.setOutlineThickness(0);
	for (int i = 0; i < numberofpixels; i++)
	{
		int y = i / size;
		int x = i % size;

		switch (pixels[i])
		{
		case 0:
			continue;
			break;
		case 1:
			rect.setFillColor(sf::Color::Green);
			break;
		default:
			rect.setFillColor(sf::Color::Magenta);
			break;
		}

		rect.setPosition(x, y);
		target.draw(rect);
	}

	renderedChunk.setTexture(target.getTexture());
}

pixel Chunk::getPixel(int x, int y)
{
	return 0;
}