#include "Entity.hpp"

Entity::Entity()
{
    this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
    this->shape.setFillColor(sf::Color::Magenta);
    this->movementSpeed = 100.0f;
}

Entity::~Entity()
{

}

//Functions

void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
    this->shape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
}

void Entity::update(const float& dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->move(dt, -1.0f, 0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->move(dt, 1.0f, 0.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->move(dt, 0.0f, -1.0f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->move(dt, 0.0f, 1.0f);
    }
}

void Entity::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}