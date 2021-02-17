#pragma once
#include "Moving.h"
#include "Life.h"
#include"Score.h"

class Digger : public Moving
{
public:
	Digger(const sf::Texture& photo, const sf::Vector2f& v1, sf::Vector2f& size);
	virtual void move(const sf::Vector2f& border, const float& time);
	virtual bool collision(Game_object& game_object) override;
	virtual bool collision(Monster& Monster)override;
	virtual bool collision(Digger& digger)override { return true; } ;
	virtual bool collision(Wall& wall)override;
	virtual bool collision(Stone& stone)override;
	virtual bool collision(Diamond& diamond)override { return true; } ;
	virtual bool collision(Gift& gift)override { return true; } ;
	int way();
private:
	sf::Vector2f m_origion;

};