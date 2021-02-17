#include "wall.h"

bool Wall::collision(Game_object& game_object)
{
	return game_object.collision(*this);
}

bool Wall::collision(Digger& digger)
{
	return digger.collision(*this);
	
}

bool Wall::collision(Monster& monster)
{
	return monster.collision(*this);
}
