#pragma once

//Standard libs
#include <iostream>
#include <ctime>
#include <cstdlib>

//SFML
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//Headers

class Game
{
    private:
        //Variables
        sf::RenderWindow* window;
        sf::Event sfEvent;


        //Initialization
        void initWindow();
    public:
        //Constructors & Destructors
        Game();
        virtual ~Game();

        //Functions
        void updateSFMLEvents();
        void update();
        void render();
        void run();
};