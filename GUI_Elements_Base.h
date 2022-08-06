#pragma once

#include "SFML/Graphics.hpp"

class GuiElementsBase
{
public:
	GuiElementsBase();
	virtual ~GuiElementsBase();

	virtual void Update() = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
private:
	sf::Vector2f m_size;
	sf::RectangleShape m_gui_rect;
};