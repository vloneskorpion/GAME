#include "EditorState.hpp"

//Private Functions
void EditorState::initBackground()
{

}

void EditorState::initFonts()
{
    if(!this->font.loadFromFile("../fonts/Cascadia.ttf"))
    {
        throw("ERROR::EDITORSTATE::COULD NOT LOAD FONT");
    }
}

void EditorState::initKeybinds()
{
    this->loadKeybindsIni("../config/editorstate_keybinds.ini");
}

void EditorState::loadKeybindsIni(const std::string& filepath)
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

void EditorState::initButtons()
{
}

//Constructors & Destructors
EditorState::EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states) 
    :   State(window, supportedKeys, states)
{
    this->initBackground();
    this->initFonts();
    this->initKeybinds();
    this->initButtons();
}

EditorState::~EditorState()
{
    for(auto it = buttons.begin(); it != buttons.end(); ++it)
    {
        delete it->second;
    }
}

//Functions
void EditorState::updateInput(const float& dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->getKeybinds().at("CLOSE"))))          this->endState();
}

void EditorState::updateButtons()
{
    //Updated all buttons in the state and handles their functionality
    for(const auto& kv : buttons)
    {
        kv.second->update(mousePosView);
    }
}

void EditorState::renderButtons(sf::RenderTarget* target)
{
    for(const auto& kv : buttons)
    {
        kv.second->redner(target);
    }
}

void EditorState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);

    this->updateButtons();

}

void EditorState::render(sf::RenderTarget* target)
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