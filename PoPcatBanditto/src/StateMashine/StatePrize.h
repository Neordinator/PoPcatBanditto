#pragma once

#include "State.h"

class StatePrize : public State
{
public:
	StatePrize() = delete;
	StatePrize(Grid&);

	void update() override;

private:
	void playSound(EType);

	sf::Uint8 shake_count;
	sf::Uint8 takt;

	std::vector<Element*> matches_elements;

	float deltaY;
	bool already_played;
	bool it_is_not_a_time;

	sf::Sound sound;
	const sf::SoundBuffer* pPop;
	const sf::SoundBuffer* pWhu;
	const sf::SoundBuffer* pIllum;

	sf::Thread soundPlaying_thread{ [&]() {
		sf::Uint8 types_counter = 2u;
		for (auto it = matches_elements.begin(); it != matches_elements.end(); ++it, --types_counter)
		{
			(*it)->turnPrizeMode();
			if (types_counter == 0u)
			{
				types_counter = 2u;
				this->playSound((*it)->getType());
			}
		}
		this->already_played = true;
	} };
};