#include <iostream>
#include <stdlib.h>     // exit, EXIT_FAILURE
#include "startScreen.h"
#include "StoryBeats.h"

/*
    NOTE: 
    
    Font might break depending on where you compile this file from
        - Definitely works if working directory is ../final-project-thevoidgame

    Game name icon on top left is positioned based on the TITLE_WINDOW_SIZE macros from ScreenManager.cpp
        - changing the font size of any text will result in off-center position
*/

void renderStartScreen (sf::RenderWindow* p_startScreenWindow)
{
    // clear window with black color
    p_startScreenWindow->clear(sf::Color::Black);

    // define rectangle 1/4 size of screen
    sf::RectangleShape whiteRectangle(sf::Vector2f((p_startScreenWindow->getSize().x)/4.f, (p_startScreenWindow->getSize().y)/4.f));
    // create text variables
    sf::Text gameNameText1;
    sf::Text gameNameText2;
    // create font variables
    sf::Font titleFontImpact;

    // load fonts from resources directory
    if (!titleFontImpact.loadFromFile("resources/impact.ttf"))
    {
        std::cout << "ERROR: could not load the impact font from resources directory\n - Please check the note at the top of <screenName>.cpp\n";
        exit (EXIT_FAILURE);
    }

    // set text to display
    gameNameText1.setString("The");
    gameNameText2.setString("Void");
    // select fonts
    gameNameText1.setFont(titleFontImpact);
    gameNameText2.setFont(titleFontImpact);
    // set font styles
    gameNameText1.setStyle(sf::Text::Bold);
    gameNameText2.setStyle(sf::Text::Bold);
    // set font sizes
    gameNameText1.setCharacterSize(100);
    gameNameText2.setCharacterSize(100);
    // set color
    whiteRectangle.setFillColor(sf::Color::White);
    gameNameText1.setFillColor(sf::Color::Black);
    gameNameText2.setFillColor(sf::Color::Black);
    //define positions of rectangle and texts
    whiteRectangle.setPosition(p_startScreenWindow->getSize().x/16.f, p_startScreenWindow->getSize().y/16.f);
    gameNameText1.setPosition(whiteRectangle.getPosition().x + (whiteRectangle.getSize().x-148.f)/2.f, whiteRectangle.getPosition().y + (whiteRectangle.getSize().y-158.f)/3.f - 20.f);
    gameNameText2.setPosition(whiteRectangle.getPosition().x + (whiteRectangle.getSize().x-183.f)/2.f, gameNameText1.getPosition().y + 79.f + (whiteRectangle.getSize().y-158.f)/3.f);
    // draw rectangle and texts
    p_startScreenWindow->draw(whiteRectangle);
    p_startScreenWindow->draw(gameNameText1);
    p_startScreenWindow->draw(gameNameText2);
    
    // end current frame
    p_startScreenWindow->display();
}

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
            // don't process other types of events
            default:
                break;
        }
    }
}