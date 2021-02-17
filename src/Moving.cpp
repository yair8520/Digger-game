#pragma once
#include "Moving.h"

sf::Vector2f Moving::calculateDirection(const float& deltaTime,const int& num)
{
	float speed = 200.f;
	switch (num)
	{
	case up:
		return sf::Vector2f(0, -speed * deltaTime);
		break;
	case down:
		return sf::Vector2f(0, speed * deltaTime);
		break;
	case left:
		return sf::Vector2f(-speed * deltaTime, 0);
		break;
	case right:
		return sf::Vector2f(speed * deltaTime, 0);
	case stand:
		return { 0,0 };
		break;
	}
}

bool Moving::inBoard(const sf::Vector2f& borderBoard)
{
	if (m_display.getPosition().x < borderBoard.x-20 && m_display.getPosition().y < borderBoard.y-20
		&& m_display.getPosition().x > 30 && m_display.getPosition().y > 30)
		return true;
	return false;
}