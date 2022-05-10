#pragma once

#include "State.h"

class StateWaiting : public State
{
public:
	StateWaiting() = delete;
	StateWaiting(Grid&);

	void update() override;
};