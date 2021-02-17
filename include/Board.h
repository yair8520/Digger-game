#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "File.h"
#include "Stone.h"
#include "Timer.h"
using std::ostream;
using std::endl;

class Board
{
public:
	Board();
	bool ReadFromFile();
	int getRow() { return m_row; };
	int getCol() { return m_col; };
	int getstone() { return m_stone; };
	int gettime() { return m_time; };
	std::vector<std::string> getMatrixInp() { return m_matrix_inp; };
	void reOpenNameFile();
	void startRead();
	
private:
	 int m_row;
	 int m_col;
	int m_stone;
	int m_time;
	std::vector<std::string> m_matrix_inp;
	File m_file;


};
