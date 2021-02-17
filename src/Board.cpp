#include "Board.h"
int m_row = 0;
int m_col = 0;

Board::Board()
{
	startRead();
}
//--------------------------------------------------------
bool Board::ReadFromFile()
{
		
	m_matrix_inp.clear();
	m_file.NextLevel();

	if (!m_file.getEndGame())
	{
		auto line = std::string();
		std::getline(m_file.getFileLevel(), line);
		auto issNumbers = std::istringstream(line);
		issNumbers >>m_row;
		issNumbers >> m_col;
		issNumbers >> m_stone;
		issNumbers >> m_time;
		Stone::setAllowStone(m_stone);
		Timer::setTime(m_time);

		for (int i = 0; std::getline(m_file.getFileLevel(), line) && i < m_row; i++)
			m_matrix_inp.push_back(line);
		return true;
	}
	return false;
}
//--------------------------------------------------------
void Board::reOpenNameFile()
{
	m_file.closeNameFile();
	startRead();
}
//--------------------------------------------------------
void Board::startRead()
{
	m_file.setboolendgame(false);
	if (m_file.openNameFile())
		ReadFromFile();
}
//--------------------------------------------------------


