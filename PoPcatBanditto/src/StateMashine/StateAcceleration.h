#pragma once

#include "State.h"

class StateAcceleration : public State
{
public:
	StateAcceleration(Grid&);

	void update() override;

private:
	float deltaY;
};