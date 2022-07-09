#include "State.hpp"

//Constructors & Destructors
State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) 
    : window(window), quit(false), supportedKeys(supportedKeys)
{

}

State::~State()
{
    
}

//Functions

sf::RenderWindow* State::getWindow() const
{
    return window; 
}

void State::checkForQuit()
{
    if(sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(this->getKeybinds()["CLOSE"]))) 
        this->quit = true;
}

const bool& State::getQuit() const
{
    return quit;
}

std::map<std::string, int>* State::getSupportedKeys() const
{
    return supportedKeys;
}

std::map<std::string, int>& State::getKeybinds()
{
    return keybinds;
}