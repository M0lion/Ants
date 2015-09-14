#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	int width = 1500;
	int height = 900;

	sf::RenderWindow window;

	sf::VideoMode vm(width, height);

	window.create(vm, "Ants");

	Game game(window);
	game.Start();

	return 0;
}