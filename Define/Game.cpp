#include "Game.h"
#include <iostream>
using namespace std;

Game::Game()
{
	m_mainWindow.create(sf::VideoMode(m_windowSize, m_windowSize, 32), "Game!");
	//GameLoop();

	m_Level = new Level(m_windowSize);		
	//m_gameObjectManager = new GameObjectManager();

	m_gameState = ShowingMenu;
	//m_debug.Initialize();

	while (m_gameState != Exiting)
	{
		GameLoop();
	}

	//m_gameObjectManager->Destroy();
	m_mainWindow.close();
}

void Game::GameLoop()
{
	sf::Event event;

	int frames;
	m_maxFrames = 5;
	m_time = m_gameClock.restart().asSeconds();

	m_remainingTime += m_time;
	frames = 0;

	while ((m_remainingTime > m_minTimestep) && (frames < m_maxFrames))
	{

		m_mainWindow.clear(sf::Color::White);
		m_Level->Draw(m_mainWindow);
		m_mainWindow.display();

		while (m_mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_gameState = Exiting;
			}
		}

		m_remainingTime -= m_minTimestep;
		frames++;
	}
}

Game::~Game()
{
	delete m_Level;
}

sf::Clock Game::m_gameClock;