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
    
    protected:
        sf::Vector2i mousePosScreen;
        sf::Vector2i mousePosWindow;
        sf::Vector2f mousePosView;

    public:
        //Constructors & Destructors
        State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
        virtual ~State();

        //Getters & Setters
        sf::RenderWindow* getWindow() const;
        const bool& getQuit() const;
        //TODO resolve quit function later
        void quitState();
        std::map<std::string, int>*  getSupportedKeys() const;
        std::map<std::string, int>&  getKeybinds();

        //Functions
        virtual void checkForQuit();
        virtual void endState() = 0;

        //-> Update
        virtual void updateMousePositions();
        virtual void updateInput(const float& dt) = 0;
        virtual void update(const float& dt) = 0;

        virtual void render(sf::RenderTarget* target = nullptr) = 0;
        virtual void initKeybinds() = 0;
};