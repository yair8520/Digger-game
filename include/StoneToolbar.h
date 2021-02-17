#include"Toolbar.h"
#include"stone.h"

class StoneToolbar : public Toolbar
{
public:
	StoneToolbar(const sf::Texture& photo, sf::Font& font) :head("stone:"),
		Toolbar(photo, font, "stone: " + std::to_string(Stone::getAllowStone())) {};
	virtual void setHeadLine()override {
		setText(head + std::to_string(Stone::getAllowStone()));
	}
	
private:
	std::string head;
};

