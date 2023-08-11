#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */

/*
    This script renders the title screen using SFML graphics

    Font might break depending on where you compile this file from
        - Definitely works if working directory is ../final-project-thevoidgame

    White rectangle background and title text are centered based on the TITLE_WINDOW_SIZE global const variables
        - changing the font size of any title text will result in off-center position
*/

// func that renders the title screen from a RenderWindow object
void renderTitleScreen(sf::RenderWindow*);

// global const variables that set title window size
const int TITLE_WINDOW_SIZE_X = 800;
const int TITLE_WINDOW_SIZE_Y = 600;

int main() {
    // create a window that can not be resized
    sf::RenderWindow titleScreenWindow(sf::VideoMode(TITLE_WINDOW_SIZE_X, TITLE_WINDOW_SIZE_Y), "Title Screen", sf::Style::Close);

    // run the program as long as the window is open
    while (titleScreenWindow.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event titleScreenEvent;
        while (titleScreenWindow.pollEvent(titleScreenEvent))
        {
            // "close requested" event: we close the window
            if (titleScreenEvent.type == sf::Event::Closed)
                titleScreenWindow.close();
        }

        renderTitleScreen(&titleScreenWindow);

    }

    return 0;
}


void renderTitleScreen (sf::RenderWindow *p_titleScreenWindow) {
    // clear the window with black color
    p_titleScreenWindow->clear(sf::Color::Black);

    // define a rectangle 3/4 size of the screen
    sf::RectangleShape whiteRectangle(sf::Vector2f((3.f*TITLE_WINDOW_SIZE_X)/4.f, (3.f*TITLE_WINDOW_SIZE_Y)/4.f));
    // set rectangle color to white
    whiteRectangle.setFillColor(sf::Color::White);
    // center white rectangle on screen
    whiteRectangle.setPosition(TITLE_WINDOW_SIZE_X/8.f, TITLE_WINDOW_SIZE_Y/8.f);
    // draw white rectangle on screen
    p_titleScreenWindow->draw(whiteRectangle);

    // create the font variables
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
    
    // create the text variables
    sf::Text titleText1;
    sf::Text titleText2;
    sf::Text titleText3;
    // select the fonts
    titleText1.setFont(titleFontImpact);
    titleText2.setFont(titleFontImpact);
    titleText3.setFont(titleFontArial);
    // set the strings to display
    titleText1.setString("The");
    titleText2.setString("Void");
    titleText3.setString("Press [ENTER] key");
    // set the font sizes
    titleText1.setCharacterSize(225);
    titleText2.setCharacterSize(225);
    titleText3.setCharacterSize(50);
    // set the color
    titleText1.setFillColor(sf::Color::Black);
    titleText2.setFillColor(sf::Color::Black);
    titleText3.setFillColor(sf::Color::Black);
    // set the text styles
    titleText1.setStyle(sf::Text::Bold);
    titleText2.setStyle(sf::Text::Bold);
    //center the positions of the title screen texts
    titleText1.setPosition((TITLE_WINDOW_SIZE_X - 330.f)/2, ((TITLE_WINDOW_SIZE_Y - 550)/2.f));
    titleText2.setPosition((TITLE_WINDOW_SIZE_X - 408.f)/2, ((TITLE_WINDOW_SIZE_Y - 550)/2.f) + (179.f+25.f));
    titleText3.setPosition((TITLE_WINDOW_SIZE_X - 423.f)/2, ((TITLE_WINDOW_SIZE_Y - 550)/2.f) + (179.f+25.f) + (179.f+65.f));
    // draw the texts
    p_titleScreenWindow->draw(titleText1);
    p_titleScreenWindow->draw(titleText2);
    p_titleScreenWindow->draw(titleText3);

    // end the current frame
    p_titleScreenWindow->display();
}