#include "StateAcceleration.h"

StateAcceleration::StateAcceleration(Grid& _grid) : State(_grid), deltaY(0.f)
{
}

void StateAcceleration::update()
{
    if (deltaY > 49.99f)
    {
        deltaY = 50.f;
        end();
    }
    deltaY += 0.5f;
    pGrid->update(deltaY);
}
