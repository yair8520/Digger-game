#include "screen.h"

class GameSuccess : public Screen
{
public:
	GameSuccess(const sf::Texture& photo, sf::Font& font) : Screen(photo, font, ("restart?\n    y/n")) {};


private:

};