#pragma once
#include "Game_object.h"

class Non_moving :public Game_object
{
public:
	Non_moving(const sf::Texture& photo, const sf::Vector2f& v1, sf::Vector2f& size) :Game_object(photo,v1,size) {};
	//bool collision(Digger* digger) override {};

	
};
