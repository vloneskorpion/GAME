#pragma once

//Standard libs
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

//SFML
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Entity
{
    private:
        //Private functions
        void initVariables();

    protected:
        sf::Texture* texture;
        sf::Sprite* sprite; 

        float movementSpeed;

    public:
        //Constructors & Destructors
        Entity();
        virtual ~Entity();

        //Component functions
        void createSprite(sf::Texture* texture);

        //Functions
        virtual void move(const float& dt, const float x, const float y);

        virtual void update(const float& dt);
        virtual void render(sf::RenderTarget* target);
};