#pragma once

#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void Run();
private:
	void ProcessInput();
	void Update(sf::Time dt);
	void Render();
private:
	static const sf::Time time_per_frame;
	sf::RenderWindow m_window;
	sf::Texture m_background_texture;
	sf::RectangleShape m_background_rect;
};