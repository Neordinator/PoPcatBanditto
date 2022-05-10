#include "StateMashine.h"

#include "StateWaiting.h"
#include "StateAcceleration.h"
#include "StateRolling.h"
#include "StateDeceleration.h"
#include "StatePrize.h"
#include "StateTurn.h"
#include "../Widgets/Grid/Grid.h"

StateMashine::StateMashine(Grid& _grid, Button* _start, Button* _stop)
: pGrid(&_grid), pStart(_start), pStop(_stop), pCurrent_state(new StateWaiting(*pGrid)), eCurrent_state(EState::Waiting)
{
}

void StateMashine::update()
{
    pCurrent_state->update();
    switch (eCurrent_state)
    {
    case EState::Waiting:
        break;
    case EState::Rolling:
        if (pCurrent_state->isOver())
        {
            eCurrent_state = EState::Deceleration;
            delete pCurrent_state;
            pCurrent_state = new StateDeceleration(*pGrid);
            pStart->setActive(false);
            pStop->setActive(false);
        }
        break;
    case EState::Acceleration:
        if (pCurrent_state->isOver())
        {
            eCurrent_state = EState::Rolling;
            delete pCurrent_state;
            pCurrent_state = new StateRolling(*pGrid);
            pStart->setActive(false);
            pStop->setActive(true);
        }
        break;
    case EState::Prize:
        if (pCurrent_state->isOver())
        {
            eCurrent_state = EState::Waiting;
            delete pCurrent_state;
            pCurrent_state = new StateWaiting(*pGrid);
            pStart->setActive(true);
            pStop->setActive(false);
        }
        break;
    case EState::Turn:
        if (pCurrent_state->isOver())
        {
            eCurrent_state = EState::Prize;
            delete pCurrent_state;
            pCurrent_state = new StatePrize(*pGrid);
            pStart->setActive(false);
            pStop->setActive(false);
        }
        break;
    case EState::Deceleration:
        if (pCurrent_state->isOver())
        {
            eCurrent_state = EState::Turn;
            delete pCurrent_state;
            pCurrent_state = new StateTurn(*pGrid);
            pStart->setActive(false);
            pStop->setActive(false);
        }
        break;
    }
    sf::sleep(sf::milliseconds(5));
}

void StateMashine::start()
{
    eCurrent_state = EState::Acceleration;
    if (pCurrent_state != nullptr)
    {
        delete pCurrent_state;
    }
    pCurrent_state = new StateAcceleration(*pGrid);
    pStart->setActive(false);
    pStop->setActive(false);
}

void StateMashine::stop()
{
    eCurrent_state = EState::Deceleration;
    if (pCurrent_state != nullptr)
    {
        delete pCurrent_state;
    }
    pCurrent_state = new StateDeceleration(*pGrid);
    pStart->setActive(false);
    pStop->setActive(false);
}