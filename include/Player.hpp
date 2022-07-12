#pragma once
#include "Entity.hpp"

class Player : public Entity
{
    private:
        //Variables

        
        //Initializer functions
        void initVariables();
        void initComponents();

    public:
        Player(float x, float y, sf::Texture* texture);
        virtual ~Player();

        //Functions
}; 