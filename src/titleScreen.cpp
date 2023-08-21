#include <iostream>
#include <stdlib.h>     // exit, EXIT_FAILURE
#include "../header/titleScreen.h"
#include "../header/StoryBeats.h"

/*
    Implements title screen related functions
        - Renders title screen
        - Handles keyboard inputs from player

    NOTES: 
    
    Font might break depending on where you compile this file from
        - Definitely works if working directory is ../final-project-thevoidgame
    White rectangle background and title text are centered based on the TITLE_WINDOW_SIZE macros from ScreenManager.cpp
        - can play around with font/character size to see what looks best
*/

// creates font objects
sf::Font titleFontImpact;
sf::Font promptFontArial;
// creates rectangle object
sf::RectangleShape whiteRectangle;
// creates text objects
sf::Text gameNameText1;
sf::Text gameNameText2;
sf::Text enterKeyPrompt;

/*
    This function instantiates and sets up all the title screen objects using SFML graphics
    Called from main() before game loop

    Input:  titleScreenWindow - alias of RenderWindow object
*/
void setupTitleScreen (sf::RenderWindow& titleScreenWindow)
{
    // load fonts from resources directory
    if (!titleFontImpact.loadFromFile("resources/impact.ttf"))
    {
        std::cout << "ERROR: could not load the impact font from resources directory\n - Please check the note at the top of <screenName>.cpp\n";
        exit (EXIT_FAILURE);
    }
    if (!promptFontArial.loadFromFile("resources/arial.ttf"))
    {
        std::cout << "ERROR: could not load the arial font from resources directory\n - Please check the note at the top of title-screen.cpp\n";
        exit (EXIT_FAILURE);
    }
    
    // sets texts to display
    gameNameText1.setString("The");
    gameNameText2.setString("Void");
    enterKeyPrompt.setString("Press [ENTER] key");
    // selects fonts
    gameNameText1.setFont(titleFontImpact);
    gameNameText2.setFont(titleFontImpact);
    enterKeyPrompt.setFont(promptFontArial);
    // sets font styles
    gameNameText1.setStyle(sf::Text::Bold);
    gameNameText2.setStyle(sf::Text::Bold);
    // sets sizes
    whiteRectangle.setSize(sf::Vector2f((3.f*titleScreenWindow.getSize().x)/4.f, (3.f*titleScreenWindow.getSize().y)/4.f));
    gameNameText1.setCharacterSize(225);
    gameNameText2.setCharacterSize(225);
    enterKeyPrompt.setCharacterSize(50);
    // sets colors
    whiteRectangle.setFillColor(sf::Color::White);
    gameNameText1.setFillColor(sf::Color::Black);
    gameNameText2.setFillColor(sf::Color::Black);
    enterKeyPrompt.setFillColor(sf::Color::Black);
    //sets and centers positions
    whiteRectangle.setPosition(titleScreenWindow.getSize().x/8.f, titleScreenWindow.getSize().y/8.f);
    gameNameText1.setPosition((titleScreenWindow.getSize().x - 330.f)/2, ((titleScreenWindow.getSize().y - 550)/2.f));
    gameNameText2.setPosition((titleScreenWindow.getSize().x - 408.f)/2, ((titleScreenWindow.getSize().y - 550)/2.f) + (179.f+25.f));
    enterKeyPrompt.setPosition((titleScreenWindow.getSize().x - 423.f)/2, ((titleScreenWindow.getSize().y - 550)/2.f) + (179.f+25.f) + (179.f+65.f));
}

/*
    This function processes the player input from the title screen
    Called from main() within game loop

    Input:  titleScreenWindow - alias of RenderWindow object
            titleScreenEvent  - alias of Event object
    Output: sets flag if player presses 'enter' key
            closes window if player closes window :)
*/
void processTitleScreenInput(sf::RenderWindow& titleScreenWindow, sf::Event& titleScreenEvent)
{
    // checks all window events triggered since last iteration of loop - event loop
    while (titleScreenWindow.pollEvent(titleScreenEvent))
    {
        // checks type of event
        switch (titleScreenEvent.type)
        {
            // key pressed
            case sf::Event::KeyPressed:
                // 'enter' key pressed
                if (titleScreenEvent.key.scancode == sf::Keyboard::Scan::Enter)
                {
                    clearFlag(0);   // clears ENTER_TITLE_SCREEN flag
                    setFlag(1);     // sets ENTER_START_SCREEN flag
                }
                break;
            // "close requested" event: close the window
            case sf::Event::Closed:
                titleScreenWindow.close();
                break;
            // don't process other types of events
            default:
                break;
        }
    }
}

/*
    This function draws all the graphics objects to the title screen
    Called from main() within game loop

    Input:  titleScreenWindow - alias of RenderWindow object
    Output: all objects drawn to screen
*/
void drawTitleScreen(sf::RenderWindow& titleScreenWindow) {
    // clears window with black color
    titleScreenWindow.clear(sf::Color::Black);

    // draws rectangle and title texts
    titleScreenWindow.draw(whiteRectangle);
    titleScreenWindow.draw(gameNameText1);
    titleScreenWindow.draw(gameNameText2);
    titleScreenWindow.draw(enterKeyPrompt);

    // ends current frame
    titleScreenWindow.display();
}