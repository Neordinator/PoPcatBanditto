#include "Element.h"

Element::Element(const sf::Texture* _texture_base, const sf::Texture* _texture_prize, EType _type)
	: t_base(_texture_base), t_prize(_texture_prize), sprite(*t_base), type(_type), posX(0.f), posY(0.f), offsetX(0.f), offsetY(0.f)
{
	setProperty();
	sprite.setPosition(posX, posY);
}

Element::Element(const sf::Texture* _texture_base, const sf::Texture* _texture_prize, const sf::Vector2f& _position, EType _type)
	: t_base(_texture_base), t_prize(_texture_prize), sprite(*t_base), type(_type), posX(0.f), posY(0.f), offsetX(0.f), offsetY(0.f)
{
	setProperty();
	sprite.setPosition(_position.x, _position.y);
}

Element::Element(const sf::Texture* _texture_base, const sf::Texture* _texture_prize
	, const sf::Vector2f& _position, const sf::Vector2f& _render_texture_size, EType _type)
	: t_base(_texture_base), t_prize(_texture_prize), sprite(*t_base), type(_type), posX(_position.x), posY(_position.y)
	, offsetX(_render_texture_size.x / 3.f * 0.09f), offsetY(_render_texture_size.y / 3.f * 0.09f)
{
	setProperty();
	applyOffset();
}

bool operator==(const Element & _this, const Element & _other)
{
	const void* this_address = &_this;
	const void* other_address = &_this;
	return (&this_address == &other_address) ? true : false;
}

void Element::setPosition(sf::Vector2f _pos)
{
	posX = _pos.x;
	posY = _pos.y;
	applyOffset();
}

void Element::applyOffset()
{
	sprite.setPosition(posX + offsetX, posY + offsetY);
}

void Element::drawTo(sf::RenderWindow* _window)
{
	_window->draw(sprite);
}

void Element::drawTo(sf::RenderTexture& _rentexture)
{
	_rentexture.draw(sprite);
}

void Element::move(const float& _deltaY)
{
	posY += _deltaY;
	sprite.move(0.f, _deltaY);
}

const sf::Vector2f Element::getPosition()
{
	return sf::Vector2f(posX, posY);
}

const sf::Vector2f& Element::getSpritePosition()
{
	return sprite.getPosition();
}

sf::FloatRect Element::getGlobalSize()
{
	return sprite.getGlobalBounds();
}

void Element::turnPrizeMode()
{
	sprite.setTexture(*t_prize);
}

EType Element::getType()
{
	return type;
}

void Element::setProperty()
{
	sprite.setScale((((sprite.getPosition().x - posX) * 10.f) - (2.f * offsetX)) / t_base->getSize().x, (((sprite.getPosition().y - posY) * 10.f) - (2.f * offsetY)) / t_base->getSize().y);
}