#include "Game.h"
#include "Player.h"
//Private Functions

void Game::initializeVariables()
{
    this-> window = nullptr; //initializam ca null pointer
}

void Game::initializeWindow()
{
    this-> videoMode.height=900;
    this-> videoMode.width=1200;
    //this-> videoMode.getDesktopMode() ar lua rezolutia ecranului direct cand vrem un joc mai dinamic
    this-> window = new sf::RenderWindow(this->videoMode, "Jump King", sf::Style::Titlebar | sf::Style::Close);
    this-> window ->setFramerateLimit(60);
}

void Game::initializeWorld()
{
    if(!this->levelBackgroundTexture.loadFromFile("C:/Users/Vlad/Desktop/Proiect POO - Jump King/Images/1.png"))
    {std::cout<<"Error! Could not load level background";}
    this->levelBackground.setTexture(this->levelBackgroundTexture);
}

//Constructors & Destructors

Game::Game()
{
    this -> initializeVariables();
    this -> initializeWindow();
    this -> initializeWorld();
    //this -> initializeEnemies();
}

Game::~Game()
{
    delete this->window;
}
//Accessors
 bool Game::running() const
{
    return this->window->isOpen();
}

//Functions
void Game::pollEvents()
{

//Event polling
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
            case sf::Event::Resized:
                break;
            case sf::Event::LostFocus:
                break;
            case sf::Event::GainedFocus:
                break;
            case sf::Event::TextEntered:
                break;
            case sf::Event::KeyReleased:
                break;
            case sf::Event::MouseWheelMoved:
                break;
            case sf::Event::MouseWheelScrolled:
                break;
            case sf::Event::MouseButtonPressed:
                break;
            case sf::Event::MouseButtonReleased:
                break;
            case sf::Event::MouseMoved:
                break;
            case sf::Event::MouseEntered:
                break;
            case sf::Event::MouseLeft:
                break;
            case sf::Event::JoystickButtonPressed:
                break;
            case sf::Event::JoystickButtonReleased:
                break;
            case sf::Event::JoystickMoved:
                break;
            case sf::Event::JoystickConnected:
                break;
            case sf::Event::JoystickDisconnected:
                break;
            case sf::Event::TouchBegan:
                break;
            case sf::Event::TouchMoved:
                break;
            case sf::Event::TouchEnded:
                break;
            case sf::Event::SensorChanged:
                break;
            case sf::Event::Count:
                break;
        }
    }
}

void Game::update()
{
    this -> pollEvents();
    player.updateInput();
}

void Game::renderWorld()
{
    this -> window -> draw(this->levelBackground);
}

void Game::render()
{
    this -> window -> clear();
    this -> renderWorld();

    player.render(*this->window);

    this -> window -> display();
}


