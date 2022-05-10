#include "State.h"

State::State(Grid& _grid) : in_process(true), pGrid(&_grid)
{
}

void State::begin()
{
	in_process = true;
}

void State::end()
{
	in_process = false;
}

bool State::isOver()
{
	return !in_process;
}
