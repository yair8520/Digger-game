#pragma once
#include "Moving.h"
#include"digger.h"
class Monster :public Moving
{
public:
	Monster(const sf::Texture& photo, const sf::Vector2f& v1, sf::Vector2f& size) :Moving(photo,v1,size) {};
	virtual void move(const sf::Vector2f& border, const float& time) override {};
	virtual bool collision(Game_object& game_object)override;
	virtual bool collision(Digger& digger)override;
	virtual bool collision(Wall& wall)override;
	virtual bool collision(Stone& stone)override;
	virtual bool collision(Diamond& diamond)override ;
	virtual bool collision(Gift& gift)override = 0;
	virtual bool collision(Monster& monster)override { return true; };
private:

};
