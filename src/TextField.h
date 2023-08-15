// header file for TextField.cpp
#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

class TextField {
    public:
        TextField();
        TextField(int limitSize, bool isTextFieldSelected);
        void setTextFieldFont(sf::Font*);
        void setTextFieldCharSize(unsigned int charSize);
        void setTextFieldColor(sf::Color);
        void setTextFieldPosition(float x, float y);
        void drawTextField(sf::RenderWindow*);
        void setTextFieldFocus(bool);
        bool hasTextFieldFocus();
        float getTextFieldXPosition();
        float getTextFieldYPosition();
        int getTextFieldCharSize();
        int getTextFieldCharLimit();
        void typedInTextField(sf::Event*);


    private:
        sf::Text text;
        std::ostringstream textBuffer;
        bool hasFocus;
        int charLimit;

        std::string getTextFieldStr();
};

#endif