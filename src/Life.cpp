#pragma once
#include"life.h"

int Life::m_life = 3;

void Life::setHeadLine()
{
	setText(head + std::to_string(m_life));
}
//----------------------------------------
bool Life::gameOver()
{
	return m_life < 0;
}
