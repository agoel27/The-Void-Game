#include <iostream>
#include "storyBeats.h"
#include "titleScreen.h"
#include "startScreen.h"

/*
    This script manages all the screens. Refer to Navigation Layout on README
*/

// set window size
#define WINDOW_SIZE_X 1200
#define WINDOW_SIZE_Y 800

int main() 
{
    // create window - can not be resized
    sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "The Void Game", sf::Style::Close);

    // create user event for screen
    sf::Event screenEvent;

    // run program while window is open - game loop
    while (gameWindow.isOpen())
    {
        if (!hasFlag(0))
        {
            // call renderTitleScreen() func - renders title screen
            renderTitleScreen(&gameWindow);
            // call getTitleScreenInput() func - processes user events 
            processTitleScreenInput(&gameWindow, &screenEvent);
        }
        else if (hasFlag(0))
        {
            // call renderStartScreen() func - renders start screen
            renderStartScreen(&gameWindow);
            // call getStartScreenInput() func - processes user events 
            processStartScreenInput(&gameWindow, &screenEvent);
        }
        
        
        
    }

    return 0;
}

