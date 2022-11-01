#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

class Player{

private:
    sf::RectangleShape shape;
    //Texturi player
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
    float movementSpeed;
    void initSprites();
    void initVariables();
    void initTextures();


public:
    Player(float x = 0.f, float y = 0.f);
    virtual ~Player();

    void update();
    void updateInput();
    void render(sf::RenderTarget& target);

};


#endif //OOP_PLAYER_H
