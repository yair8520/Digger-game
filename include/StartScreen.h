#pragma once
#include "screen.h"

class StartScreen : public Screen
{
public:
	StartScreen(const sf::Texture& photo, sf::Font& font) :
		Screen(photo, font, "Press space to begin or Esc to exit") {};

private:
	
};
