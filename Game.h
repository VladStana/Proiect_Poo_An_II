#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Player.h"

/*
 * Class that acts like a Game Engine
*/


class Game {
private:

    //Variables
    //Window
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    Player player;

    //World
    sf::Texture levelBackgroundTexture;
    sf::Sprite levelBackground;

    //Game objects

    //Private functions
    void initializeVariables();
    void initializeWorld();
    void initializeWindow();
    void initializeCollision();

public:
    //Constructors & Destructors
    Game();
    virtual ~Game();

    //Accessors
    bool running() const;

    //Functions
    void pollEvents();
    void update();
    void render();
    void renderWorld();


};


#endif
