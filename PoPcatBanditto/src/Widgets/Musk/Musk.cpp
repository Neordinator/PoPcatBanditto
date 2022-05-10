#include "Musk.h"

Musk::Musk(const sf::Texture* _texture_base, const sf::Texture* _texture_prize
	, const sf::Vector2f& _position, const sf::Vector2f& _render_texture_size)
	: Element(_texture_base, _texture_prize, _position, _render_texture_size, EType::Musk)
{
	setProperty();
	applyOffset();
}

void Musk::setProperty()
{
	sprite.setScale((((sprite.getPosition().x - posX) * 10.f) - (2.f * offsetX)) / t_base->getSize().x, (((sprite.getPosition().y - posY) * 10.f) - (2.f * offsetY)) / t_base->getSize().y);
}

void Musk::turnPrizeMode()
{
	sprite.setTexture(*t_prize);
}