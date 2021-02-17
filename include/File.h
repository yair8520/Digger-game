#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

class File
{
public:
	File();
	~File();
	bool openNameFile();
	void openLevelFile(std::string name);
	void NextLevel();
	std::ifstream& getFileLevel();
	bool getEndGame() const { return m_endGame; };
	void setboolendgame(bool x) { m_endGame = x; };
	void closeNameFile();
private:
	std::ifstream m_fileLevel;
	std::ifstream m_nameFile;
	bool m_endGame = false;				//false-have any level, true-the game over.
};
