#pragma once

#include "GameState.hpp"
#include "Button.hpp"

class MainMenuState : public State
{
    private:

        //Variables
        sf::RectangleShape background;
        sf::Font font;

        Button* gamestate_btn;

        //Functions
        void initFonts();
        void initKeybinds() override;
        void loadKeybindsIni(const std::string& filepath);

    public:
        //Constructors & Destructors
        MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
        virtual ~MainMenuState();

        //Functions
        void endState() override;
        void updateInput(const float& dt) override;
        void update (const float& dt) override;
        void render (sf::RenderTarget* target = nullptr) override;
};