#include "GameState.hpp"

//Private Functions
void GameState::initKeybinds()
{
    this->getKeybinds().emplace("MOVE_LEFT",    this->getSupportedKeys()->at("A"));
    this->getKeybinds().emplace("MOVE_RIGHT",   this->getSupportedKeys()->at("D"));
    this->getKeybinds().emplace("MOVE_UP",      this->getSupportedKeys()->at("W"));
    this->getKeybinds().emplace("MOVE_DOWN",    this->getSupportedKeys()->at("S"));
}

//Constructors & Destructors
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) 
    :   State(window, supportedKeys)
{
    this->initKeybinds();
}

GameState::~GameState()
{

}

//Functions
void GameState::endState()
{

}

void GameState::updateInput(const float& dt)
{
    this->checkForQuit();

    //Update player input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->getKeybinds().at("MOVE_LEFT"))))      this->player.move(dt, -1.0f,  0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->getKeybinds().at("MOVE_RIGHT"))))     this->player.move(dt,  1.0f,  0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->getKeybinds().at("MOVE_UP"))))        this->player.move(dt,  0.0f, -1.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->getKeybinds().at("MOVE_DOWN"))))      this->player.move(dt,  0.0f,  1.0f);
}

void GameState::update(const float& dt)
{
    this->updateInput(dt);

    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    if(!target)
        target = this->getWindow();

    this->player.render(target);
}
