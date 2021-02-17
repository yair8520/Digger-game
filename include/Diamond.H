#pragma once
#include "Non_moving.h"
#include <SFML/Graphics.hpp>
#include "Score.h"
#include "Monster.h"

class Diamond :public Non_moving
{
public:
	Diamond(const sf::Texture& photo, const sf::Vector2f& v1, sf::Vector2f& size) :Non_moving(photo,v1,size) { ++m_numOfDiamond; };
	~Diamond();
	virtual bool collision(Game_object& game_object)override { return true; } ;
	virtual bool collision(Digger& digger) override;
	virtual bool collision(Monster& monster)override ;
	virtual bool collision(Wall& wall)override { return true; }  ;
	virtual bool collision(Stone& stone)override { return true; }  ;
	virtual bool collision(Gift& gift)override { return true; }  ;
	virtual bool collision(Diamond& diamond)override { return true; }  ;
	static int getNumOfDiamond() { return m_numOfDiamond; };
	static void setNumOfDiamond(int i) { m_numOfDiamond=i; };

private:
	static int m_numOfDiamond;
};

