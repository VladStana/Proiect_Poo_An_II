#include <iostream>
#include "Game.h" //We include this so we don't need to include all the libraries everytime. Optimization stuff


int main() {

    //initializare Game Engine
    Game game;

    //Game Loop
    while(game.running())
    {
        //Update
        game.update();
        //Render
        game.render();
    }

    return 0;
}
