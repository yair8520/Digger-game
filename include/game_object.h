#pragma once
#include <SFML/Graphics.hpp>

class Digger;
class Monster;
class Wall;
class Stone;
class Diamond;
class Gift;

class Game_object
{
public:
	Game_object(const sf::Texture& photo, const sf::Vector2f& v1, sf::Vector2f& size);
	~Game_object() {};
	void draw(sf::RenderWindow& window);
	sf::RectangleShape& getSprite() { return m_display; };
	virtual bool collision(Game_object& game_object) = 0;
	virtual bool collision(Digger& digger) = 0;
	virtual bool collision(Monster& Monster) = 0;
	virtual bool collision(Wall& wall) = 0;
	virtual bool collision(Stone& stone) = 0;
	virtual bool collision(Diamond& diamond) = 0;
	virtual bool collision(Gift& gift) = 0;
protected:
	sf::RectangleShape m_display;

	
};

