#include "StatePrize.h"

StatePrize::StatePrize(Grid& _grid) : State(_grid), matches_elements(pGrid->countMatches()), deltaY(15.f), already_played(false), it_is_not_a_time(false)
, pPop(pGrid->gamePointer()->thePop()), pWhu(pGrid->gamePointer()->theWhu()), pIllum(pGrid->gamePointer()->theIllum()), shake_count(36u), takt(6u)
{
	if (matches_elements.size() < 3)
	{
		end();
	}
	else
	{
		timer.setCallback([&]() {
			this->it_is_not_a_time = true;
			soundPlaying_thread.launch();
		});
		timer.start(5.f);
	}
}

void StatePrize::update()
{
	timer.update(0.1f);

	--shake_count;
	--takt;

	if(it_is_not_a_time)
	{
		deltaY = 0.f;
	}
	else if (shake_count == 0u)
	{
		deltaY = 0.f;
	}
	else
	{
		for (uint8_t i = 0u; i < matches_elements.size(); ++i)
		{
			matches_elements[i]->move(deltaY);
		}
		if (takt == 3u)
		{
			deltaY *= -1.f;
		}
		else if (takt == 0u)
		{
			deltaY *= -1.f;
			takt = 6u;
		}
	}

	if (already_played)
	{
		end();
	}
}

void StatePrize::playSound(EType _type)
{
	sf::Time duration;
	switch (_type)
	{
	case EType::Eye:
		sound.setBuffer(*pIllum);
		duration = pIllum->getDuration();
		break;
	case EType::Oatmeal:
		sound.setBuffer(*pPop);
		duration = pPop->getDuration();
		break;
	case EType::Musk:
		sound.setBuffer(*pWhu);
		duration = pWhu->getDuration();
		break;
	}
	sound.play();
	sf::sleep(duration);
}
