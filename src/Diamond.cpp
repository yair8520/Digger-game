#include "Diamond.h"

int Diamond::m_numOfDiamond = 0;

Diamond::~Diamond()
{
	--m_numOfDiamond;
}

bool Diamond::collision(Digger& digger)
{
	Score::setScore(15);
	this->~Diamond();
	return true;
}

bool Diamond::collision(Monster& monster)
{
	return monster.collision(*this);
}
