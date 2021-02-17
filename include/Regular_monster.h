#pragma once
#include"Monster.h"

class Regular_monster: public Monster 
{
public:
	Regular_monster(const sf::Texture& photo, const sf::Vector2f& v1, sf::Vector2f& size) :Monster(photo,v1,size) {};
	virtual void move(const sf::Vector2f& border, const float& time) override;
	virtual bool collision(Gift& gift)override ;
	
private:
};
