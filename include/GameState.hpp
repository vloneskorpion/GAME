#pragma once

#include "State.hpp"

class GameState : public State
{
    private:
        Player* player;

        //Functions
        void initTextures();
        void initPlayers();
        void initKeybinds() override;
        void loadKeybindsIni(const std::string& filepath);

    public:
        //Constructors & Destructors
        GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states);
        virtual ~GameState();

        //Functions
        void updateInput(const float& dt) override;
        void update (const float& dt) override;
        void render (sf::RenderTarget* target = nullptr) override;
};