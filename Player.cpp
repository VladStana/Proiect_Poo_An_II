#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

//initializam variabilele playerului
void Player::initVariables()
{
    this -> movementSpeed= 4.f;
}

//generam playerul si ii aplicam texturi
void Player::initTextures()
{
    this->playerTexture.loadFromFile("C:/Users/Vlad/Desktop/Proiect POO - Jump King/Images/Player/default.png");
    shape.setTexture(&playerTexture);
    this->shape.setSize(sf::Vector2f(93.f, 103.f));
    this->shape.setPosition(20,360);
}

void Player::Gravity ()
{
    if (!this->isOnGround)
        shape.move(0, 3);

}

void Player::initSprites()
{
   // this->playerSprite.setTexture(this->playerTexture);
}

Player::Player(float x, float y)
{
    this -> shape.setPosition(x,y);

    this -> initVariables();
    this -> initTextures();
    this -> initSprites();
}

Player::~Player()
{

}

void Player::updateInput() {

    //Keyboard input movement

    //Miscare la stanga
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this -> shape.move(-this -> movementSpeed, 0.f);
    }
    //Miscare la dreapta
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this -> shape.move(this -> movementSpeed,0.f);
    }
}

void Player::update()
{
    //window bounds collision //to be done
    this->updateInput();
    this->Gravity();
}

void Player::render(sf::RenderTarget & target)
{
    target.draw(this->shape);
    target.draw(playerSprite);
}



