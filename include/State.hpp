#pragma once

#include "Player.hpp"

class State
{
    private:
        sf::RenderWindow* window; 
        std::map<std::string, int>* supportedKeys;
        std::map<std::string, int>  keybinds;

        bool quit; 

        
    
    protected:
        sf::Vector2i mousePosScreen;
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

        std::stack<State*>& states;

        //Resources
        std::map<std::string, sf::Texture> textures;

    public:
        //Constructors & Destructors
        State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states);
        virtual ~State();

        //Getters & Setters
        sf::RenderWindow* getWindow() const;
        const bool& getQuit() const;
        std::map<std::string, int>*  getSupportedKeys() const;
        std::map<std::string, int>&  getKeybinds();

        //Functions
        virtual void endState();

        //-> Update
        virtual void updateMousePositions();
        virtual void updateInput(const float& dt) = 0;
        virtual void update(const float& dt) = 0;

        virtual void render(sf::RenderTarget* target = nullptr) = 0;
        virtual void initKeybinds() = 0;
};