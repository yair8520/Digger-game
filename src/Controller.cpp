#pragma once
#include "..\include\Controller.h"
#include <iostream>

Controller::Controller():m_border({ 1200,550 })
{
	m_game_clock.restart();
	loadScreen();       //load all screens
	if (!StartOrEnd())     
		m_window.close();
	else 
	{
		creatLevel();
		insertToToolbar();
		playMusic(gamemusic);
	}
}
//------vector of screens---------------------
void Controller::loadScreen()
{
	m_screen.push_back(new StartScreen(m_recorces[startscreen], m_recorces.getfont(1)));
	m_screen.push_back(new Background(m_recorces[background], m_recorces.getfont(1)));
	m_screen.push_back(new GameOver(m_recorces[gameover], m_recorces.getfont(2)));
	m_screen.push_back(new LevelScreen(m_recorces[levelscreen], m_recorces.getfont(1)));
	m_screen.push_back(new GameSuccess(m_recorces[endgame], m_recorces.getfont(2)));
	m_screen[4]->setText(50, { 470,500 },sf::Color::Black);
	m_screen[3]->setText(20, { 350,500 },sf::Color::Black);
	m_screen[2]->setText(50, { 400,600 },sf::Color::Blue);

}
//-------opening screen -----------------------
bool Controller::StartOrEnd()
{
	while (m_window.isOpen())
	{
		m_window.clear();
		m_screen[0]->draw(m_window);
		m_window.display();

		for (; m_window.pollEvent(m_event); )
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
				m_event.type == sf::Event::Closed)
			{
				m_window.close();
				return false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				m_window.clear();
				return true;
			}

		}
	}
}
//---------create objects according to file inpute -----------
void Controller::creatLevel()
{
	sf::Vector2f size = sizeOfObject();
	int rand = 0,
		numOfMoving = 0,
		sizeCol = 550 / m_board.getCol(),
		sizeRow = 1200 / m_board.getRow();
	m_nonmoving.resize(m_board.getRow());
	for (int i = 0; i < m_board.getRow(); i++)
	{
		m_nonmoving[i].resize(m_board.getCol());
		for (int j = 0; j < m_board.getCol(); j++)
		{
			sf::Vector2f v1(i * sizeRow + 30, j * sizeCol + 30);
			if (m_board.getMatrixInp()[i][j] == '/')
			{
				m_moving.push_back(new Digger(m_recorces[digger], v1, size));
				m_moving[numOfMoving]->setStartLocation(v1);
				locDig = numOfMoving;
				numOfMoving++;
			}
			else if (m_board.getMatrixInp()[i][j] == '!')
			{
				if (rand % 2 == 0)
					m_moving.push_back(new Regular_monster(m_recorces[regular_monster], v1, size));
				else
				{
					m_moving.push_back(new Smart_monster(m_recorces[smart_monster], v1, size));
				}
				rand++;
				m_moving[numOfMoving]->setStartLocation(v1);
				numOfMoving++;
			}
			else if (m_board.getMatrixInp()[i][j] == 'D')
				m_nonmoving[i][j] = (new Diamond(m_recorces[diamond], v1, size));
			else if (m_board.getMatrixInp()[i][j] == '@')
				m_nonmoving[i][j] = new Stone(m_recorces[stone], v1, size);
			else if (m_board.getMatrixInp()[i][j] == '#')
				m_nonmoving[i][j] = new Wall(m_recorces[wall], v1, size);
			else if (m_board.getMatrixInp()[i][j] == '+')
				m_nonmoving[i][j] = new Gift(m_recorces[gift], v1, size);
		}
	}
	//using RTTI to save the digger position on every smart monster
	for(int i=0; i<m_moving.size();i++)
		if (dynamic_cast<Smart_monster*>(m_moving[i])) 
		{
			auto ptr = static_cast<Smart_monster*>(m_moving[i]);             
			ptr->setDigger(&m_moving[locDig]->getSprite());
		}
}
//-----------set timmer && end game if timer=0---------
void Controller::secondPass()
{
	if (Timer::getTime() != -1)
	{
		if (m_game_clock.getElapsedTime().asSeconds() >= 1.f)
		{
			Timer::decTime();
			m_game_clock.restart();
		}
		if (Timer::getTime() == 0)
		{
			Life::decLife();
			restartOrNewLevel();
		}
	}
}
//---------------vector of toolbar objects----------------
void Controller::insertToToolbar()
{
	m_toolbar.push_back(new Life(m_recorces[life], m_recorces.getfont(0)));
	m_toolbar.push_back(new Score(m_recorces[score], m_recorces.getfont(0)));
	m_toolbar.push_back(new Level(m_recorces[level], m_recorces.getfont(0)));
	m_toolbar.push_back(new StoneToolbar(m_recorces[stone], m_recorces.getfont(0)));
	m_toolbar.push_back(new Timer(m_recorces[timer], m_recorces.getfont(0)));
}
//--------print toolbar----------------
void Controller::printToolbar()
{
	int row = 590,
		col = 150;
	
	for (int i = 0; i < m_toolbar.size(); i++)
	{
		m_toolbar[i]->setHeadLine();
		m_toolbar[i]->draw(m_window, sf::Vector2f(col, row));
		col += 200;
	}
}

//-------print level-------------
void Controller::printLevel()
{
	for (int i = 0; i < m_board.getRow(); i++)
		for (int j = 0; j < m_board.getCol(); j++)
			if(m_nonmoving[i][j]!=NULL)
				m_nonmoving[i][j]->draw(m_window);
	for (int i = 0; i < m_moving.size(); i++)
		m_moving[i]->draw(m_window);
	
}
//-------------------------size of the any object-------------------
sf::Vector2f Controller::sizeOfObject()
{
	if (550 / m_board.getCol() < 550 / m_board.getRow())
		return sf::Vector2f(550 / m_board.getCol(), 550 / m_board.getCol());
	return sf::Vector2f(550 / m_board.getRow(), 550 / m_board.getRow());
}
//-----------------------------------------
void Controller::run()
{
	while (m_window.isOpen())
	{
		secondPass();                           
		m_window.clear();                       
		continueOrEndGame();                          
		m_window.display();                       
		closeWindow();                               
		movingObject();		                          
	}
}
//-------collision test-------------------------
void Controller::touchOtherObject()
{
	//monster and digger coliide with non-moving objects
	for (int x = 0; x < m_moving.size(); x++)                  
	{
		for (int i = 0; i < m_nonmoving.size(); i++)
		{
			for (int j = 0; j < m_nonmoving[i].size(); j++)
			{
				if (m_nonmoving[i][j] != NULL &&
					m_moving[x]->getSprite().getGlobalBounds().
					intersects(m_nonmoving[i][j]->getSprite().getGlobalBounds()))
				{
					if (m_moving[x]->collision(*m_nonmoving[i][j]))
					{
						m_nonmoving[i][j] = NULL;
					}
				}
			}
		}
	}
	// monster coliide with digger
	for (int i = 0; i < m_moving.size(); i++)
	{
		if (i != locDig && m_moving[locDig]->getSprite().getGlobalBounds().
			intersects(m_moving[i]->getSprite().getGlobalBounds()))
		{
			m_moving[locDig]->collision(*m_moving[i]);
			playMusic(deathmusic);
		}
	}
}
//-------------------------------------------------------------
void Controller::movingObject()
{
	float time = m_digger_clock.restart().asSeconds();
	for (int i = 0; i < m_moving.size(); i++)
	{
		m_moving[i]->move(m_border, time);
		touchOtherObject();
		if (i == m_moving.size())
			i = 0;
	}
}
//-------------------------------------------------------------
void Controller::closeWindow()
{
	for (; m_window.pollEvent(m_event); )
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		
		}
		
	}
}


//-------------------------------------
void Controller::restartOrNewLevel()
{
	deletefromvector();	
	Stone::setAllowStone(m_board.getstone());
	Timer::setTime(m_board.gettime());
	creatLevel();
}

//---------------------------------------
void Controller::continueOrEndGame()
{
	if (!Life::gameOver() && Diamond::getNumOfDiamond() > 0)     
	{
		m_screen[1]->draw(m_window);
		printLevel();
		printToolbar();
	}
	else if (!Life::gameOver() && Diamond::getNumOfDiamond() == 0
		&& m_board.ReadFromFile())  
		//Life and stages remained, but the diamonds were over
	{
		nextLevel();
		restartOrNewLevel();
	}
	else if (!m_board.ReadFromFile() && !Life::gameOver() && Diamond::getNumOfDiamond() == 0)            //game success
		endGameSuccess();
	else if (Life::gameOver())
		endGameFailure();
}
//----------------------------------------------------------
void Controller::playMusic(int i)
{
	m_recorces.getMusic(i).play();
}
//------------check if to load next level-----------------------------------	
void Controller::nextLevel()
{
	Level::setLevel();
	Score::setScore(20);
	m_window.clear();
	m_screen[3]->draw(m_window);
	m_window.display();
	for (; m_window.waitEvent(m_event); )
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			break;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			deletefromvector();
			m_window.close();
			break;
		}
	}
}
//-------------life is over---------------------------------
void Controller::endGameFailure()
{
	m_window.clear();
	m_screen[2]->draw(m_window);
	m_recorces.getMusic(gamemusic).stop();
	m_window.display();
	for (; m_window.waitEvent(m_event); )
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			Life::resetLife();
			restartGame();
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			deletefromvector();
			m_window.close();
			break;
		}
	}
}
//----------end game by success && load level by player choich--------------------
void Controller::endGameSuccess()
{
	m_window.clear();
	m_screen[4]->draw(m_window);
	m_recorces.getMusic(gamemusic).stop();

	m_window.display();
	for (; m_window.waitEvent(m_event); )
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			restartGame();
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
		{
			deletefromvector();
			m_window.close();
			break;
		}
	}
}
//--------------------------------------------------------
void Controller::restartGame()
{
	m_board.reOpenNameFile();
	restartOrNewLevel();	
}

void Controller::deletefromvector()
{
   for (int i = 0; i < m_nonmoving.size(); i++)
	   for (int j = 0; j < m_nonmoving[i].size(); j++)
		   if(m_nonmoving[i][j]!=NULL)
		      delete m_nonmoving[i][j];
   for (int i = 0; i < m_moving.size(); i++)
	   if(m_moving[i]!=NULL)
	       delete m_moving[i];
   m_moving.clear();
   m_nonmoving.clear();
   Diamond::setNumOfDiamond(0);
}
