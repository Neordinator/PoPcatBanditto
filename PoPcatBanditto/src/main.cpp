#include <ctime>

#include "Game/Game.h"

int main(int argc, char* argv[])
{
    srand(static_cast<unsigned int>(time(NULL)));

    Game game(1280.f, 720.f);
    game.run();

    return 0;
}