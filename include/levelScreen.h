#pragma once
#include "screen.h"
#include"Level.h"

class LevelScreen : public Screen
{
public:
	LevelScreen(const sf::Texture& photo, sf::Font& font) :
		Screen(photo, font, "press SPACE to continue or ESC to exit") {};

private:

};