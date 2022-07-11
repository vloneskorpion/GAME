#include "Game.hpp"

//Initialization
void Game::initWindow()
{
    //Create SFML window using options from window.ini file
    this->loadWindowIni("../config/window.ini");
    this->videoModes = sf::VideoMode::getFullscreenModes();

    this->windowSettings.antialiasingLevel = this->antialiasingLevel;
    if(this->fullscreen)
        this->window = new sf::RenderWindow(this->windowMode, this->windowTitle, sf::Style::Fullscreen, this->windowSettings);
    else
        this->window = new sf::RenderWindow(this->windowMode, this->windowTitle, sf::Style::Titlebar | sf::Style::Close, this->windowSettings);
    this->window->setFramerateLimit(this->frameLimit);
    this->window->setVerticalSyncEnabled(this->vSync);
}

void Game::loadWindowIni(const std::string& filepath)
{
    std::ifstream stream(filepath);
    
    if(stream.is_open())
    {
        std::getline(stream, windowTitle);
        stream >> this->windowMode.width >> this->windowMode.height;
        stream >> this->fullscreen;
        stream >> this->frameLimit;
        stream >> this->vSync;
        stream >> this->antialiasingLevel;
    } else {std::cout << "ERROR: window.ini not found!";}

    stream.close();
}

void Game::initKeys()
{
    this->loadKeysIni("../config/supported_keys.ini");
}

void Game::loadKeysIni(const std::string& filepath)
{
    std::ifstream stream(filepath);
    std::string key; 
    int value;
    
    if(stream.is_open())
    {
        while(stream >> key >> value)
        {
            this->supportedKeys.insert(std::make_pair(key,value));
        }
    } else {std::cout << "ERROR: window.ini not found!";}

    stream.close();
}

void Game::initStates()
{
    this->states.push(new MainMenuState(this->window, &this->supportedKeys, this->states));
}

//Constructors & Destructors
Game::Game()
{
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game()
{
    delete this->window;

    while(!this->states.empty())
    {
        delete this->states.top();
        this->states.pop();
    }
        
}


//Functions

void Game::endAppliaction()
{
    std::cout << "ENDING GAME!" << '\n';
}

void Game::updateDt()
{
    //Updates the dt with the time it takes to update and render one frame
    this->dt = this->dtClock.restart().asSeconds();
    // std::cout << "Time elapsed: " << dt << '\n';
    // system("clear");
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

    if(!this->states.empty())
    {
        this->states.top()->update(this->dt);

        if(this->states.top()->getQuit()) 
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    //APPLICATION END
    else
    {
        this->endAppliaction();
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    if(!this->states.empty())
        this->states.top()->render(this->window);

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
