#include "Player.hpp"

//Initializer functions
void Player::initVariables()
{

}

void Player::initComponents()
{

}

//Constructors & Destructors
Player::Player(float x, float y, sf::Texture& texture_sheet)
{
    this->initVariables();

    this->setPosition(x, y);

    this->sprite.scale(3.5f, 3.5f);
    this->createMovementComponent(300.0f, 15.0f, 5.0f);
    this->createAnimationComponent(texture_sheet);

    this->animationComponent->addAnimation("IDLE",          10.0f, 0, 0, 0, 0, 32, 31);
    this->animationComponent->addAnimation("WALK_RIGHT",    10.0f, 3, 0, 2, 0, 32, 31);
    this->animationComponent->addAnimation("WALK_LEFT",     10.0f, 9, 0, 2, 0, 32, 31);
    this->animationComponent->addAnimation("WALK_UP",       10.0f, 6, 0, 2, 0, 32, 31);
    this->animationComponent->addAnimation("WALK_DOWN",     10.0f, 0, 0, 2, 0, 32, 31);

    this->animationComponent->addAnimation("STAND_RIGHT",   10.0f, 3, 0, 0, 0, 32, 31);
    this->animationComponent->addAnimation("STAND_LEFT",    10.0f, 9, 0, 0, 0, 32, 31);
    this->animationComponent->addAnimation("STAND_UP",      10.0f, 6, 0, 0, 0, 32, 31);
    this->animationComponent->addAnimation("STAND_DOWN",    10.0f, 0, 0, 0, 0, 32, 31);
}

Player::~Player()
{

}

//Functions
void Player::update(const float& dt)
{
    movementComponent->update(dt);

    if(this->movementComponent->getState(IDLE))
    {
        if(this->animationComponent->getAnimationKey() == "WALK_UP")
            this->animationComponent->play("STAND_UP", dt);
        else if(this->animationComponent->getAnimationKey() == "WALK_DOWN")
            this->animationComponent->play("STAND_DOWN", dt);
        else if(this->animationComponent->getAnimationKey() == "WALK_LEFT")
            this->animationComponent->play("STAND_LEFT", dt);
        else if(this->animationComponent->getAnimationKey() == "WALK_RIGHT")
            this->animationComponent->play("STAND_RIGHT", dt);

        else if(this->animationComponent->getAnimationKey() == "STAND_UP")
            this->animationComponent->play("STAND_UP", dt);
        else if(this->animationComponent->getAnimationKey() == "STAND_DOWN")
            this->animationComponent->play("STAND_DOWN", dt);
        else if(this->animationComponent->getAnimationKey() == "STAND_LEFT")
            this->animationComponent->play("STAND_LEFT", dt);
        else if(this->animationComponent->getAnimationKey() == "STAND_RIGHT")
            this->animationComponent->play("STAND_RIGHT", dt);
    }
    else if(this->movementComponent->getState(MOVING_UP))
        this->animationComponent->play("WALK_UP", dt);
    else if(this->movementComponent->getState(MOVING_DOWN))
        this->animationComponent->play("WALK_DOWN", dt);
    else if(this->movementComponent->getState(MOVING_LEFT))
        this->animationComponent->play("WALK_LEFT", dt);
    else if(this->movementComponent->getState(MOVING_RIGHT))
        this->animationComponent->play("WALK_RIGHT", dt);
}