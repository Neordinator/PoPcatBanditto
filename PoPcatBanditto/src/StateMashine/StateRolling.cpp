#include "StateRolling.h"

StateRolling::StateRolling(Grid& _grid) : State(_grid)
{
	timer.setCallback([&]() { this->end(); });
	timer.start(10.f);
}

void StateRolling::update()
{
	if (!in_process)
	{
		return;
	}
	timer.update(0.01f);
	pGrid->update(50.f);
}
