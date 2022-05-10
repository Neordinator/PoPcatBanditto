#pragma once

#include "../Element/Element.h"

class Eye : public Element
{
public:
	Eye() = delete;
	Eye(const sf::Texture*, const sf::Texture*, const sf::Vector2f&, const sf::Vector2f&);
	virtual void setProperty() override;
	virtual void turnPrizeMode() override;
};
