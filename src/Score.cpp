#pragma once
#include"score.h"

int Score::m_score = 0;

void Score::setHeadLine()
{
	setText(m_head + std::to_string(m_score));
}

void Score::setScore(const int& i)
{
	m_score += i;
}

int Score::getScore()
{
	return m_score;
}


