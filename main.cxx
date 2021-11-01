#include <iostream>
#include "controller.hxx"

int
main()
{
    Game game;
    Controller controller(game);

    controller.run();
}