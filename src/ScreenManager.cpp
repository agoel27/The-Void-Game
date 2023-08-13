#include "titleScreen.h"

/*
    This script manages all the screens. Refer to Navigation Layout on README
*/

// set window size
#define WINDOW_SIZE_X 800
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
        
        // call renderTitleScreen() func - renders title screen
        renderTitleScreen(&gameWindow);
        // call getTitleScreenInput() func - processes user events 
        processTitleScreenInput(&gameWindow, &screenEvent);
    }

    return 0;
}

