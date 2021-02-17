#pragma once
#include "Toolbar.h"

class Level : public Toolbar
{
public:
	Level(const sf::Texture& photo, sf::Font& font) :
		Toolbar(photo, font, "level: " + std::to_string(m_level)) {};
	static void setLevel() { m_level++; };
	static int getLevel() { return m_level; }
	virtual void setHeadLine();
	

private:
	static int m_level;
	std::string head = "Level: ";
};
