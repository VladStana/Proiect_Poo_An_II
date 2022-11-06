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
    bool isOnGround;

    void initSprites();
    void initVariables();
    void initTextures();


public:
    Player(float x = 0.f, float y = 0.f);
    virtual ~Player();

    void Gravity();
    void update();
    void updateInput();
    void render(sf::RenderTarget& target);

};

class PlayerState{
private:
    bool isOnGround;
    float currentPos;
    float currentSpeed;

    bool jumpHeld = false;
    int jumpTimer;
    bool leftHeld = false;
    bool rightHeld = false;

    unsigned int currentLevelNo = 0;

    unsigned int jumpStartingHeight = 0;
    bool hasFallen = false;
public:

    void jump();

};


#endif //OOP_PLAYER_H
