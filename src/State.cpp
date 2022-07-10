#include "State.hpp"

//Constructors & Destructors
State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states) 
    : window(window), quit(false), supportedKeys(supportedKeys), states(states)
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

void State::quitState()
{
    quit = true;
}

std::map<std::string, int>* State::getSupportedKeys() const
{
    return supportedKeys;
}

std::map<std::string, int>& State::getKeybinds()
{
    return keybinds;
}

void State::updateMousePositions()
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView   = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}