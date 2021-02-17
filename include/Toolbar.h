#pragma once
#include <SFML/Graphics.hpp>

class Score;

class Toolbar
{
public:
	Toolbar(const sf::Texture& photo, sf::Font& font, std::string headLine);
	void draw(sf::RenderWindow& window, const sf::Vector2f& v1);
	virtual void setHeadLine() {};
	void setText(const std::string& head);

private:
	sf::RectangleShape m_display;
	sf::Text m_text;

};
