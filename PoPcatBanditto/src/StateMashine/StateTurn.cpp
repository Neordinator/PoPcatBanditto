#include "StateTurn.h"

StateTurn::StateTurn(Grid& _grid) : State(_grid), deltaY(2.f)
{
}

void StateTurn::update()
{
    if (pGrid->getHighestY() < 0.f)
    {
        pGrid->update(deltaY);
    }
    else
    {
        end();
    }
}