#include <SFML/Graphics.hpp>

#define BLOCK_SIZE 32

class Block
{
public:
	Block();
	~Block();

	void Draw(sf::RenderTarget *target, int xPos, int yPos);
};