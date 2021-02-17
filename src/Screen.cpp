#include"screen.h"

Screen::Screen(const sf::Texture& photo, sf::Font& font, std::string headLine)
{
	m_screen.setSize({ 1200,700 });
	m_screen.setTexture(&photo);
	head.setFont(font);
	head.setString(headLine);
	head.setCharacterSize(20);
	head.setColor(sf::Color::Blue);
	head.setPosition({ 50,650 });
	head.setStyle(sf::Text::Italic | sf::Text::Bold);
}

void Screen::draw(sf::RenderWindow& window)
{
	window.draw(m_screen);
	window.draw(head);
}

void Screen::setText(int size, sf::Vector2f position,sf::Color color)
{
	head.setPosition(position);
	head.setCharacterSize(size);
	head.setColor(color);
}
