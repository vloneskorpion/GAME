#pragma once

#include "GameState.hpp"

class Game
{
    private:
        //VARIABLES
        sf::RenderWindow* window;
        sf::Event sfEvent;

        //-> Window options
        std::string windowTitle;
        sf::VideoMode windowMode;
        unsigned int frameLimit;
        bool vSync;

        //-> Time options
        sf::Clock dtClock;
        float dt;

        //-> Game states
        std::stack<State*> states;

        //-> Core
        std::map<std::string, int> supportedKeys;

        //Initialization
        void initWindow();
        void loadWindowIni(const std::string& filepath);
        void initKeys();
        void initStates();

    public:
        //Constructors & Destructors
        Game();
        virtual ~Game();

        //Functions

        //-> Regular
        void endAppliaction();

        //-> Update
        void updateDt();
        void updateSFMLEvents();
        void update();
        
        //-> Render
        void render();

        //-> Core
        void run();
};