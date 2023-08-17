#include <iostream>
#include <stdlib.h>     // exit, EXIT_FAILURE
#include "startScreen.h"
#include "storyBeats.h"
#include "TextField.h"

/*
    NOTE: 
    
    Font might break depending on where you compile this file from
        - Definitely works if working directory is ../final-project-thevoidgame

    Game icon on top left is positioned based on the TITLE_WINDOW_SIZE macros from ScreenManager.cpp
        - changing the font size of any text will result in off-center position
*/

// create Text Field objects
TextField nameField(10, true);
TextField beverageField(10, false);

/*
    This function renders the start screen using SFML graphics
    Called from main() within game loop

    Input:      p_startScreenWindow - pointer to RenderWindow object
    Output:     Renders start screen
*/
void renderStartScreen (sf::RenderWindow* p_startScreenWindow)
{
    // clear window with black color
    p_startScreenWindow->clear(sf::Color::Black);

    // define rectangle 1/4 size of screen
    sf::RectangleShape iconBackground(sf::Vector2f(p_startScreenWindow->getSize().x/4.f, p_startScreenWindow->getSize().y/4.f));
    sf::RectangleShape whiteRectangle(sf::Vector2f((7.f*p_startScreenWindow->getSize().x)/8.f, (9.f*p_startScreenWindow->getSize().y)/16.f));
    // create text variables
    sf::Text gameNameText1;
    sf::Text gameNameText2;
    sf::Text namePromptText;
    sf::Text beveragePromptText;
    // create font variables
    sf::Font titleFontImpact;
    sf::Font textFieldFontArial;

    // load fonts from resources directory
    if (!titleFontImpact.loadFromFile("resources/impact.ttf"))
    {
        std::cout << "ERROR: could not load the impact font from resources directory\n - Please check the note at the top of <screenName>.cpp\n";
        exit (EXIT_FAILURE);
    }
    if (!textFieldFontArial.loadFromFile("resources/arial.ttf"))
    {
        std::cout << "ERROR: could not load the arial font from resources directory\n - Please check the note at the top of <screenName>.cpp\n";
        exit (EXIT_FAILURE);
    }

    // set text to display
    gameNameText1.setString("The");
    gameNameText2.setString("Void");
    namePromptText.setString("Enter Name: ");
    beveragePromptText.setString("Enter favorite morning beverage: ");
    // select fonts
    gameNameText1.setFont(titleFontImpact);
    gameNameText2.setFont(titleFontImpact);
    namePromptText.setFont(textFieldFontArial);
    beveragePromptText.setFont(textFieldFontArial);
    nameField.setTextFieldFont(&textFieldFontArial);
    beverageField.setTextFieldFont(&textFieldFontArial);
    // set font styles
    gameNameText1.setStyle(sf::Text::Bold);
    gameNameText2.setStyle(sf::Text::Bold);
    // set font sizes
    gameNameText1.setCharacterSize(100);
    gameNameText2.setCharacterSize(100);
    namePromptText.setCharacterSize(30);
    beveragePromptText.setCharacterSize(30);
    nameField.setTextFieldCharSize(30);
    beverageField.setTextFieldCharSize(30);
    // set color
    iconBackground.setFillColor(sf::Color::White);
    whiteRectangle.setFillColor(sf::Color::White);
    gameNameText1.setFillColor(sf::Color::Black);
    gameNameText2.setFillColor(sf::Color::Black);
    namePromptText.setFillColor(sf::Color::Black);
    beveragePromptText.setFillColor(sf::Color::Black);
    nameField.setTextFieldColor(sf::Color::Black);
    beverageField.setTextFieldColor(sf::Color::Black);
    //define positions
    iconBackground.setPosition(p_startScreenWindow->getSize().x/16.f, p_startScreenWindow->getSize().y/16.f);
    whiteRectangle.setPosition(p_startScreenWindow->getSize().x/16.f, iconBackground.getPosition().y + iconBackground.getSize().y + p_startScreenWindow->getSize().y/16.f);
    gameNameText1.setPosition(iconBackground.getPosition().x + (iconBackground.getSize().x-148.f)/2.f, iconBackground.getPosition().y + (iconBackground.getSize().y-158.f)/3.f - 20.f);
    gameNameText2.setPosition(iconBackground.getPosition().x + (iconBackground.getSize().x-183.f)/2.f, gameNameText1.getPosition().y + 79.f + (iconBackground.getSize().y-158.f)/3.f);
    namePromptText.setPosition(whiteRectangle.getPosition().x + p_startScreenWindow->getSize().x/16.f, whiteRectangle.getPosition().y + (whiteRectangle.getSize().y-100.f)/3.f);
    beveragePromptText.setPosition(whiteRectangle.getPosition().x + p_startScreenWindow->getSize().x/16.f, namePromptText.getPosition().y + 50.f + (whiteRectangle.getSize().y-100.f)/3.f);
    nameField.setTextFieldPosition(whiteRectangle.getPosition().x + (whiteRectangle.getSize().x/2.f), namePromptText.getPosition().y);
    beverageField.setTextFieldPosition(whiteRectangle.getPosition().x + (whiteRectangle.getSize().x/2.f), beveragePromptText.getPosition().y);

    // draw to start screen
    p_startScreenWindow->draw(iconBackground);
    p_startScreenWindow->draw(whiteRectangle);
    p_startScreenWindow->draw(gameNameText1);
    p_startScreenWindow->draw(gameNameText2);
    p_startScreenWindow->draw(namePromptText);
    p_startScreenWindow->draw(beveragePromptText);
    nameField.drawTextField(p_startScreenWindow);
    beverageField.drawTextField(p_startScreenWindow);
    
    // end current frame
    p_startScreenWindow->display();
}

/*
    This function processes the player input from the start screen
    Called from main() within game loop

    Input:  p_startScreenWindow - pointer to RenderWindow object
            p_startScreenEvent  - pointer to Event object
    Output: closes window if player closes window :)
            handles text entered by player 
*/
void processStartScreenInput(sf::RenderWindow* p_startScreenWindow, sf::Event* p_startScreenEvent)
{
    // check all window events triggered since last iteration of loop - event loop
    while (p_startScreenWindow->pollEvent(*p_startScreenEvent))
    {
        // check type of event
        switch (p_startScreenEvent->type)
        {
            // "close requested" event: close the window
            case sf::Event::Closed:
                p_startScreenWindow->close();
                break;
            // text entered
            case sf::Event::TextEntered:
                // handles text entered if focus is on name text field
                if(nameField.hasTextFieldFocus()) {
                    nameField.typedInTextField(p_startScreenEvent);
                }
                // handles text entered if focus is on beverage text field
                else if(beverageField.hasTextFieldFocus()){
                    beverageField.typedInTextField(p_startScreenEvent);
                }
                break;
            // mouse button pressed
            case sf::Event::MouseButtonPressed:
                // sets focus to name text field if mouse pressed inside text field bounds
                if(p_startScreenEvent->mouseButton.x >= nameField.getTextFieldXPosition()-3 && p_startScreenEvent->mouseButton.x <= nameField.getTextFieldXPosition()-3 + nameField.getTextFieldCharSize()*nameField.getTextFieldCharLimit() && p_startScreenEvent->mouseButton.y >= nameField.getTextFieldYPosition()+7 && p_startScreenEvent->mouseButton.y <= nameField.getTextFieldYPosition()+7 + nameField.getTextFieldCharSize()) {
                    nameField.setTextFieldFocus(true);
                    beverageField.setTextFieldFocus(false);
                }
                // sets focus to beverage text field if mouse pressed inside text field bounds
                else if(p_startScreenEvent->mouseButton.x >= beverageField.getTextFieldXPosition()-3 && p_startScreenEvent->mouseButton.x <= beverageField.getTextFieldXPosition()-3 + beverageField.getTextFieldCharSize()*beverageField.getTextFieldCharLimit() && p_startScreenEvent->mouseButton.y >= beverageField.getTextFieldYPosition()+7 && p_startScreenEvent->mouseButton.y <= beverageField.getTextFieldYPosition()+7 + beverageField.getTextFieldCharSize()) {
                    nameField.setTextFieldFocus(false);
                    beverageField.setTextFieldFocus(true);
                }
                // removes focus from all text fields if mouse pressed outside text field bounds
                else {
                    nameField.setTextFieldFocus(false);
                    beverageField.setTextFieldFocus(false);
                }
                break;
            // don't process other types of events
            default:
                break;
        }
    }
}