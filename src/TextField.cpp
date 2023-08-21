#include "TextField.h"

/*
    Implements Text Field class related functions
    Text Field handles typed user input

    NOTE: 
    Must set font and text field size else text and text field wont show

    Credits:
    https://www.youtube.com/watch?v=T31MoLJws4U&ab_channel=TermSpar
    https://learnsfml.com/how-to-center-text/
*/

// contructor takes character limit size, text size, font, and a boolean that determines if the text field has focus by default
TextField::TextField(int limitSize, unsigned int charSize, bool isTextFieldSelected) {
    _charLimit = limitSize;
    _text.setCharacterSize(charSize);
    _hasFocus = isTextFieldSelected;
    if(_hasFocus) {
        _text.setString("_");
        setTextFieldPosition(getTextFieldPosition());
    }
    else {
        _text.setString("");
        setTextFieldPosition(getTextFieldPosition());
    }
    // reset position since text buffer was updated
    setTextFieldPosition(getTextFieldPosition());
    _textBuffer.str("");
}

//sets text font
void TextField::setTextFont(sf::Font& textFont) {
    _text.setFont(textFont);
}

// sets text field color
void TextField::setTextFieldColor(sf::Color rectColor) {
    _textFieldRect.setFillColor(rectColor);
}

// sets text color
void TextField::setTextColor(sf::Color textColor) {
    _text.setFillColor(textColor);
}

// sets text field size
void TextField::setTextFieldSize(sf::Vector2f textFieldSize) {
    _textFieldRect.setSize(textFieldSize);
}

// sets text position
void TextField::setTextFieldPosition(sf::Vector2f textFieldRectPosition) {
    _textFieldRect.setPosition(sf::Vector2f(sf::Vector2u(textFieldRectPosition)));
    _text.setOrigin(sf::Vector2f(sf::Vector2u(_text.getGlobalBounds().getSize()/2.f + _text.getLocalBounds().getPosition())));
    _text.setPosition(sf::Vector2f(sf::Vector2u(textFieldRectPosition + _textFieldRect.getSize()/2.f)));
}

// sets text field focus
void TextField::setTextFieldFocus(bool sel) {
    // if has focus then display '_'
    if(sel) {
        _text.setString(getTextFieldStr() + "_");
    }
    // else dont
    else {
        _text.setString(getTextFieldStr());
    }
    // reset position since text buffer was updated
    setTextFieldPosition(getTextFieldPosition());
    // update value of hasFocus
    _hasFocus = sel;
}

// gets text field focus
bool TextField::getTextFieldFocus() {
    return _hasFocus;
}

// return x position of text field
sf::Vector2f TextField::getTextFieldPosition() {
    return _textFieldRect.getPosition();
}

sf::Vector2f TextField::getTextFieldSize() {
    return _textFieldRect.getSize();
}

// return character size of text
unsigned int TextField::getTextCharSize() {
    return _text.getCharacterSize();
}

// return character limit of text
int TextField::getTextCharLimit() {
    return _charLimit;
}

// returns text string
std::string TextField::getTextFieldStr() {
    return _textBuffer.str();
}

// draws text field and text
void TextField::drawTextField(sf::RenderWindow& gameWindow) {
    _textFieldRect.setOutlineThickness(2.f);
    _textFieldRect.setOutlineColor(sf::Color::Black);
    gameWindow.draw(_textFieldRect);
    gameWindow.draw(_text);
}

// updates and displays text in text field  
// handles 'delete', 'enter', and 'tab' pressed 
void TextField::processTextFieldInput(sf::Event& textEntered) {
    int charTyped = textEntered.text.unicode;
    // if valid text is entered, text buffer updated and displayed
    if(charTyped >= 32 && charTyped <= 126) {
        // checks character limit
        if(getTextFieldStr().length() < _charLimit) {
            _textBuffer << static_cast<char>(charTyped);
            _text.setString(getTextFieldStr() + "_");
        }
    }
    // if delete pressed, text buffer updated and displayed
    else if(charTyped == 8 && getTextFieldStr().length() > 0) {
        std::string newTextBuffer = getTextFieldStr().substr(0, getTextFieldStr().length()-1);
        _textBuffer.str("");
        _textBuffer << newTextBuffer;
        _text.setString(getTextFieldStr() + "_");
    }
    // if enter or tab pressed, text field loses focus
    else if(charTyped == 9 || charTyped == 10) {
        setTextFieldFocus(false);
        _text.setString(getTextFieldStr());
    }
    // reset position since text buffer was updated
    setTextFieldPosition(getTextFieldPosition());
}