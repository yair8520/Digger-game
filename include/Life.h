#pragma once
#include "Toolbar.h"

class Life :public Toolbar
{
public:
	
	Life(const sf::Texture& photo, sf::Font& font) :
		Toolbar(photo, font, "Life: " + std::to_string(m_life)) {};
	static void decLife() { m_life--; };
	static void resetLife() { m_life = 3; };
	virtual void setHeadLine();
	static bool gameOver();
private:
	static int m_life;
	std::string head = "Life: ";
};

