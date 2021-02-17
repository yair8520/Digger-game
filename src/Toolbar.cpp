#include "Toolbar.h"

Toolbar::Toolbar(const sf::Texture& photo ,sf::Font& font,std::string headLine)
{
	m_display.setSize(sf::Vector2f(70.0f, 70.0f));
	m_display.setTexture(&photo);
	m_text.setFont(font);
	m_text.setString(headLine);
	m_text.setCharacterSize(20);
}

void Toolbar::draw(sf::RenderWindow& window, const sf::Vector2f& v1)
{
	m_display.setPosition(v1);
	m_text.setPosition({ v1.x+10,v1.y+80 });
	m_text.setStyle(sf::Text::Italic| sf::Text::Bold);
	window.draw(m_display);
	window.draw(m_text);

}


void Toolbar::setText(const std::string& head)
{
	m_text.setString(head);
}

