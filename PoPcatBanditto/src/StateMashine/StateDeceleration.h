#pragma once

#include "State.h"

class StateDeceleration : public State
{
public:
	StateDeceleration(Grid&);

	void update() override;

private:
    float deltaY;
};