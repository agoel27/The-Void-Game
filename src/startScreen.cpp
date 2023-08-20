#include <iostream>
#include <stdlib.h>     // exit, EXIT_FAILURE
#include "startScreen.h"
#include "storyBeats.h"
#include "TextField.h"
#include "Button.h"

/*
    Implements start screen related functions
        - Renders start screen
        - Handles mouse and keyboard player inputs from start screen

    NOTES:

    Font might break depending on where you compile this file from
        - Definitely works if working directory is ../final-project-thevoidgame
    Game icon on top left is positioned based on the TITLE_WINDOW_SIZE macros from ScreenManager.cpp
        - changing the font size of any text will result in off-center position
*/

// creates text field objects
TextField nameField(10, 30u, true);
TextField beverageField(10, 30u, false);
// creates button object
Button submitButton("SUBMIT", 30u);

/*
    This function renders the start screen using SFML graphics
    Called from main() within game loop

    Input:      p_startScreenWindow - pointer to RenderWindow object
    Output:     void
*/
void renderStartScreen (sf::RenderWindow* p_startScreenWindow, sf::Event* p_startScreenEvent)
{
    // // clears window with black color
    // p_startScreenWindow->clear(sf::Color::Black);

    // creates font objects
    sf::Font impactFont;
    sf::Font arialFont;
    // loads fonts from resources directory
    if (!impactFont.loadFromFile("resources/impact.ttf"))
    {
        std::cout << "ERROR: could not load the impact font from resources directory\n - Please check the note at the top of <screenName>.cpp\n";
        exit (EXIT_FAILURE);
    }
    if (!arialFont.loadFromFile("resources/arial.ttf"))
    {
        std::cout << "ERROR: could not load the arial font from resources directory\n - Please check the note at the top of <screenName>.cpp\n";
        exit (EXIT_FAILURE);
    }

    // creates rectangle objects
    sf::RectangleShape iconBackground(sf::Vector2f(p_startScreenWindow->getSize().x/4.f, p_startScreenWindow->getSize().y/4.f));
    sf::RectangleShape whiteRectangle(sf::Vector2f((7.f*p_startScreenWindow->getSize().x)/8.f, (9.f*p_startScreenWindow->getSize().y)/16.f));
    // creates text objects
    sf::Text iconText1;
    sf::Text iconText2;
    sf::Text namePromptText;
    sf::Text beveragePromptText;

    // sets text to display
    iconText1.setString("The");
    iconText2.setString("Void");
    namePromptText.setString("Enter Name: ");
    beveragePromptText.setString("Enter favorite morning beverage: ");
    // selects fonts
    iconText1.setFont(impactFont);
    iconText2.setFont(impactFont);
    namePromptText.setFont(arialFont);
    beveragePromptText.setFont(arialFont);
    nameField.setTextFont(arialFont);
    beverageField.setTextFont(arialFont);
    submitButton.setButtonTextFont(arialFont);
    // sets font styles
    iconText1.setStyle(sf::Text::Bold);
    iconText2.setStyle(sf::Text::Bold);
    // sets sizes
    iconText1.setCharacterSize(100);
    iconText2.setCharacterSize(100);
    nameField.setTextFieldSize(sf::Vector2f(400, 35));
    beverageField.setTextFieldSize(sf::Vector2f(400, 35));
    submitButton.setButtonSize(sf::Vector2f(200.f, 70.f));
    // sets colors
    iconBackground.setFillColor(sf::Color::White);
    whiteRectangle.setFillColor(sf::Color::White);
    iconText1.setFillColor(sf::Color::Black);
    iconText2.setFillColor(sf::Color::Black);
    namePromptText.setFillColor(sf::Color::Black);
    beveragePromptText.setFillColor(sf::Color::Black);
    nameField.setTextColor(sf::Color::Black);
    beverageField.setTextColor(sf::Color::Black);
    nameField.setTextFieldColor(sf::Color(73, 213, 245));
    beverageField.setTextFieldColor(sf::Color(73, 213, 245));
    submitButton.setButtonColor(sf::Color::Transparent);
    submitButton.setButtonTextColor(sf::Color::Black);
    submitButton.setButtonOutlineColor(sf::Color::Black);
    //defines positions
    iconBackground.setPosition(sf::Vector2f(p_startScreenWindow->getSize())/16.f);
    whiteRectangle.setPosition(p_startScreenWindow->getSize().x/16.f,  (3.f*p_startScreenWindow->getSize().y)/8.f);
    iconText1.setOrigin(iconText1.getGlobalBounds().getSize()/2.f + iconText1.getLocalBounds().getPosition());
    iconText1.setPosition(iconBackground.getPosition().x + (iconBackground.getSize().x - iconText1.getGlobalBounds().width)/2.f + iconText1.getGlobalBounds().width/2.f, iconBackground.getPosition().y + (iconBackground.getSize().y - (iconText1.getGlobalBounds().height+iconText2.getGlobalBounds().height))/3.f + iconText1.getGlobalBounds().height/2.f);
    iconText2.setOrigin(iconText2.getGlobalBounds().getSize()/2.f + iconText2.getLocalBounds().getPosition());    
    iconText2.setPosition(iconBackground.getPosition().x + (iconBackground.getSize().x - iconText2.getGlobalBounds().width)/2.f + iconText2.getGlobalBounds().width/2.f, iconText1.getGlobalBounds().top + iconText1.getGlobalBounds().height + (iconBackground.getSize().y - (iconText1.getGlobalBounds().height+iconText2.getGlobalBounds().height))/3.f + iconText2.getGlobalBounds().height/2.f);
    float whiteRectEmptySpaceY = whiteRectangle.getSize().y - (namePromptText.getGlobalBounds().height+beveragePromptText.getGlobalBounds().height+submitButton.getButtonSize().y);
    namePromptText.setOrigin(namePromptText.getGlobalBounds().getSize()/2.f + namePromptText.getLocalBounds().getPosition());
    namePromptText.setPosition(p_startScreenWindow->getSize().x/8.f + namePromptText.getGlobalBounds().width/2.f, whiteRectangle.getPosition().y + whiteRectEmptySpaceY/4.f + namePromptText.getGlobalBounds().height/2.f);
    beveragePromptText.setOrigin(beveragePromptText.getGlobalBounds().getSize()/2.f + beveragePromptText.getLocalBounds().getPosition());
    beveragePromptText.setPosition(p_startScreenWindow->getSize().x/8.f + beveragePromptText.getGlobalBounds().width/2.f, namePromptText.getGlobalBounds().top + namePromptText.getGlobalBounds().height + whiteRectEmptySpaceY/4.f + beveragePromptText.getGlobalBounds().height/2.f);
    nameField.setTextFieldPosition(sf::Vector2f(whiteRectangle.getPosition().x + (whiteRectangle.getSize().x/2.f), namePromptText.getGlobalBounds().top));
    beverageField.setTextFieldPosition(sf::Vector2f(whiteRectangle.getPosition().x + (whiteRectangle.getSize().x/2.f), beveragePromptText.getGlobalBounds().top));
    submitButton.setButtonPosition(sf::Vector2f((p_startScreenWindow->getSize().x - submitButton.getButtonSize().x)/2.f, beveragePromptText.getGlobalBounds().top + beveragePromptText.getGlobalBounds().height + whiteRectEmptySpaceY/4.f));
    
    // calls getStartScreenInput() func - processes user events
    processStartScreenInput(p_startScreenWindow, p_startScreenEvent);

    // draws to start screen
    p_startScreenWindow->draw(iconBackground);
    p_startScreenWindow->draw(whiteRectangle);
    p_startScreenWindow->draw(iconText1);
    p_startScreenWindow->draw(iconText2);
    p_startScreenWindow->draw(namePromptText);
    p_startScreenWindow->draw(beveragePromptText);
    nameField.drawTextField(*p_startScreenWindow);
    beverageField.drawTextField(*p_startScreenWindow);
    submitButton.drawButton(*p_startScreenWindow);

    // ends current frame
    p_startScreenWindow->display();
}

/*
    This function processes the player input from the start screen
    Called from main() within game loop

    Input:      p_startScreenWindow - pointer to RenderWindow object
                p_startScreenEvent  - pointer to Event object
    Output:     void
*/
void processStartScreenInput(sf::RenderWindow* p_startScreenWindow, sf::Event* p_startScreenEvent)
{
    // checks all window events triggered since last iteration of loop - event loop
    while (p_startScreenWindow->pollEvent(*p_startScreenEvent))
    {
        // checks type of event
        switch (p_startScreenEvent->type)
        {
            // text entered event
            case sf::Event::TextEntered:
                // handles text entered if focus is on name text field
                if(nameField.getTextFieldFocus()) {
                    nameField.processTextFieldInput(*p_startScreenEvent);
                }
                // handles text entered if focus is on beverage text field
                else if(beverageField.getTextFieldFocus()){
                    beverageField.processTextFieldInput(*p_startScreenEvent);
                }
                break;
            // mouse button pressed event
            case sf::Event::MouseButtonPressed:
                // sets focus to name text field if mouse pressed inside text field bounds
                if(p_startScreenEvent->mouseButton.x >= nameField.getTextFieldPosition().x && p_startScreenEvent->mouseButton.x <= nameField.getTextFieldPosition().x + nameField.getTextFieldSize().x && p_startScreenEvent->mouseButton.y >= nameField.getTextFieldPosition().y && p_startScreenEvent->mouseButton.y <= nameField.getTextFieldPosition().y + nameField.getTextFieldSize().y) {
                    nameField.setTextFieldFocus(true);
                    beverageField.setTextFieldFocus(false);
                }
                // sets focus to beverage text field if mouse pressed inside text field bounds
                else if(p_startScreenEvent->mouseButton.x >= beverageField.getTextFieldPosition().x && p_startScreenEvent->mouseButton.x <= beverageField.getTextFieldPosition().x + beverageField.getTextFieldSize().x && p_startScreenEvent->mouseButton.y >= beverageField.getTextFieldPosition().y && p_startScreenEvent->mouseButton.y <= beverageField.getTextFieldPosition().y + beverageField.getTextFieldSize().y) {
                    nameField.setTextFieldFocus(false);
                    beverageField.setTextFieldFocus(true);
                }
                else if(p_startScreenEvent->mouseButton.x >= submitButton.getButtonPosition().x && p_startScreenEvent->mouseButton.x <= submitButton.getButtonPosition().x + submitButton.getButtonSize().x && p_startScreenEvent->mouseButton.y >= submitButton.getButtonPosition().y && p_startScreenEvent->mouseButton.y <= submitButton.getButtonPosition().y + submitButton.getButtonSize().y) {
                    if(nameField.getTextFieldStr() == "" || beverageField.getTextFieldStr() == "") {
                        submitButton.setButtonOutlineColor(sf::Color::Red);
                        submitButton.setButtonTextColor(sf::Color::Red);
                    }
                    else {
                        //submitButton.setButtonColor(sf::Color::Red);
                        setFlag(1);
                        std::cout << "flag 1 set" << std::endl;
                    }
                    // removes focus from all text fields
                    nameField.setTextFieldFocus(false);
                    beverageField.setTextFieldFocus(false);
                }
                // removes focus from all text fields if mouse pressed outside any text field bounds
                else {
                    nameField.setTextFieldFocus(false);
                    beverageField.setTextFieldFocus(false);
                }
                break;
            // "close requested" event: close the window
            case sf::Event::Closed:
                p_startScreenWindow->close();
                break;
            // don't process other types of events
            default:
                break;
        }
    }
}