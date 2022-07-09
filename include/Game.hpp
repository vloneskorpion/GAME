#pragma once

#include "State.hpp"

class Game
{
    private:
        //VARIABLES
        sf::RenderWindow* window;
        sf::Event sfEvent;

        //-> window options
        std::string windowTitle;
        sf::VideoMode windowMode; //window options
        unsigned int frameLimit;
        bool vSync;

        //-> time options
        sf::Clock dtClock;
        float dt;

        //Initialization
        void initWindow();
        void loadWindowIni(const std::string& filepath);
    public:
        //Constructors & Destructors
        Game();
        virtual ~Game();

        //Functions
        void updateDt();
        void updateSFMLEvents();
        void update();
        void render();
        void run();
};