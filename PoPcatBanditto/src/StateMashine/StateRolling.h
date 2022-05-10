#pragma once

#include "State.h"

class StateRolling : public State
{
public:
	StateRolling() = delete;
	StateRolling(Grid&);

	void update() override;
};