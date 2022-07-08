#include "Game.hpp"

//Initialization
void Game::initWindow()
{
    //Create SFML window using options from windows.ini file
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
void Game::updateDt()
{
    //Updates the dt with the time it takes to update and render one frame
    this->dt = this->dtClock.restart().asSeconds();
    std::cout << "Time elapsed: " << dt << '\n';
    system("clear");
}

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
        this->updateDt();
        this->update();
        this->render();
    }
}