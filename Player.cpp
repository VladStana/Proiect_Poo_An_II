#include "Player.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

void Player::initVariables()
{
    this -> movementSpeed= 4.f;
}
void Player::initTextures()
{
    this->playerTexture.loadFromFile("C:/Users/Vlad/Desktop/Proiect POO - Jump King/Images/Player/default.png");
    this->shape.setSize(sf::Vector2f(50.f, 65.f));
    this->shape.setPosition(20,395);
}

void Player::initSprites()
{
    this->playerSprite.setTexture(this->playerTexture);
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
}

void Player::render(sf::RenderTarget & target)
{
    target.draw(this->shape);
    target.draw(playerSprite);
}


