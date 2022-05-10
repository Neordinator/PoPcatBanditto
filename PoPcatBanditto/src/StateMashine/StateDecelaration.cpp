#include "StateDeceleration.h"

StateDeceleration::StateDeceleration(Grid& _grid) : State(_grid), deltaY(50.f)
{
}

void StateDeceleration::update()
{
    deltaY -= 0.5f;
    pGrid->update(deltaY);
    if (deltaY < 2.01f)
    {
        deltaY = 2.f;
        end();
    }
}
