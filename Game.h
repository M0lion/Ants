#pragma once
#include <SFML\Graphics.hpp>
#include "World.h"
#include "Chunk.h"

class Game
{
public:
	Game(sf::RenderWindow &window);
	~Game();

	void Start();

private:
	sf::RenderWindow *window;
	void Draw();
	void Update(float deltaTime);

	bool running = false;
	
	float mouseScroll;

	World *world;

	Chunk *chunk;
};