#include "TextField.h"

TextField::TextField() {}

TextField::TextField(int limitSize, bool isTextFieldSelected) {
    charLimit = limitSize;
    hasFocus = isTextFieldSelected;
    if(hasFocus) {
        text.setString("_");
    }
    else {
        text.setString("");
    }
}

void TextField::setTextFieldFont(sf::Font* p_textFieldFont) {
    text.setFont(*p_textFieldFont);
}

void TextField::setTextFieldCharSize(unsigned int charSize) {
    text.setCharacterSize(charSize);
}

void TextField::setTextFieldColor(sf::Color textColor) {
    text.setFillColor(textColor);
}

void TextField::setTextFieldPosition(float x, float y) {
    text.setPosition(x, y);
}

void TextField::drawTextField(sf::RenderWindow* p_gameWindow) {
    sf::RectangleShape textBox(sf::Vector2f(text.getCharacterSize()*charLimit, text.getCharacterSize())); 
    sf::Color lightBlue(3, 244, 252);
    textBox.setFillColor(lightBlue);
    textBox.setPosition(text.getPosition().x-3, text.getPosition().y+7);
    p_gameWindow->draw(textBox);
    p_gameWindow->draw(text);
}

void TextField::setTextFieldFocus(bool sel) {
    if(!hasFocus && sel) {
        text.setString(getTextFieldStr() + "_");
    }
    if(hasFocus && !sel) {
        text.setString(getTextFieldStr());
    }
    hasFocus = sel;
}

bool TextField::hasTextFieldFocus() {
    return hasFocus;
}

float TextField::getTextFieldXPosition() {
    return text.getPosition().x;
}

float TextField::getTextFieldYPosition() {
    return text.getPosition().y;
}

int TextField::getTextFieldCharSize() {
    return text.getCharacterSize();
}

int TextField::getTextFieldCharLimit() {
    return charLimit;
}

void TextField::typedInTextField(sf::Event* p_textEntered) {
    int charTyped = p_textEntered->text.unicode;
    if(charTyped >= 32 && charTyped <= 126) {
        if(getTextFieldStr().length() < charLimit) {
            textBuffer << static_cast<char>(charTyped);
            text.setString(getTextFieldStr() + "_");
        }
    }
    else if(charTyped == 8 && getTextFieldStr().length() > 0) {
        std::string newTextBuffer = getTextFieldStr().substr(0, getTextFieldStr().length()-1);
        textBuffer.str("");
        textBuffer << newTextBuffer;
        text.setString(getTextFieldStr() + "_");
    }
    else if(charTyped == 9 || charTyped == 10) {
        setTextFieldFocus(false);
        text.setString(getTextFieldStr());
    }
}

std::string TextField::getTextFieldStr() {
    return textBuffer.str();
}