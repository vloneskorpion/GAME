#include "GameState.hpp"

//Private Functions
void GameState::initTextures()
{
    if(!this->textures["PLAYER_IDLE"].loadFromFile("../resources/images/sprites/player/spider.jpeg"))
    {
        std::cout << "ERROR:GAME_STATE: COULDNT LOAD PLAYER TEXTURE" << '\n';
    }
}

void GameState::initPlayers()
{
    this->player = new Player(0, 0, &this->textures["PLAYER_IDLE"]);
}

void GameState::initKeybinds()
{
    this->loadKeybindsIni("../config/gamestate_keybinds.ini");
}

void GameState::loadKeybindsIni(const std::string& filepath)
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
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states) 
    :   State(window, supportedKeys, states)
{
    this->initKeybinds();
    this->initTextures();
    this->initPlayers();
}

GameState::~GameState()
{
    delete this->player;
}

//Functions
void GameState::updateInput(const float& dt)
{

    //Update player input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->getKeybinds().at("MOVE_LEFT"))))      this->player->move(dt, -1.0f,  0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->getKeybinds().at("MOVE_RIGHT"))))     this->player->move(dt,  1.0f,  0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->getKeybinds().at("MOVE_UP"))))        this->player->move(dt,  0.0f, -1.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->getKeybinds().at("MOVE_DOWN"))))      this->player->move(dt,  0.0f,  1.0f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->getKeybinds().at("CLOSE"))))          this->endState();
}

void GameState::update(const float& dt)
{
    this->updateMousePositions();
    this->updateInput(dt);

    this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
    if(!target)
        target = this->getWindow();

    this->player->render(target);
}
