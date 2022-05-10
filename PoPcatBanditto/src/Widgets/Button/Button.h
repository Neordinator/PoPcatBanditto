#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>

#include <functional>

class Button
{
private:
	sf::RectangleShape rectangle;
	sf::Text text;

	bool hovered;
	bool active;
	std::function<void()> callback;

public:
	Button() = delete;
	Button(sf::String, sf::Color, sf::Color);
	Button(sf::Vector2f, sf::Color, sf::Color);
	Button(sf::String, sf::Vector2f, sf::Color, sf::Color);

	bool operator==(Button&);

	void setFont(sf::Font&);
	void setBackColor(sf::Color);
	void setTextColor(sf::Color);
	void setText(sf::String);
	void drawTo(sf::RenderWindow*);

	void setPosition(sf::Vector2f);
	void setActive(bool);
	bool isActive();

	bool isMouseOver(sf::RenderWindow&);
	void leftClick();
	bool isHovered();
	void setCallback(std::function<void()>);

private:
	unsigned int getStringSize();
};

