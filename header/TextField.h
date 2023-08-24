/*
    Defines TextField class
    Header file for TextField.cpp
*/
#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

class TextField {
    public:
        // contructor
        TextField(int, unsigned int, bool);
        // setters
        void setTextFont(sf::Font&);
        void setTextFieldColor(sf::Color);
        void setTextColor(sf::Color);
        void setTextFieldOutlineColor(sf::Color);
        void setTextFieldSize(sf::Vector2f);
        void setTextFieldPosition(sf::Vector2f);
        void setTextFieldFocus(bool);
        bool getTextFieldFocus();
        // getters
        sf::Vector2f getTextFieldPosition();
        sf::Vector2f getTextFieldSize();
        unsigned int getTextCharSize();
        int getTextCharLimit();
        std::string getTextFieldStr();
        // draws text field
        void drawTextField(sf::RenderWindow&);
        // handles text field input
        void processTextFieldInput(sf::Event&);

    private:
        sf::Text _text;
        std::ostringstream _textBuffer;
        sf::RectangleShape _textFieldRect;
        bool _hasFocus;
        int _charLimit;
};

#endif