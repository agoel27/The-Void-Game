#include <iostream>
#include <stdlib.h>     // exit, EXIT_FAILURE
#include "../header/startScreen.h"
#include "../header/StoryBeats.h"
#include "../header/TextField.h"
#include "../header/Button.h"

/*
    Implements start screen related functions
        - Renders start screen
        - Handles mouse and keyboard inputs from player

    NOTES:

    Font might break depending on where you compile this file from
        - Definitely works if working directory is ../final-project-thevoidgame
    Game icon on top left is positioned based on the TITLE_WINDOW_SIZE macros from ScreenManager.cpp
        - changing the font size of any text will result in off-center position
*/

// creates font objects
sf::Font impactFont;
sf::Font arialFont;
// creates rectangle objects
sf::RectangleShape iconBackground;
sf::RectangleShape whiteBackground;
// creates text objects
sf::Text iconText1;
sf::Text iconText2;
sf::Text namePromptText;
sf::Text beveragePromptText;
// creates text field objects
TextField nameField(10, 30u, true);
TextField beverageField(10, 30u, false);
// creates button object
Button submitButton("SUBMIT", 30u);
Button maleOption("MALE", 30u);
Button femaleOption("FEMALE", 30u);

/*
    This function instantiates and sets up all the start screen objects using SFML graphics
    Called from main() before game loop

    Input:      startScreenWindow - alias of RenderWindow object
*/
void setupStartScreen (sf::RenderWindow& startScreenWindow) {
    // loads fonts from resources directory
    if (!impactFont.loadFromFile("resources/impact.ttf")) {
        std::cout << "ERROR: could not load the impact font from resources directory\n - Please check the note at the top of <screenName>.cpp\n";
        exit (EXIT_FAILURE);
    }
    if (!arialFont.loadFromFile("resources/arial.ttf")) {
        std::cout << "ERROR: could not load the arial font from resources directory\n - Please check the note at the top of <screenName>.cpp\n";
        exit (EXIT_FAILURE);
    }

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
    maleOption.setButtonTextFont(arialFont);
    femaleOption.setButtonTextFont(arialFont);
    // sets font styles
    iconText1.setStyle(sf::Text::Bold);
    iconText2.setStyle(sf::Text::Bold);
    // sets sizes
    iconBackground.setSize(sf::Vector2f(startScreenWindow.getSize().x/4.f, startScreenWindow.getSize().y/4.f));
    whiteBackground.setSize(sf::Vector2f((7.f*startScreenWindow.getSize().x)/8.f, (9.f*startScreenWindow.getSize().y)/16.f));
    iconText1.setCharacterSize(100);
    iconText2.setCharacterSize(100);
    nameField.setTextFieldSize(sf::Vector2f(400, 35));
    beverageField.setTextFieldSize(sf::Vector2f(400, 35));
    submitButton.setButtonSize(sf::Vector2f(200.f, 70.f));
    maleOption.setButtonSize(sf::Vector2f(150.f, 40.f));
    femaleOption.setButtonSize(sf::Vector2f(150.f, 40.f));
    // sets colors
    iconBackground.setFillColor(sf::Color::White);
    whiteBackground.setFillColor(sf::Color::White);
    iconText1.setFillColor(sf::Color::Black);
    iconText2.setFillColor(sf::Color::Black);
    namePromptText.setFillColor(sf::Color::Black);
    beveragePromptText.setFillColor(sf::Color::Black);
    nameField.setTextColor(sf::Color::Black);
    beverageField.setTextColor(sf::Color::Black);
    nameField.setTextFieldColor(sf::Color(73, 213, 245));
    beverageField.setTextFieldColor(sf::Color(73, 213, 245));
    nameField.setTextFieldOutlineColor(sf::Color::Black);
    beverageField.setTextFieldOutlineColor(sf::Color::Black);
    submitButton.setButtonColor(sf::Color::Transparent);
    submitButton.setButtonTextColor(sf::Color::Black);
    submitButton.setButtonOutlineColor(sf::Color::Black);
    maleOption.setButtonColor(sf::Color::Transparent);
    maleOption.setButtonTextColor(sf::Color::Black);
    maleOption.setButtonOutlineColor(sf::Color::Black);
    femaleOption.setButtonColor(sf::Color::Transparent);
    femaleOption.setButtonTextColor(sf::Color::Black);
    femaleOption.setButtonOutlineColor(sf::Color::Black);
    //sets positions
    iconBackground.setPosition(sf::Vector2f(startScreenWindow.getSize())/16.f);
    whiteBackground.setPosition(startScreenWindow.getSize().x/16.f,  (3.f*startScreenWindow.getSize().y)/8.f);
    iconText1.setOrigin(iconText1.getGlobalBounds().getSize()/2.f + iconText1.getLocalBounds().getPosition());
    iconText1.setPosition(iconBackground.getPosition().x + (iconBackground.getSize().x - iconText1.getGlobalBounds().width)/2.f + iconText1.getGlobalBounds().width/2.f, iconBackground.getPosition().y + (iconBackground.getSize().y - (iconText1.getGlobalBounds().height+iconText2.getGlobalBounds().height))/3.f + iconText1.getGlobalBounds().height/2.f);
    iconText2.setOrigin(iconText2.getGlobalBounds().getSize()/2.f + iconText2.getLocalBounds().getPosition());    
    iconText2.setPosition(iconBackground.getPosition().x + (iconBackground.getSize().x - iconText2.getGlobalBounds().width)/2.f + iconText2.getGlobalBounds().width/2.f, iconText1.getGlobalBounds().top + iconText1.getGlobalBounds().height + (iconBackground.getSize().y - (iconText1.getGlobalBounds().height+iconText2.getGlobalBounds().height))/3.f + iconText2.getGlobalBounds().height/2.f);
    float whiteRectEmptySpaceY = whiteBackground.getSize().y - (namePromptText.getGlobalBounds().height+beveragePromptText.getGlobalBounds().height+submitButton.getButtonSize().y);
    namePromptText.setOrigin(namePromptText.getGlobalBounds().getSize()/2.f + namePromptText.getLocalBounds().getPosition());
    namePromptText.setPosition(startScreenWindow.getSize().x/8.f + namePromptText.getGlobalBounds().width/2.f, whiteBackground.getPosition().y + whiteRectEmptySpaceY/4.f + namePromptText.getGlobalBounds().height/2.f);
    beveragePromptText.setOrigin(beveragePromptText.getGlobalBounds().getSize()/2.f + beveragePromptText.getLocalBounds().getPosition());
    beveragePromptText.setPosition(startScreenWindow.getSize().x/8.f + beveragePromptText.getGlobalBounds().width/2.f, namePromptText.getGlobalBounds().top + namePromptText.getGlobalBounds().height + whiteRectEmptySpaceY/4.f + beveragePromptText.getGlobalBounds().height/2.f);
    nameField.setTextFieldPosition(sf::Vector2f(whiteBackground.getPosition().x + (whiteBackground.getSize().x/2.f), namePromptText.getGlobalBounds().top));
    beverageField.setTextFieldPosition(sf::Vector2f(whiteBackground.getPosition().x + (whiteBackground.getSize().x/2.f), beveragePromptText.getGlobalBounds().top));
    submitButton.setButtonPosition(sf::Vector2f((startScreenWindow.getSize().x - submitButton.getButtonSize().x)/2.f, beveragePromptText.getGlobalBounds().top + beveragePromptText.getGlobalBounds().height + whiteRectEmptySpaceY/4.f));
    maleOption.setButtonPosition(sf::Vector2f((startScreenWindow.getSize().x - maleOption.getButtonSize().x)/8.f, beveragePromptText.getGlobalBounds().top + beveragePromptText.getGlobalBounds().height + whiteRectEmptySpaceY/7.f));
    femaleOption.setButtonPosition(sf::Vector2f((startScreenWindow.getSize().x - maleOption.getButtonSize().x)/3.5f, beveragePromptText.getGlobalBounds().top + beveragePromptText.getGlobalBounds().height + whiteRectEmptySpaceY/7.f));
}

/*
    This function processes the player input from the start screen
    Called from main() within game loop

    Input:  startScreenWindow - alias of RenderWindow object
            startScreenEvent  - alias of Event object
    Output: displays text entered in appropriate text fields
            changes text field focus if mouse clicked
            sets flag if player presses 'submit' key and both text fields are filled
            closes window if player closes window :)
*/
void processStartScreenInput(sf::RenderWindow& startScreenWindow, sf::Event& startScreenEvent) {
    // checks all window events triggered since last iteration of loop - event loop
    while (startScreenWindow.pollEvent(startScreenEvent)) {
        // checks type of event
        switch (startScreenEvent.type) {
            // text entered event
            case sf::Event::TextEntered:
                // handles text entered if focus is on name text field
                if(nameField.getTextFieldFocus()) {
                    nameField.processTextFieldInput(startScreenEvent);
                }
                // handles text entered if focus is on beverage text field
                else if(beverageField.getTextFieldFocus()){
                    beverageField.processTextFieldInput(startScreenEvent);
                }
                break;
            // mouse button pressed event
            case sf::Event::MouseButtonPressed:
                // sets focus to name text field if mouse pressed inside text field bounds
                if(startScreenEvent.mouseButton.x >= nameField.getTextFieldPosition().x && startScreenEvent.mouseButton.x <= nameField.getTextFieldPosition().x + nameField.getTextFieldSize().x && startScreenEvent.mouseButton.y >= nameField.getTextFieldPosition().y && startScreenEvent.mouseButton.y <= nameField.getTextFieldPosition().y + nameField.getTextFieldSize().y) {
                    nameField.setTextFieldFocus(true);
                    beverageField.setTextFieldFocus(false);
                }
                // sets focus to beverage text field if mouse pressed inside text field bounds
                else if(startScreenEvent.mouseButton.x >= beverageField.getTextFieldPosition().x && startScreenEvent.mouseButton.x <= beverageField.getTextFieldPosition().x + beverageField.getTextFieldSize().x && startScreenEvent.mouseButton.y >= beverageField.getTextFieldPosition().y && startScreenEvent.mouseButton.y <= beverageField.getTextFieldPosition().y + beverageField.getTextFieldSize().y) {
                    nameField.setTextFieldFocus(false);
                    beverageField.setTextFieldFocus(true);
                }
                // submit button pressed
                else if(startScreenEvent.mouseButton.x >= submitButton.getButtonPosition().x && startScreenEvent.mouseButton.x <= submitButton.getButtonPosition().x + submitButton.getButtonSize().x && startScreenEvent.mouseButton.y >= submitButton.getButtonPosition().y && startScreenEvent.mouseButton.y <= submitButton.getButtonPosition().y + submitButton.getButtonSize().y) {
                    // changes submit button to red to show that player has not entered name and beverage
                    if(nameField.getTextFieldStr() == "" || beverageField.getTextFieldStr() == "") {
                        if(nameField.getTextFieldStr() == "") {
                            nameField.setTextFieldOutlineColor(sf::Color::Red);
                        }
                        else {
                            nameField.setTextFieldOutlineColor(sf::Color::Black);
                        }
                        if(beverageField.getTextFieldStr() == "") {
                            beverageField.setTextFieldOutlineColor(sf::Color::Red);
                        }
                        else {
                            beverageField.setTextFieldOutlineColor(sf::Color::Black);
                        }
                        submitButton.setButtonOutlineColor(sf::Color::Red);
                        submitButton.setButtonTextColor(sf::Color::Red);
                    }
                    else {
                        clearFlag(1);   // clears ENTER_START_SCREEN flag
                        setFlag(2);     // sets ENTER_INSIDE_HOUSE flag
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
                startScreenWindow.close();
                break;
            // don't process other types of events
            default:
                break;
        }
    }
}

/*
    This function draws all the graphics objects to the start screen
    Called from main() within game loop

    Input:  startScreenWindow - alias of RenderWindow object
    Output: all objects drawn to screen
*/
void drawStartScreen(sf::RenderWindow& startScreenWindow) {

    // clears window with black color
    startScreenWindow.clear(sf::Color::Black);

    // draws to start screen
    startScreenWindow.draw(iconBackground);
    startScreenWindow.draw(whiteBackground);
    startScreenWindow.draw(iconText1);
    startScreenWindow.draw(iconText2);
    startScreenWindow.draw(namePromptText);
    startScreenWindow.draw(beveragePromptText);
    nameField.drawTextField(startScreenWindow);
    beverageField.drawTextField(startScreenWindow);
    submitButton.drawButton(startScreenWindow);
    maleOption.drawButton(startScreenWindow);
    femaleOption.drawButton(startScreenWindow);

    // ends current frame
    startScreenWindow.display();
}