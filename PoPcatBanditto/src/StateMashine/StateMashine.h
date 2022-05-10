#pragma once

#include <SFML/Graphics.hpp>

#include "../Timer/Timer.h"
#include "../Widgets/Button/Button.h"

enum class EState : sf::Uint8
{
    Waiting = 0,
    Acceleration,
    Rolling,
    Deceleration,
    Turn,
    Prize
};

class State;
class Grid;

class StateMashine
{
public:
    StateMashine() = delete;
    StateMashine(Grid&, Button*, Button*);

    void update();

    void start();
    void stop();

protected:
    EState eCurrent_state;
	State* pCurrent_state;

    Grid* pGrid;
    Button* pStart;
    Button* pStop;
};