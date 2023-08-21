/*
    Defines Button class
    Header file for Button.cpp
*/
#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
    public:
        // constructor
        Button(std::string, unsigned int);
        // setters
        void setButtonTextFont(sf::Font&);
        void setButtonSize(sf::Vector2f);
        void setButtonColor(sf::Color);
        void setButtonTextColor(sf::Color);
        void setButtonOutlineColor(sf::Color);
        void setButtonPosition(sf::Vector2f);
        //getters
        sf::Vector2f getButtonSize();
        sf::Vector2f getButtonPosition();
        // draws button
        void drawButton(sf::RenderWindow&);
    private:
        sf::RectangleShape _buttonRect;
        sf::Text _buttonText;
};

#endif