#pragma once

//Standard libs
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

//SFML
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State
{
    private:
        std::vector<sf::Texture> textures; 


    public:
        //Constructors & Destructors
        State();
        virtual ~State();

        //Functions
        virtual void update() = 0;
        virtual void render() = 0;
};