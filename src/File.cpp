#pragma once
#include"file.h"

File::File()
{
}

File::~File()
{
	m_fileLevel.close();
	m_nameFile.close();
}

bool File::openNameFile()
{
	m_nameFile.open("Name.txt");
	return m_nameFile.is_open();
}

void File::openLevelFile(std::string name)
{
	m_fileLevel.open(name);
	//m_fileLevel.seekg(0);
	if (!m_fileLevel.is_open())
		std::cout << "eror in read the name file";
}

void File::NextLevel()
{
 	if (m_fileLevel.eof()||!m_fileLevel.is_open())
	{
		if (!m_nameFile.eof())
		{
			auto line = std::string();
			std::getline(m_nameFile, line);
			m_fileLevel.close();
			openLevelFile(line);
		}
		else
			m_endGame = true;
	}
}

std::ifstream& File::getFileLevel()
{
	return m_fileLevel;
}

void File::closeNameFile()
{
	m_nameFile.close();
}
