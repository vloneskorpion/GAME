#pragma once

#include "HitboxComponent.hpp"
#include "MovementComponent.hpp"
#include "AnimationComponent.hpp"

class Entity
{
    private:
        //Private functions
        void initVariables();

    protected:
        sf::Sprite sprite;

        HitboxComponent* hitboxComponent;
        MovementComponent* movementComponent;
        AnimationComponent* animationComponent; 

    public:
        //Constructors & Destructors
        Entity();
        virtual ~Entity();

        //Component functions
        void setTexture(sf::Texture& texture);
        void createMovementComponent(const float maxVelocity, const float acceleration, const float deceleration);
        void createAnimationComponent(sf::Texture& texture_sheet);

        //Functions
        virtual void setPosition(const float x, const float y);
        virtual void move(const float x, const float y, const float& dt);

        virtual void update(const float& dt);
        virtual void render(sf::RenderTarget* target);
};