#pragma once

#include "State.hpp"

class GameState : public State
{
    private:
        Entity player;

        //Functions
        void initKeybinds() override;
        void loadKeybindsIni(const std::string& filepath);

    public:
        //Constructors & Destructors
        GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states);
        virtual ~GameState();

        //Functions
        void endState() override;
        void updateInput(const float& dt) override;
        void update (const float& dt) override;
        void render (sf::RenderTarget* target = nullptr) override;
};