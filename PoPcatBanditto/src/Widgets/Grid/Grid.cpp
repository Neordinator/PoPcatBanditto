#include "Grid.h"

#include <ctime>

#include "../Eye/Eye.h"
#include "../Musk/Musk.h"
#include "../Oatmeal/Oatmeal.h"

Grid::Grid( Game* _window, const sf::Texture& _tEye_1, const sf::Texture& _tEye_2
	, const sf::Texture& _tMusk_1, const sf::Texture& _tMusk_2
	, const sf::Texture& _tOatmeal_1, const sf::Texture& _tOatmeal_2) : pWindow(_window)
	, T_eye_1(&_tEye_1), T_eye_2(&_tEye_2)
	, T_musk_1(&_tMusk_1), T_musk_2(&_tMusk_2)
	, T_oatmeal_1(&_tOatmeal_1), T_oatmeal_2(&_tOatmeal_2)
{
	render_buffer.create(static_cast<unsigned int>(float(_window->getSize().x + 1u) * 0.5f) - 1u, static_cast<unsigned int>(float(_window->getSize().y + 1u) * 0.8f) - 1u);
	float indent_bot = (float)render_buffer.getSize().y / 3.f;
	float indent_top = indent_bot * (-1.f);
    sprite_display.setPosition((float)_window->getSize().x * 0.1f, (float)_window->getSize().y * 0.1f);
	slot_width = getSlotWidth(), slot_height = getSlotHeight();
	formGrid();
}

void Grid::update(const float& _deltaY)
{
	if (_deltaY == 0.f)
	{
		return;
	}
	for (auto it = elements.begin(); it != elements.end();)
	{
		Element* element = *it;
		if (element->getPosition().y > ((float)render_buffer.getSize().y))
		{
			newElement(element->getPosition().x, highestInColumn(element->getPosition().x)->getPosition().y - getSlotHeight());
			it = elements.erase(it);
			delete element;
		}
		else
		{
			element->move(_deltaY);
			++it;
		}
	}
}

void Grid::renderFrame()
{
	render_buffer.clear(sf::Color(0u, 0u, 0u, 0u));

	for (auto it = elements.begin(); it != elements.end(); ++it)
	{
		Element* element = *it;
		element->drawTo(render_buffer);
	}

	render_buffer.display();

	sprite_display.setTexture(render_buffer.getTexture());
}

void Grid::draw()
{
	pWindow->draw(sprite_display);
}

const float Grid::getX()
{
	return sprite_display.getPosition().x;
}
const float Grid::getY()
{
	return sprite_display.getPosition().y;
}
const float Grid::getW()
{
	return (float)render_buffer.getSize().x;
}
const float Grid::getH()
{
	return (float)render_buffer.getSize().y;
}

void Grid::formGrid()
{
	for (int8_t row = -1; row < 3; ++row)
	{
		for (uint8_t column = 0; column < 3; ++column)
		{
			const sf::Vector2f sprite_position((float)render_buffer.getSize().x / 3.f * (float)column, ((float)render_buffer.getSize().y / 3.f) * (float)row);
			switch (rand() % 3)
			{
			case 0:
				elements.push_front(new Eye(T_eye_1, T_eye_2, sprite_position, sf::Vector2f((float)render_buffer.getSize().x, (float)render_buffer.getSize().y)));
				break;
			case 1:
				elements.push_front(new Musk(T_musk_1, T_musk_2, sprite_position, sf::Vector2f((float)render_buffer.getSize().x, (float)render_buffer.getSize().y)));
				break;
			case 2:
				elements.push_front(new Oatmeal(T_oatmeal_1, T_oatmeal_2, sprite_position, sf::Vector2f((float)render_buffer.getSize().x, (float)render_buffer.getSize().y)));
				break;
			}
		}
	}
}

void Grid::newElement(const float& _x, const float& _y)
{
	const sf::Vector2f sprite_position(_x, _y);
	switch (rand() % 3)
	{
	case 0:
		elements.push_back(new Eye(T_eye_1, T_eye_2, sprite_position, sf::Vector2f((float)render_buffer.getSize().x, (float)render_buffer.getSize().y)));
		break;
	case 1:
		elements.push_back(new Musk(T_musk_1, T_musk_2, sprite_position, sf::Vector2f((float)render_buffer.getSize().x, (float)render_buffer.getSize().y)));
		break;
	case 2:
		elements.push_back(new Oatmeal(T_oatmeal_1, T_oatmeal_2, sprite_position, sf::Vector2f((float)render_buffer.getSize().x, (float)render_buffer.getSize().y)));
		break;
	}
}

Element* Grid::highestInColumn(const float& _x)
{
	for (auto it = elements.rbegin(); it != elements.rend(); ++it)
	{
		if ((*it)->getPosition().x == _x)
		{
			return *it;
		}
	}
	return nullptr;
}

std::vector<Element*> Grid::countMatches()
{
	std::vector<Element*> match_elements;
	for (int row = 0; row < 3; ++row)
	{
		Element* first = getElementInSlot(0, row);
		Element* second = getElementInSlot(1, row);
		Element* third = getElementInSlot(2, row);
		if ((sf::Uint8)first->getType() == (sf::Uint8)second->getType() && (sf::Uint8)first->getType() == (sf::Uint8)third->getType())
		{
			match_elements.push_back(first);
			match_elements.push_back(second);
			match_elements.push_back(third);
		}
		first = nullptr;
		second = nullptr;
		third = nullptr;
	}
	return match_elements;
}
Element* Grid::getElementInSlot(const int& _col, const int& _row)
{
	float slot_left = (float)_col * slot_width;
	float slot_right = slot_width + (float)_col * slot_width;
	float slot_top = (float)_row * slot_height;
	float slot_bot = slot_height + (float)_row * slot_height;
	for (auto it = elements.rbegin(); it != elements.rend(); ++it)
	{
		if ((*it)->getSpritePosition().x > slot_left && (*it)->getSpritePosition().x + (*it)->getGlobalSize().width < slot_right
		&& (*it)->getSpritePosition().y > slot_top && (*it)->getSpritePosition().y + (*it)->getGlobalSize().height < slot_bot)
		{
			return (*it);
		}
	}
	return nullptr;
}

const float Grid::getHighestY()
{
	return elements.back()->getPosition().y;
}

Game* Grid::gamePointer()
{
	return pWindow;
}

float Grid::getSlotWidth()
{
	return (float)render_buffer.getSize().x / 3.f;
}

float Grid::getSlotHeight()
{
	return (float)render_buffer.getSize().y / 3.f;
}