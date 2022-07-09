#pragma once

#include "Entity.hpp"

class State
{
    private:
        sf::RenderWindow* window; 
        std::vector<sf::Texture> textures;
        bool quit; 

    public:
        //Constructors & Destructors
        State(sf::RenderWindow* window);
        virtual ~State();

        //Functions
        virtual void checkForQuit();
        const bool& getQuit() const;

        virtual void endState() = 0;
        virtual void updateKeybinds(const float& dt) = 0;
        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderTarget* target = nullptr) = 0;
};