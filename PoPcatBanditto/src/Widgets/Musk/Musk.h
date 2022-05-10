#pragma once

#include "../Element/Element.h"

class Musk : public Element
{
public:
	Musk() = delete;
	Musk(const sf::Texture*, const sf::Texture*, const sf::Vector2f&, const sf::Vector2f&);
	virtual void setProperty() override;
	virtual void turnPrizeMode() override;
};
