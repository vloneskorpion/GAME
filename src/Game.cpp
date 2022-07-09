#include "Game.hpp"

//Initialization
void Game::initWindow()
{
    //Create SFML window using options from window.ini file
    this->loadWindowIni("../config/window.ini");

    this->window = new sf::RenderWindow(windowMode, windowTitle);
    this->window->setFramerateLimit(frameLimit);
    this->window->setVerticalSyncEnabled(vSync);
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

void Game::loadWindowIni(const std::string& filepath)
{
    std::ifstream stream(filepath);
    
    if(stream.is_open())
    {
        std::getline(stream, windowTitle);
        stream >> windowMode.width >> windowMode.height;
        stream >> frameLimit;
        stream >> vSync;
    } else {std::cout << "window.ini not found!";}

    stream.close();
}