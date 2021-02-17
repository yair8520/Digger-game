#pragma once
#include "..\include\digger.h"
#include <iostream>

Digger::Digger(const sf::Texture& photo ,const sf::Vector2f& v1,sf::Vector2f& size) : Moving(photo,v1,size)
{
}
//--------------------------------------------------------
int Digger::way()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		return right;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		return left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		return up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		return down;
	}
	else
		return stand;
}

//--------------------------------------------------------
void Digger::move(const sf::Vector2f& border, const float& time)
{
	setDirection(calculateDirection(time, way()));
	m_display.move(getDirection());
	if (!inBoard(border))
		m_display.move(-getDirection());
}
//--------------------------------------------------------
bool Digger::collision(Game_object& game_object)
{
	return game_object.collision(*this);
}
//--------------------------------------------------------
bool Digger::collision(Monster& Monster)
{
	Life::decLife();
	Score::setScore(-Score::getScore());
	m_display.setPosition(getStartLocation());
	return false;
}
//--------------------------------------------------------
bool Digger::collision(Wall& wall)
{
	m_display.move(-(getDirection()));
	return false;
}
//--------------------------------------------------------
bool Digger::collision(Stone& stone)
{
	m_display.move(-getDirection());
	return false;
}
