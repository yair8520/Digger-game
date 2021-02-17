#include "Monster.h"

bool Monster::collision(Game_object& game_object)
{
	return game_object.collision(*this);
}
//---------------------------------------
bool Monster::collision(Digger& digger)
{
	m_display.setPosition(getStartLocation());
	return digger.collision(*this);
}
//---------------------------------------
bool Monster::collision(Wall& wall)
{
	m_display.move(-getDirection());
	return false;
}
//---------------------------------------
bool Monster::collision(Stone& stone)
{
	m_display.move(-getDirection());
	return false;
}

bool Monster::collision(Diamond& diamond)
{
	m_display.move(-getDirection());
	return false;
}
