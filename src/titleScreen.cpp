#include <iostream>
#include <stdlib.h>     // exit, EXIT_FAILURE
#include "titleScreen.h"
#include "StoryBeats.h"

/*
    NOTE: 
    
    Font might break depending on where you compile this file from
        - Definitely works if working directory is ../final-project-thevoidgame

    White rectangle background and title text are centered based on the TITLE_WINDOW_SIZE macros from ScreenManager.cpp
        - changing the font size of any text will result in off-center position
*/

/*
    This function renders the title screen using SFML graphics
    Called from main() within game loop

    Input:      p_titleScreenWindow - pointer to RenderWindow object
    Output:     Renders title screen
*/
void renderTitleScreen (sf::RenderWindow* p_titleScreenWindow)
{
    // clear window with black color
    p_titleScreenWindow->clear(sf::Color::Black);

    // define rectangle 3/4 size of screen
    sf::RectangleShape whiteRectangle(sf::Vector2f((3.f*p_titleScreenWindow->getSize().x)/4.f, (3.f*p_titleScreenWindow->getSize().y)/4.f));
    // create text variables
    sf::Text gameNameText1;
    sf::Text gameNameText2;
    sf::Text enterKeyPrompt;
    // create font variables
    sf::Font titleFontImpact;
    sf::Font promptFontArial;

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
    
    // set text to display
    gameNameText1.setString("The");
    gameNameText2.setString("Void");
    enterKeyPrompt.setString("Press [ENTER] key");
    // select fonts
    gameNameText1.setFont(titleFontImpact);
    gameNameText2.setFont(titleFontImpact);
    enterKeyPrompt.setFont(promptFontArial);
    // set font styles
    gameNameText1.setStyle(sf::Text::Bold);
    gameNameText2.setStyle(sf::Text::Bold);
    // set font sizes
    gameNameText1.setCharacterSize(225);
    gameNameText2.setCharacterSize(225);
    enterKeyPrompt.setCharacterSize(50);
    // set color
    whiteRectangle.setFillColor(sf::Color::White);
    gameNameText1.setFillColor(sf::Color::Black);
    gameNameText2.setFillColor(sf::Color::Black);
    enterKeyPrompt.setFillColor(sf::Color::Black);
    //center positions of rectangle and texts
    whiteRectangle.setPosition(p_titleScreenWindow->getSize().x/8.f, p_titleScreenWindow->getSize().y/8.f);
    gameNameText1.setPosition((p_titleScreenWindow->getSize().x - 330.f)/2, ((p_titleScreenWindow->getSize().y - 550)/2.f));
    gameNameText2.setPosition((p_titleScreenWindow->getSize().x - 408.f)/2, ((p_titleScreenWindow->getSize().y - 550)/2.f) + (179.f+25.f));
    enterKeyPrompt.setPosition((p_titleScreenWindow->getSize().x - 423.f)/2, ((p_titleScreenWindow->getSize().y - 550)/2.f) + (179.f+25.f) + (179.f+65.f));
    // draw rectangle and texts
    p_titleScreenWindow->draw(whiteRectangle);
    p_titleScreenWindow->draw(gameNameText1);
    p_titleScreenWindow->draw(gameNameText2);
    p_titleScreenWindow->draw(enterKeyPrompt);

    // end current frame
    p_titleScreenWindow->display();
}

/*
    This function processes the player input from the title screen
    Called from main() within game loop

    Input:  p_titleScreenWindow - pointer to RenderWindow object
            p_titleScreenEvent  - pointer to Event object
    Output: closes window if player closes window :)
            closes window if player presses 'enter' key 
*/
void processTitleScreenInput(sf::RenderWindow* p_titleScreenWindow, sf::Event* p_titleScreenEvent)
{
    // check all window events triggered since last iteration of loop - event loop
    while (p_titleScreenWindow->pollEvent(*p_titleScreenEvent))
    {
        // check type of event
        switch (p_titleScreenEvent->type)
        {
            // "close requested" event: close the window
            case sf::Event::Closed:
                p_titleScreenWindow->close();
                break;
            // key pressed
            case sf::Event::KeyPressed:
                // 'enter' key pressed
                if (p_titleScreenEvent->key.scancode == sf::Keyboard::Scan::Enter)
                {
                    setFlag(0); // sets ENTER_START_SCREEN flag to true;
                    std::cout << "flag 0 set" << std::endl;;
                }
                break;
            // don't process other types of events
            default:
                break;
        }
    }
}