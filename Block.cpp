#include "Block.h"

Block::Block()
{

}

Block::~Block()
{

}

void Block::Draw(sf::RenderTarget *target, int xPos, int yPos)
{
	sf::RectangleShape shape(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
	shape.setPosition(xPos * BLOCK_SIZE, yPos * BLOCK_SIZE);

	shape.setFillColor(sf::Color(255, 0, 255, 255));

	target->draw(shape);
}