#include "Stone.h"

int Stone::m_numOfAllowStone = 0;

void Stone::setAllowStone(const int& i)
{
	m_numOfAllowStone = i;
}

int Stone::getAllowStone()
{
	return m_numOfAllowStone;
}

Stone::~Stone()
{
	--m_numOfAllowStone;
}

bool Stone::collision(Game_object& game_object)
{
	return game_object.collision(*this);
}

bool Stone::collision(Digger& digger)
{
	if (m_numOfAllowStone > 0)
	{
		this->~Stone();
		return true;
	}
	return digger.collision(*this);
}

bool Stone::collision(Monster& monster)
{
	return monster.collision(*this);
}

