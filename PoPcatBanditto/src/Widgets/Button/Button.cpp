#include "Button.h"

Button::Button(sf::String _text, sf::Vector2f _size, sf::Color _bgColor = sf::Color::White, sf::Color _textColor = sf::Color::Black)
	: hovered(false), active(true)
{
	text.setFillColor(_textColor);
	rectangle.setFillColor(_bgColor);

	text.setString(_text);
	text.setCharacterSize(unsigned int (_size.x / _size.y));

	if ((float)getStringSize() > _size.x || (float)getStringSize() < _size.x)
	{
		text.setCharacterSize(unsigned int(_size.x / _size.y * 10.f));
	}

	text.setLetterSpacing(_size.x / (float(text.getString().getSize()) * 7u));
	rectangle.setSize(_size);
}

Button::Button(sf::Vector2f _size, sf::Color _bgColor = sf::Color::White, sf::Color _textColor = sf::Color::Black) : hovered(false), active(true)
{
	text.setFillColor(_textColor);
	rectangle.setFillColor(_bgColor);

	text.setString("Button");
	text.setCharacterSize(unsigned int(_size.x / _size.y));

	if ((float)getStringSize() > _size.x || (float)getStringSize() < _size.x)
	{
		text.setCharacterSize(unsigned int(_size.x / _size.y * 10.f));
	}

	text.setLetterSpacing(_size.x / (float(text.getString().getSize()) * 7u));
	rectangle.setSize(_size);
}

Button::Button(sf::String _text, sf::Color _bgColor = sf::Color::White, sf::Color _textColor = sf::Color::Black) : hovered(false), active(true)
{
	text.setFillColor(_textColor);
	rectangle.setFillColor(_bgColor);

	text.setString(_text);
	sf::Vector2f _size((float)getStringSize(), (float)text.getCharacterSize());

	text.setCharacterSize((unsigned int)(_size.x / _size.y * 10.f));
	text.setLetterSpacing(_size.x / (float(text.getString().getSize()) * 7u));
	rectangle.setSize(_size);
}

bool Button::operator==(Button& other)
{
	return (this == &other) ? true : false;
}

void Button::setFont(sf::Font& _font)
{
	text.setFont(_font);
}

void Button::setBackColor(sf::Color _color)
{
	rectangle.setFillColor(_color);
}

void Button::setTextColor(sf::Color _color)
{
	text.setFillColor(_color);
}

void Button::setPosition(sf::Vector2f _pos)
{
	rectangle.setPosition(_pos);

	//float xPos = (_pos.x + rectangle.getGlobalBounds().width / 3) - (text.getGlobalBounds().width / 2);
	//float yPos = (_pos.y + rectangle.getGlobalBounds().height / 3) - (text.getGlobalBounds().height / 2);

	//text.setPosition({ xPos, yPos });

	//float xPos = (_pos.x + rectangle.getGlobalBounds().width / 3) - (text.getGlobalBounds().width / 2);
	//float yPos = (_pos.y + rectangle.getGlobalBounds().height / 3) - (text.getGlobalBounds().height / 2);

	text.setPosition({ _pos.x, _pos.y - text.getCharacterSize() / 4 });
}

void Button::setActive(bool _activity)
{
	active = _activity;
}

bool Button::isActive()
{
	return active;
}

void Button::setText(sf::String _text)
{
	text.setString(_text);
}

void Button::drawTo(sf::RenderWindow* window)
{
	window->draw(rectangle);
	window->draw(text);
}

bool Button::isMouseOver(sf::RenderWindow& window)
{
	if (!active)
	{
		return false;
	}

	float mouseX = static_cast<float>(sf::Mouse::getPosition(window).x);
	float mouseY = static_cast<float>(sf::Mouse::getPosition(window).y);

	float btnPosX = static_cast<float>(rectangle.getPosition().x);
	float btnPosY = static_cast<float>(rectangle.getPosition().y);

	float btnxPosWidth = static_cast<float>(rectangle.getPosition().x + rectangle.getLocalBounds().width);
	float btnyPosHeight = static_cast<float>(rectangle.getPosition().y + rectangle.getLocalBounds().height);

	if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY)
	{
		hovered = true;
	}
	else
	{
		hovered = false;
	}
	
	return hovered;
}

void Button::leftClick()
{
	if (active)
	{
		callback();
	}
}

bool Button::isHovered()
{
	return hovered;
}

void Button::setCallback(std::function<void()> _callback)
{
	callback = _callback;
}

unsigned int Button::getStringSize()
{
	return static_cast<size_t>(text.getString().getSize()) * text.getCharacterSize();
}