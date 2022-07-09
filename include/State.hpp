#pragma once

#include "Entity.hpp"

class State
{
    private:
        sf::RenderWindow* window; 
        std::map<std::string, int>* supportedKeys;
        std::map<std::string, int>  keybinds;

        bool quit; 

        //Resources
        std::vector<sf::Texture> textures;

    public:
        //Constructors & Destructors
        State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
        virtual ~State();

        //Getters & Setters
        sf::RenderWindow* getWindow() const;
        const bool& getQuit() const;
        std::map<std::string, int>*  getSupportedKeys() const;
        std::map<std::string, int>&  getKeybinds();

        //Functions
        virtual void checkForQuit();
        virtual void endState() = 0;
        virtual void updateInput(const float& dt) = 0;
        virtual void update(const float& dt) = 0;
        virtual void render(sf::RenderTarget* target = nullptr) = 0;
        virtual void initKeybinds() = 0;
};