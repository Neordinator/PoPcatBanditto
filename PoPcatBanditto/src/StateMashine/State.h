#pragma once

#include "../Widgets/Grid/Grid.h"
#include "../Timer/Timer.h"

class State
{
public:
	State() = delete;
	State(Grid&);

	virtual void update() = 0;

	void begin();
	void end();

	bool isOver();
	
protected:
	Timer timer;
	Grid* pGrid;
	bool in_process;
};