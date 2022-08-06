#include "Game.h"

#include <iostream>

const sf::Time Game::time_per_frame = sf::seconds(1.f / 60.f);

Game::Game()
	:
	m_window(sf::VideoMode(1280, 1024), "Tulips of the Underground PROTOTYPE", sf::Style::Close)
{
	m_window.setVerticalSyncEnabled(true);

	// Load background image
	if (!m_background_texture.loadFromFile("Resources\\Textures\\background.png"))
	{
		std::cout << "Failed to load background image!" << std::endl;
	}
	
	m_background_rect.setOrigin(0, 0);
	m_background_rect.setSize(sf::Vector2f(m_window.getSize().x, m_window.getSize().y));
	m_background_rect.setTexture(&m_background_texture);
	

}

void Game::Run()
{
	sf::Clock clock;
	sf::Time elapsed = sf::Time::Zero;

	while (m_window.isOpen())
	{
		sf::Time dt = clock.restart();
		elapsed += dt;

		while (elapsed > time_per_frame)
		{
			elapsed -= time_per_frame;

			ProcessInput();
			Update(time_per_frame);
		}

		Render();
	}
}

void Game::ProcessInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::Update(sf::Time dt)
{
}

void Game::Render()
{
	m_window.clear();
	
	m_window.draw(m_background_rect);

	m_window.display();
}
