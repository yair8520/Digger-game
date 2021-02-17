#pragma once
#include "Recorces.h"
#include <iostream>

Recorces::Recorces()
{	
	load_picture();
	load_font();
	loadSound();
}
//--------------------------------------------------------
void Recorces::load_picture()
{
	m_picture[0].loadFromFile("dg.png");
	m_picture[1].loadFromFile("monster2.png");
	m_picture[2].loadFromFile("s_monster.png");
	m_picture[3].loadFromFile("diamond.png");
	m_picture[4].loadFromFile("stone.png");
	m_picture[5].loadFromFile("wall.png");
	m_picture[6].loadFromFile("score.png");
	m_picture[7].loadFromFile("gifts.png");
	m_picture[8].loadFromFile("life.png");
	m_picture[9].loadFromFile("level.png");
	m_picture[10].loadFromFile("startscreen.png");
	m_picture[11].loadFromFile("backgrounds.jpg");
	m_picture[12].loadFromFile("game_over.jpg");
	m_picture[13].loadFromFile("time.png");
	m_picture[14].loadFromFile("nextlevel.png");
	m_picture[15].loadFromFile("endgamesuccess.png");
}

void Recorces::load_font()
{
	m_font[0].loadFromFile("Herist.otf");
	m_font[1].loadFromFile("PlayMeGames-Demo.otf");
	m_font[2].loadFromFile("sriwedari.ttf");

}
void Recorces::loadSound()
{
	m_sound[0].openFromFile("gamemusic.wav");
	m_sound[1].openFromFile("death.wav");
	m_sound[2].openFromFile("diamond.wav");
}
//-------------------------------------------------------

sf::Texture& Recorces::operator[](const int& i)
{
	return m_picture[i];
}
//-------------------------------------------------------
sf::Font& Recorces::getfont(const int& i)
{
	return m_font[i];
}

sf::Music& Recorces::getMusic(int i)
{
	return m_sound[i];
}

