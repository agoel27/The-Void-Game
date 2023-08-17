#include "TextField.h"

/*
    Text Field - creates a text field that gets typed user input

    Note: Must use function to set font or else text wont show
*/

// default constructor
TextField::TextField() {}

// contructor takes text field character limit size and hasFocus as inputs
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

// set text font
void TextField::setTextFieldFont(sf::Font* p_textFieldFont) {
    text.setFont(*p_textFieldFont);
}

// set text size
void TextField::setTextFieldCharSize(unsigned int charSize) {
    text.setCharacterSize(charSize);
}

// set text color
void TextField::setTextFieldColor(sf::Color textColor) {
    text.setFillColor(textColor);
}

// set text position
void TextField::setTextFieldPosition(float x, float y) {
    text.setPosition(x, y);
}

// draw textbox and text
void TextField::drawTextField(sf::RenderWindow* p_gameWindow) {
    sf::RectangleShape textBox(sf::Vector2f(text.getCharacterSize()*charLimit, text.getCharacterSize())); 
    sf::Color lightBlue(3, 244, 252);
    textBox.setFillColor(lightBlue);
    textBox.setPosition(text.getPosition().x-3, text.getPosition().y+7);
    p_gameWindow->draw(textBox);
    p_gameWindow->draw(text);
}

// set text field focus
void TextField::setTextFieldFocus(bool sel) {
    // if has focus then display '_'
    if(sel) {
        text.setString(getTextFieldStr() + "_");
    }
    // else dont
    else {
        text.setString(getTextFieldStr());
    }
    // update value of hasFocus
    hasFocus = sel;
}

// return if text field has focus
bool TextField::hasTextFieldFocus() {
    return hasFocus;
}

// return x position of text field
float TextField::getTextFieldXPosition() {
    return text.getPosition().x;
}

// return y position of text field
float TextField::getTextFieldYPosition() {
    return text.getPosition().y;
}

// return character size of text
int TextField::getTextFieldCharSize() {
    return text.getCharacterSize();
}

// return character limit of text
int TextField::getTextFieldCharLimit() {
    return charLimit;
}

// updates and displays text and handles 'delete', 'enter', and 'tab' pressed 
void TextField::typedInTextField(sf::Event* p_textEntered) {
    int charTyped = p_textEntered->text.unicode;
    // if valid text is entered, text buffer updated and displayed
    if(charTyped >= 32 && charTyped <= 126) {
        // checks character limit
        if(getTextFieldStr().length() < charLimit) {
            textBuffer << static_cast<char>(charTyped);
            text.setString(getTextFieldStr() + "_");
        }
    }
    // if delete pressed, text buffer updated and displayed
    else if(charTyped == 8 && getTextFieldStr().length() > 0) {
        std::string newTextBuffer = getTextFieldStr().substr(0, getTextFieldStr().length()-1);
        textBuffer.str("");
        textBuffer << newTextBuffer;
        text.setString(getTextFieldStr() + "_");
    }
    // if enter or tab pressed, text field loses focus
    else if(charTyped == 9 || charTyped == 10) {
        setTextFieldFocus(false);
        text.setString(getTextFieldStr());
    }
}

// returns text string
std::string TextField::getTextFieldStr() {
    return textBuffer.str();
}