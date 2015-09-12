#include "Hex.h"

float Hex::size = 100;
bool Hex::shaderLoaded = false;
sf::Shader *Hex::shader = nullptr;

Hex::Hex(float xPos, float yPos)
{

	shape = new sf::CircleShape(size - edgesThickness - padding, 6U);
	shape->setOutlineThickness(edgesThickness);
	shape->setPosition(xPos, yPos);

	sf::Color color;
	color.r = 237;
	color.g = 201;
	color.b = 175;
	shape->setFillColor(color);


	sf::Color edgeColor(color);
	edgeColor.r = (float)(color.r) * (1.0 - edgeDarkening);
	edgeColor.g = color.g * (1 - edgeDarkening);
	edgeColor.b = color.b * (1 - edgeDarkening);
	edgeColor.a = color.a;

	shape->setOutlineColor(edgeColor);
	shape->setOutlineThickness(edgesThickness);
}

Hex::~Hex()
{
}

void Hex::Draw(sf::RenderWindow *window)
{
	window->draw(*shape);
}

void Hex::SetPosition(float xPos, float yPos)
{
	shape->setPosition(xPos, yPos);
}

float Hex::GetSize()
{
	return size;
}

float Hex::getHeight()
{
	return 2 * size;
}

float Hex::getWidth()
{
	return sqrt(3) * size;
}