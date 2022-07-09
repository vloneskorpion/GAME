#include "GameState.hpp"

//Constructors & Destructors
GameState::GameState(sf::RenderWindow* window) :
    State(window)
{

}

GameState::~GameState()
{

}

//Functions

void GameState::endState()
{

}

void GameState::updateKeybinds(const float& dt)
{
    this->checkForQuit();
}

void GameState::update(const float& dt)
{
    this->updateKeybinds(dt);

    this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    this->player.render(target);
}