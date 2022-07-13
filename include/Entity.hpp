#pragma once

#include "MovementComponent.hpp"

class Entity
{
    private:
        //Private functions
        void initVariables();

    protected:
        sf::Texture* texture;
        sf::Sprite* sprite;

        MovementComponent* movementComponent; 

    public:
        //Constructors & Destructors
        Entity();
        virtual ~Entity();

        //Component functions
        void createSprite(sf::Texture* texture);
        void createMovementComponent(const float maxVelocity);

        //Functions
        virtual void setPosition(const float x, const float y);
        virtual void move(const float& dt, const float x, const float y);

        virtual void update(const float& dt);
        virtual void render(sf::RenderTarget* target);
};