#include "StateWaiting.h"

StateWaiting::StateWaiting(Grid& _grid) : State(_grid)
{
}

void StateWaiting::update()
{
	pGrid->update(0.f);
}
