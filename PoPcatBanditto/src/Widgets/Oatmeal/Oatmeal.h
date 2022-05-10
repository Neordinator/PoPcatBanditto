#pragma once

#include "../Element/Element.h"

class Oatmeal : public Element
{
public:
	Oatmeal() = delete;
	Oatmeal(const sf::Texture*, const sf::Texture*, const sf::Vector2f&, const sf::Vector2f&);
	virtual void setProperty() override;
	virtual void turnPrizeMode() override;
};
