#include "Game.hpp"

//Initialization
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "RPG");
}

//Constructors & Destructors
Game::Game()
{
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}


//Functions
void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render()
{
    this->window->clear();

    //Render here

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();

    }
}