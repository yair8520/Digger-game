#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum e_Picture
{
	digger,
	regular_monster,
	smart_monster,
	diamond,
	stone,
	wall,
	score,
	gift,
	life,
	level,
	startscreen,
	background,
	gameover,
	timer,
	levelscreen,
	endgame
};

enum e_music
{
	gamemusic,
	deathmusic,
	diamondmusic
};
class Recorces
{
public:
	Recorces();
	~Recorces() = default;
	void load_picture();
	void load_font();
	void loadSound();
	sf::Texture& operator[](const int& i);
	sf::Font& getfont(const int& i);
	sf::Music& getMusic(int i);



private:
	std::vector<sf::RectangleShape> m_rectangle;
	sf::Texture m_picture[16];
	sf::Font m_font[3] ;
	sf::Music m_sound[3];
};
