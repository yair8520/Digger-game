#include "gift.h"

bool Gift::collision(Game_object& game_object)
{
	return game_object.collision(*this);
}
//---------------------------------------
bool Gift::collision(Digger& digger)
{
	if (Stone::getAllowStone() == 0)
		Stone::setAllowStone(1);
	else if (Timer::getTime() < 5)
		Timer::setTime(Timer::getTime()+5);
	else
		Score::setScore(20);

	return true;
}
//---------------------------------------
bool Gift::collision(Monster& monster)
{
	return monster.collision(*this);
}

