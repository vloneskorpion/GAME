#pragma once

//Standard libs
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

//SFML
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum button_states
{
    BTN_IDLE,
    BTN_HOVER,
    BTN_ACTIVE,
};

class Button
{
    private:
        short unsigned buttonState;

        sf::RectangleShape shape;
        sf::Font* font;
        sf::Text text;

        sf::Color idleColor;
        sf::Color hoverColor;
        sf::Color activeColor;

        //Functions
        void switchState();

    public:
        Button  (float x, float y, float width, float height,
                sf::Font* font, std::string text,
                sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
        
        ~Button();


        //Accessors
        const bool isPressed() const;

        //Functions
        void update(const sf::Vector2f mousePos);
        void redner(sf::RenderTarget* target);
};