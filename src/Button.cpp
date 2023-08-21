#include "../header/Button.h"

/*
    Implements Button class related functions

    Note:
    Must set font and button size else button and button text wont show

    Credits:
    https://www.youtube.com/watch?v=T31MoLJws4U&ab_channel=TermSpar
    https://learnsfml.com/how-to-center-text/
*/

// Button contructor - parameters are button text, button text font, and button text size
// All parameters need to be set to properly center button text within button rectangle
Button::Button(std::string text, unsigned int buttonTextSize) {
    _buttonText.setString(text);
    _buttonText.setCharacterSize(buttonTextSize);
}

void Button::setButtonTextFont(sf::Font& buttonTextFont) {
    _buttonText.setFont(buttonTextFont);
}

// sets button rectangle's size
void Button::setButtonSize(sf::Vector2f buttonSize) {
    _buttonRect.setSize(buttonSize);
}

// sets button rectangle's color
void Button::setButtonColor(sf::Color buttonColor) {
    _buttonRect.setFillColor(buttonColor);
}

// sets button text's color
void Button::setButtonTextColor(sf::Color buttonTextColor) {
    _buttonText.setFillColor(buttonTextColor);
}

void Button::setButtonOutlineColor(sf::Color buttonOutlineColor) {
    _buttonRect.setOutlineThickness(-2.f);
    _buttonRect.setOutlineColor(buttonOutlineColor);
}

// sets button rectangle's position
void Button::setButtonPosition(sf::Vector2f buttonPosition) {
    _buttonRect.setPosition(sf::Vector2f(sf::Vector2u(buttonPosition)));
    _buttonText.setOrigin(sf::Vector2f(sf::Vector2u(_buttonText.getGlobalBounds().getSize()/2.f + _buttonText.getLocalBounds().getPosition())));
    _buttonText.setPosition(sf::Vector2f(sf::Vector2u(buttonPosition + _buttonRect.getSize()/2.f)));
}

// returns button's size
sf::Vector2f Button::getButtonSize() {
    return _buttonRect.getSize();
}

// returns button's position
sf::Vector2f Button::getButtonPosition() {
    return _buttonRect.getPosition();
}

// draws button on window
void Button::drawButton(sf::RenderWindow& gameWindow) {
    gameWindow.draw(_buttonRect);
    gameWindow.draw(_buttonText);
}