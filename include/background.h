#include "screen.h"

class Background:public Screen
{
public:
	Background(const sf::Texture& photo, sf::Font& font) : Screen(photo, font, "") {} ;
};