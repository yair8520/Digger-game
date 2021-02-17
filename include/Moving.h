#pragma once
#include "game_object.h"

enum side
{
	up,
	down,
	left,
	right,
	stand
};

class Moving :public Game_object 
{
public:
	Moving(const sf::Texture& photo, const sf::Vector2f& v1, sf::Vector2f& size) :Game_object(photo,v1,size) {};
	virtual void move(const sf::Vector2f& border, const float& time) = 0;
	void setlocation(const sf::Vector2f& v1) { location = v1; };
	sf::Vector2f calculateDirection(const float& deltaTime,const int& num);
	sf::Vector2f getlocation() { return location; };
	bool inBoard(const sf::Vector2f& borderBoard);
	void setStartLocation(const sf::Vector2f& v1) { startLocation = v1; };
	sf::Vector2f getStartLocation() { return startLocation; };
	void setDirection(const sf::Vector2f& v1) { newDiraction = v1; };
	sf::Vector2f getDirection() { return newDiraction; };

private:
	sf::Vector2f location;
	sf::Vector2f startLocation;
	sf::Vector2f newDiraction;
};

