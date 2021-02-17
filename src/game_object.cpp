#pragma once
#include "game_object.h"

Game_object::Game_object(const sf::Texture& photo, const sf::Vector2f& v1, sf::Vector2f& size)
{
	m_display.setSize(size);
	m_display.setTexture(&photo);
	m_display.setOrigin(m_display.getSize() / 2.f);
	m_display.setPosition(v1 + m_display.getOrigin());
}

void Game_object::draw(sf::RenderWindow& window)
{
	m_display.setFillColor(sf::Color::White);
	window.draw(m_display);
}

 

//m_display.setSize({ v1.x * 50.f,v1.y * 50.f });
//m_display.setTexture(&photo);
//m_display.setOrigin(m_display.getSize() / 2.f);
//m_display.setPosition(sf::Vector2f(v1.x* num, v1.y* num) + m_display.getOrigin());