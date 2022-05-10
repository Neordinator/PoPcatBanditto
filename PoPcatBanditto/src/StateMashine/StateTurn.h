#pragma once

#include "State.h"

class StateTurn : public State
{
public:
	StateTurn() = delete;
	StateTurn(Grid&);

	void update() override;

private:
    float deltaY;
};