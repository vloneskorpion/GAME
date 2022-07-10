#include "MainMenuState.hpp"

//Private Functions
void MainMenuState::initFonts()
{
    if(!this->font.loadFromFile("../fonts/Cascadia.ttf"))
    {
        throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
    }
}

void MainMenuState::initKeybinds()
{
    this->loadKeybindsIni("../config/gamestate_keybinds.ini");
}

void MainMenuState::loadKeybindsIni(const std::string& filepath)
{
    std::ifstream stream(filepath);
    std::string left_key; 
    std::string right_key;

    if(stream.is_open())
    {
        while(stream >> left_key >> right_key)
        {
            this->getKeybinds()[left_key] = this->getSupportedKeys()->at(right_key);
        }
    } else {std::cout << "ERROR: window.ini not found!";}

    stream.close();
}

//Constructors & Destructors
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) 
    :   State(window, supportedKeys)
{
    this->initFonts();
    this->initKeybinds();

    this->gamestate_btn = new Button(100, 100, 150, 50,
                                    &this->font, "BUTTON",
                                    sf::Color(70,70,70, 200), sf::Color(150,150,150, 255), sf::Color(20,20,20, 200));

    this->background.setSize(sf::Vector2f(this->getWindow()->getSize().x, this->getWindow()->getSize().y));
    this->background.setFillColor(sf::Color::Blue);
}

MainMenuState::~MainMenuState()
{
    delete this->gamestate_btn;
}

//Functions
void MainMenuState::endState()
{
    std::cout << "ENDED MAIN MENU!" << '\n';
}

void MainMenuState::updateInput(const float& dt)
{
    this->checkForQuit();
}

void MainMenuState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);

    this->gamestate_btn->update(this->mousePosView);
}

void MainMenuState::render(sf::RenderTarget* target)
{
    if(!target)
        target = this->getWindow();
    target->draw(this->background);
    this->gamestate_btn->redner(target);
}