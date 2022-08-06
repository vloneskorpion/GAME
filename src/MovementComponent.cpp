#include "MovementComponent.hpp"

//Constructors & destructors
MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity,
    float deceleration, float acceleration)
    : sprite(sprite), maxVelocity(maxVelocity), acceleration(acceleration), deceleration(deceleration)
{
}

MovementComponent::~MovementComponent()
{

}

//Accessors
const sf::Vector2f& MovementComponent::getVelocity() const
{
    return this->velocity;
}

//Functions
const bool MovementComponent::idle() const
{
    if(this->velocity.x == 0.0f && this->velocity.y == 0.0f) 
        return true;
    else
        return false;
}

void MovementComponent::move(const float dir_x, const float dir_y, const float& dt)
{
    //Accelerating a sprite until it reaches the max velocity

    this->velocity.x += this->acceleration * dir_x;
    this->velocity.y += this->acceleration * dir_y;
}

void MovementComponent::update(const float& dt)
{

    /* Decelerates the sprite and controls the maximum velocity
    Moves the sprite.
    */

    if(this->velocity.x > 0.0f)     //Check for positive x
    {
        //Max velocity check
        if(this->velocity.x  > this->maxVelocity)
            this->velocity.x = this->maxVelocity;
        
        //Deceleration
        this->velocity.x -= deceleration;
        if(this->velocity.x  < 0.0f)
            this->velocity.x = 0.0f;
    }
    else if(this->velocity.x < 0.0f) //Check for negative x 
    {
        //Max velocity check
        if(this->velocity.x  < -this->maxVelocity)
            this->velocity.x = -this->maxVelocity;

        //Deceleration
        this->velocity.x += deceleration;
        if(this->velocity.x  > 0.0f)
            this->velocity.x = 0.0f;
    }

    if(this->velocity.y > 0.0f)     //Check for positive y
    {
        //Max velocity check
        if(this->velocity.y  > this->maxVelocity)
            this->velocity.y = this->maxVelocity;
        
        //Deceleration
        this->velocity.y -= deceleration;
        if(this->velocity.y  < 0.0f)
            this->velocity.y = 0.0f;
    }
    else if(this->velocity.y < 0.0f) //Check for negative y 
    {
        //Max velocity check
        if(this->velocity.y  < -this->maxVelocity)
            this->velocity.y = -this->maxVelocity;

        //Deceleration
        this->velocity.y += deceleration;
        if(this->velocity.y  > 0.0f)
            this->velocity.y = 0.0f;
    }

    //Final move
    this->sprite.move(this->velocity * dt);
}