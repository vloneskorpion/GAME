#include "MainMenuState.hpp"

//Private Functions
void MainMenuState::initBackground()
{
    this->background.setSize(sf::Vector2f(this->getWindow()->getSize().x, this->getWindow()->getSize().y));
    
    if(!this->backgroundTexture.loadFromFile("../resources/images/backgrounds/mine.jpg"))
        std::cout << "ERROR: COULDNT LOAD TEXTURE" << '\n';

    this->background.setTexture(&backgroundTexture);
}

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
    this->buttons["GAME_STATE"] =   new Button(300, 480, 250, 70,
                                &this->font, "NEW GAME", 50,
                                sf::Color(23, 77, 194, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
                                sf::Color(23, 77, 194, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    this->buttons["SETTINGS"] =     new Button(300, 580, 250, 70,
                                &this->font, "SETTINGS", 50,
                                sf::Color(23, 77, 194, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
                                sf::Color(23, 77, 194, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

    this->buttons["EDITOR_STATE"] = new Button(300, 680, 250, 70,
                                &this->font, "EDITOR", 50,
                                sf::Color(23, 77, 194, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
                                sf::Color(23, 77, 194, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));


    this->buttons["EXIT"] =         new Button(300, 880, 250, 70,
                                &this->font, "EXIT", 50,
                                sf::Color(23, 77, 194, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
                                sf::Color(23, 77, 194, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
}

//Constructors & Destructors
MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states) 
    :   State(window, supportedKeys, states)
{
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();
}

MainMenuState::~MainMenuState()
{
    for(auto it = buttons.begin(); it != buttons.end(); ++it)
    {
        delete it->second;
    }
}

//Functions
void MainMenuState::updateInput(const float& dt)
{

}

void MainMenuState::updateButtons()
{
    //Updated all buttons in the state and handles their functionality
    for(const auto& kv : buttons)
    {
        kv.second->update(mousePosView);
    }

    //New game
    if(this->buttons["GAME_STATE"]->isPressed())
    {
        this->states.push(new GameState(this->getWindow(), this->getSupportedKeys(), this->states));
    }

    //Editor
    if(this->buttons["EDITOR_STATE"]->isPressed())
    {
        this->states.push(new EditorState(this->getWindow(), this->getSupportedKeys(), this->states));
    }

    //Quit the game
    if(this->buttons["EXIT"]->isPressed())
    {
        this->endState();
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


    //REMOVE LATER - just for checking mouse pos
    // sf::Text mouseTex;
    // mouseTex.setPosition(this->mousePosView.x + 30, this->mousePosView.y);
    // mouseTex.setFont(this->font);
    // mouseTex.setCharacterSize(12);
    // std::stringstream ss;
    // ss << this->mousePosView.x << " " << this->mousePosView.y;
    // mouseTex.setString(ss.str());
    // target->draw(mouseTex);
} 

//9:08 film 24 