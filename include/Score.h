#pragma once
#include "Toolbar.h"

class Score : public Toolbar
{
public:
	Score(const sf::Texture& photo, sf::Font& font) :
		Toolbar(photo, font, "score: " + std::to_string(m_score)) {};
	virtual void setHeadLine()override;
	static void setScore(const int& i);
	static int getScore();
	
	

private:
	static int m_score;
	std::string m_head = "score: ";
};
