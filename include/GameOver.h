#include "screen.h"

class GameOver : public Screen
{
public:
	GameOver(const sf::Texture& photo, sf::Font& font) : Screen(photo, font, "restart? y/n") {};


private:

};
