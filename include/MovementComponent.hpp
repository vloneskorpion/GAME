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


class MovementComponent
{
    private:
        float maxVelocity;
        sf::Vector2f velocity;
        sf::Vector2f acceleration;
        sf::Vector2f deceleration;
        
        //Initializer functions



    public:
        //Constructors & destructors
        MovementComponent(float maxVelocity);
        virtual ~MovementComponent();

        //Accessors
        const sf::Vector2f& getVelocity() const;


        //Functions
        void move(const float dir_x, const float dir_y);
        void update(const float& dt);
};