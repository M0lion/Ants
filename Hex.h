#pragma once
#include <SFML/Graphics.hpp>

class Hex
{
	public:
		Hex(float xPos, float yPos);
		~Hex();

		static float GetSize();
		static float getWidth();
		static float getHeight();

		void SetPosition(float xPos, float yPos);

		void Draw(sf::RenderWindow *window);
	private:
		static float size;

		static bool shaderLoaded;
		static sf::Shader *shader;

		float edgesThickness = 4;
		float padding = 10;
		float edgeDarkening = 0.7;

		sf::CircleShape *shape;
};