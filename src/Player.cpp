#include "Player.hpp"

//Initializer functions
void Player::initVariables()
{

}

void Player::initComponents()
{
    this->createMovementComponent(300.0f, 15.0f, 5.0f);
}

//Constructors & Destructors
Player::Player(float x, float y, sf::Texture& texture)
{
    this->initVariables();
    this->initComponents();

    this->setTexture(texture);
    this->setPosition(x, y);

}

Player::~Player()
{

}