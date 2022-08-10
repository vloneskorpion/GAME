#pragma once

#include "State.hpp"
#include "Button.hpp"

class EditorState : public State
{
    private:
        //Variables
        sf::Texture backgroundTexture;
        sf::RectangleShape background;
        sf::Font font;

        std::map<std::string, Button*> buttons;

        //Functions
        void initBackground();
        void initFonts();
        void initKeybinds() override;
        void loadKeybindsIni(const std::string& filepath);
        void initButtons();

    public:
        //Constructors & Destructors
        EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys, std::stack<State*>& states);
        virtual ~EditorState();

        //Functions
        void updateInput(const float& dt) override;
        void updateButtons();
        void renderButtons(sf::RenderTarget* target = nullptr);
        void update (const float& dt) override;
        void render (sf::RenderTarget* target = nullptr) override;
};