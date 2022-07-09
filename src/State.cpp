#include "State.hpp"

//Constructors & Destructors
State::State(sf::RenderWindow* window) 
    : window(window), quit(false)
{

}

State::~State()
{
    
}

void State::checkForQuit()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->quit = true;
}

const bool& State::getQuit() const
{
    return quit;
}