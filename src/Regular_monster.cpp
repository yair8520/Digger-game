#pragma once
#include"Regular_monster.h"

void Regular_monster::move(const sf::Vector2f& border, const float& time)
{
	if (rand() % 200 == 9)
		setDirection(calculateDirection(time/3 , rand() % 4));
	m_display.move(getDirection());
	if (!inBoard(border))
		m_display.move(-getDirection());
}

bool Regular_monster::collision(Gift& gift)
{
	m_display.move(-getDirection());
	return false;
}
