#include "Smart_monster.h"

void Smart_monster::move(const sf::Vector2f& border, const float& time)
{
	
	sf::Vector2f v1;
	int step;
	v1.x = m_digger->getPosition().x - m_display.getPosition().x;
	v1.y = m_digger->getPosition().y - m_display.getPosition().y;
	step = sqrt(v1.x * v1.x + v1.y * v1.y);
	if (step != 0)
	{
		v1.x /= step;
		v1.y /= step;
	}
	float newTime = time/3;
	setDirection(v1*(200.f* newTime));
	m_display.move(getDirection());
	if (!inBoard(border))
		m_display.move(-getDirection());
}
