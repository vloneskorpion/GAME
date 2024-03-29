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

class HitboxComponent
{
    private:
        sf::Sprite& sprite;
        sf::RectangleShape hitbox;
        float offsetX;
        float offsetY;

    public:
        //Constructors && Destructors
        HitboxComponent(sf::Sprite& sprite, 
        float offset_x, float offset_y, 
        float width, float height);

        virtual ~HitboxComponent();

        //Functions
        bool checkIntersect(const sf::FloatRect& frect);


        void update();
        void render(sf::RenderTarget& target);
};