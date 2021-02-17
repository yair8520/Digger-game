#pragma once
#include "Monster.h"

class Smart_monster : public Monster
{
public:
	Smart_monster(const sf::Texture& photo, const sf::Vector2f& v1, sf::Vector2f& size) :Monster(photo, v1, size) {};
	virtual void move(const sf::Vector2f& border, const float& time) override;
	virtual bool collision(Gift& gift)override { return true; };
	void setDigger(sf::RectangleShape* v1) { m_digger = v1; };
	
private:
	sf::RectangleShape* m_digger;
};
