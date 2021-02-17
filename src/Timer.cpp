#pragma once
#include "timer.h"

int Timer::m_time = 0;

void Timer::setHeadLine()
{
	setText(head + std::to_string(m_time));
}