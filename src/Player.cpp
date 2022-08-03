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

    this->createMovementComponent(300.0f, 15.0f, 5.0f);
    this->createAnimationComponent(texture_sheet);

    this->animationComponent->addAnimation("IDLE_LEFT", 10.0f, 0, 1, 3, 1, 97, 97);
}

Player::~Player()
{

}

//Functions
void Player::update(const float& dt)
{
    movementComponent->update(dt);

    this->animationComponent->play("IDLE_LEFT", dt);
}