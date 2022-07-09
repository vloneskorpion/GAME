#pragma once
#include "State.hpp"


class GameState : public State
{
    private:
        Entity player;

    public:
        //Constructors & Destructors
        GameState(sf::RenderWindow* window);
        virtual ~GameState();

        //Functions
        void endState() override;
        void updateKeybinds(const float& dt) override;
        void update (const float& dt) override;
        void render (sf::RenderTarget* target = nullptr) override;
};