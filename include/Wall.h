#pragma once
#include "Non_moving.h"
#include "digger.h"
#include "Monster.h"

class Wall :public Non_moving
{
public:
	Wall(const sf::Texture& photo, const sf::Vector2f& v1, sf::Vector2f& size) :Non_moving(photo, v1,size) {};
	virtual bool collision(Game_object& game_object)override;
	virtual bool collision(Digger& digger)override ;
	virtual bool collision(Wall& Wall)override { return true; } ;
	virtual bool collision(Monster& monster)override ;
	virtual bool collision(Stone& stone)override { return true; } ;
	virtual bool collision(Diamond& diamond)override { return true; } ;
	virtual bool collision(Gift& gift)override { return true; } ;
private:
};
