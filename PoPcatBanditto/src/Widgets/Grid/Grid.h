#pragma once

#include <SFML/Graphics/RenderTexture.hpp>

#include <list>
#include <vector>

#include "../Element/Element.h"
#include "../../Game/Game.h"

class Game;

class Grid
{
public:
	Grid() = delete;
	Grid(Game*, const sf::Texture&, const sf::Texture&, const sf::Texture&, const sf::Texture&, const sf::Texture&, const sf::Texture&);

	void update(const float&);
	void renderFrame();
	void draw();

	const float getX();
	const float getY();
	const float getW();
	const float getH();

	float getSlotWidth();
	float getSlotHeight();
	const float getHighestY();

	Game* gamePointer();

	std::vector<Element*> countMatches();

private:
	sf::RenderTexture render_buffer;
	sf::Sprite sprite_display;

	const sf::Texture* T_eye_1;
	const sf::Texture* T_eye_2;
	const sf::Texture* T_musk_1;
	const sf::Texture* T_musk_2;
	const sf::Texture* T_oatmeal_1;
	const sf::Texture* T_oatmeal_2;

	std::list<Element*> elements;
	Game* pWindow;

	float slot_width;
	float slot_height;

	void formGrid();
	void newElement(const float&, const float&);
	Element* highestInColumn(const float&);
	Element* getElementInSlot(const int& _col, const int& _row);
};