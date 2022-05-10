#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <iostream>

enum class EType : sf::Uint8
{
	Element = 0u,
	Eye,
	Musk,
	Oatmeal
};

class Element
{
public:
	Element() = delete;
	Element(const sf::Texture*, const sf::Texture*, EType);
	Element(const sf::Texture*, const sf::Texture*, const sf::Vector2f&, EType);
	Element(const sf::Texture*, const sf::Texture*, const sf::Vector2f&, const sf::Vector2f&, EType);

	friend bool operator==(const Element&, const Element&);

	void setPosition(sf::Vector2f);
	void drawTo(sf::RenderWindow*);
	void drawTo(sf::RenderTexture&);
	void move(const float&);

	const sf::Vector2f getPosition();
	const sf::Vector2f& getSpritePosition();
	sf::FloatRect getGlobalSize();

	EType getType();

	virtual void turnPrizeMode();
	virtual void setProperty();

protected:
	const sf::Texture* t_base;
	const sf::Texture* t_prize;
	sf::Sprite sprite;
	EType type;
	float posX;
	float posY;
	const float offsetX;
	const float offsetY;

	void applyOffset();
};

