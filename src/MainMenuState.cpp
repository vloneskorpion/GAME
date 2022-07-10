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
    this->loadKeybindsIni("../config/mainmenustate_keybinds.ini");
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

void MainMenuState::initButtons()
{
    this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50,
                                &this->font, "NEW GAME",
                                sf::Color(70,70,70, 200), sf::Color(150,150,150, 255), sf::Color(20,20,20, 200));

    this->buttons["EXIT"] = new Button(100, 300, 150, 50,
                                &this->font, "EXIT",
                                sf::Color(70,70,70, 200), sf::Color(150,150,150, 255), sf::Color(20,20,20, 200));
}

//Constructors & Destructors
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states) 
    :   State(window, supportedKeys, states)
{
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    this->background.setSize(sf::Vector2f(this->getWindow()->getSize().x, this->getWindow()->getSize().y));
    this->background.setFillColor(sf::Color::Blue);
}

MainMenuState::~MainMenuState()
{
    for(auto it = buttons.begin(); it != buttons.end(); ++it)
    {
        delete it->second;
    }
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

void MainMenuState::updateButtons()
{
    //Updated all buttons in the state and handles their functionality
    for(const auto& kv : buttons)
    {
        kv.second->update(mousePosView);
    }

    if(this->buttons["GAME_STATE"]->isPressed())
    {
        this->states.push(new GameState(this->getWindow(), this->getSupportedKeys(), this->states));
    }

    //Quit the game
    if(this->buttons["EXIT"]->isPressed())
    {
        this->quitState();
    }
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
    for(const auto& kv : buttons)
    {
        kv.second->redner(target);
    }
}

void MainMenuState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);

    this->updateButtons();

}

void MainMenuState::render(sf::RenderTarget* target)
{
    if(!target)
        target = this->getWindow();
    target->draw(this->background);

    this->renderButtons(target);
}