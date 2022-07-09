#pragma once
#include "State.hpp"


class GameState : public State
{
    private:
    public:
        //Constructors & Destructors
        GameState(sf::RenderWindow* window);
        virtual ~GameState();

        //Functions
        void endState() override;
        void update (const float& dt) override;
        void render (sf::RenderTarget* target = nullptr) override;
};