#pragma once
#include "Level.h"

int Level::m_level = 1;

void Level::setHeadLine()
{
	setText(head + std::to_string(m_level));
}
