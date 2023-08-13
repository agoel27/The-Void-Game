#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>     // exit, EXIT_FAILURE

/*
    This script renders the title screen using SFML graphics

    Font might break depending on where you compile this file from
        - Definitely works if working directory is ../final-project-thevoidgame

    White rectangle background and title text are centered based on the TITLE_WINDOW_SIZE global const variables
        - changing the font size of any title text will result in off-center position
*/

// render title screen from RenderWindow object
void renderTitleScreen(sf::RenderWindow*);
// process player input from title screen
void processTitleScreenInput(sf::RenderWindow*, sf::Event*);

// set title window size
const int TITLE_WINDOW_SIZE_X = 800;
const int TITLE_WINDOW_SIZE_Y = 800;

int main() 
{
    // create window - can not be resized
    sf::RenderWindow titleScreenWindow(sf::VideoMode(TITLE_WINDOW_SIZE_X, TITLE_WINDOW_SIZE_Y), "Title Screen", sf::Style::Close);

    // create user event for title screen
    sf::Event titleScreenEvent;

    // run program while window is open - game loop
    while (titleScreenWindow.isOpen())
    {
        
        // call renderTitleScreen() func - renders title screen
        renderTitleScreen(&titleScreenWindow);

        // call getTitleScreenInput() func - processes user events 
        processTitleScreenInput(&titleScreenWindow, &titleScreenEvent);
    }

    return 0;
}

/*
    This function renders the title screen using SFML graphics
    Called from main() within game loop

    Input:      p_titleScreenWindow - pointer to RenderWindow object
    Output:     Renders title screen
*/
void renderTitleScreen (sf::RenderWindow *p_titleScreenWindow) {
    // clear window with black color
    p_titleScreenWindow->clear(sf::Color::Black);

    // define rectangle 3/4 size of screen
    sf::RectangleShape whiteRectangle(sf::Vector2f((3.f*TITLE_WINDOW_SIZE_X)/4.f, (3.f*TITLE_WINDOW_SIZE_Y)/4.f));
    // set rectangle color to white
    whiteRectangle.setFillColor(sf::Color::White);
    // center white rectangle on screen
    whiteRectangle.setPosition(TITLE_WINDOW_SIZE_X/8.f, TITLE_WINDOW_SIZE_Y/8.f);
    // draw white rectangle on screen
    p_titleScreenWindow->draw(whiteRectangle);

    // create font variables
    sf::Font titleFontImpact;
    sf::Font titleFontArial;
    // load fonts from resources directory
    if (!titleFontImpact.loadFromFile("resources/impact.ttf"))
    {
        std::cout << "ERROR: could not load the impact font from resources directory\n - Please check the note at the top of title-screen.cpp\n";
        exit (EXIT_FAILURE);
    }
    if (!titleFontArial.loadFromFile("resources/arial.ttf"))
    {
        std::cout << "ERROR: could not load the arial font from resources directory\n - Please check the note at the top of title-screen.cpp\n";
        exit (EXIT_FAILURE);
    }
    
    // create text variables
    sf::Text titleText1;
    sf::Text titleText2;
    sf::Text titleText3;
    // select fonts
    titleText1.setFont(titleFontImpact);
    titleText2.setFont(titleFontImpact);
    titleText3.setFont(titleFontArial);
    // set text to display
    titleText1.setString("The");
    titleText2.setString("Void");
    titleText3.setString("Press [ENTER] key");
    // set font sizes
    titleText1.setCharacterSize(225);
    titleText2.setCharacterSize(225);
    titleText3.setCharacterSize(50);
    // set color
    titleText1.setFillColor(sf::Color::Black);
    titleText2.setFillColor(sf::Color::Black);
    titleText3.setFillColor(sf::Color::Black);
    // set text styles
    titleText1.setStyle(sf::Text::Bold);
    titleText2.setStyle(sf::Text::Bold);
    //center positions of texts
    titleText1.setPosition((TITLE_WINDOW_SIZE_X - 330.f)/2, ((TITLE_WINDOW_SIZE_Y - 550)/2.f));
    titleText2.setPosition((TITLE_WINDOW_SIZE_X - 408.f)/2, ((TITLE_WINDOW_SIZE_Y - 550)/2.f) + (179.f+25.f));
    titleText3.setPosition((TITLE_WINDOW_SIZE_X - 423.f)/2, ((TITLE_WINDOW_SIZE_Y - 550)/2.f) + (179.f+25.f) + (179.f+65.f));
    // draw texts
    p_titleScreenWindow->draw(titleText1);
    p_titleScreenWindow->draw(titleText2);
    p_titleScreenWindow->draw(titleText3);

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
                    p_titleScreenWindow->close();
                }
                break;
            // don't process other types of events
            default:
                break;
        }
    }
}