#pragma once
#include <SFML/Graphics.hpp>

class Screen
{
public:
	Screen(const sf::Texture& photo, sf::Font& font, std::string headLine);
	void draw(sf::RenderWindow& window);
	void setText(int size, sf::Vector2f position, sf::Color color);
	

private:
	sf::RectangleShape m_screen;
	sf::Text head;
};
