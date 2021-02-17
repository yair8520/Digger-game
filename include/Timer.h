#pragma once
#include "Toolbar.h"

class Timer : public Toolbar
{
public:
	Timer(const sf::Texture& photo, sf::Font& font) :
		Toolbar(photo, font, "Time: " + std::to_string(m_time)) {};
	static void setTime(const int& time) { m_time = time; };
	static void decTime() { m_time--; };
	static int getTime() { return m_time; };
	virtual void setHeadLine();
	


private:
	static int m_time;
	std::string head = "Time: ";
};
