#include "Game.h"

Game::Game(sf::RenderWindow &window)
{
	this->window = &window;

	world = new World(100, 100);
	chunk = new Chunk(100,100,99);
}

Game::~Game()
{
	delete world;
	delete chunk;
}

void Game::Start() 
{
	running = true;

	sf::Clock clock;

	while (running && window->isOpen())
	{
		mouseScroll = 0;
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window->close();
				running = false;
			}

			if (event.type == sf::Event::MouseWheelScrolled)
			{
				mouseScroll = event.mouseWheelScroll.delta;
			}
		}

		Update(clock.restart().asSeconds());
		Draw();

	}
}

void Game::Draw()
{
	window->clear();

	chunk->Draw(window);

	window->display();
}

void Game::Update(float deltaTime)
{
	if (mouseScroll != 0)
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition();
		sf::Vector2f mousePosInWorld = window->mapPixelToCoords(mousePos);

		sf::View view = window->getView();
		view.zoom(1 - (mouseScroll / 10));

		mousePos = sf::Mouse::getPosition();
		sf::Vector2i zoomDelta = window->mapCoordsToPixel(mousePosInWorld, view) - mousePos;
		sf::Vector2f translation = mousePosInWorld - window->mapPixelToCoords(mousePos, view);
		view.move(translation);

		window->setView(view);
	}
}