#include <iostream>
#include "../header/StoryBeats.h"
#include "../header/titleScreen.h"
#include "../header/startScreen.h"
#include "../header/insideHouseScreen.h"

/*
    Manages all the screens. Refer to Navigation Layout on README
*/

// set window size
#define WINDOW_SIZE_X 1200
#define WINDOW_SIZE_Y 800



int main() {
    // create window - can not be resized
    sf::RenderWindow gameWindow(sf::VideoMode(WINDOW_SIZE_X, WINDOW_SIZE_Y), "The Void Game", sf::Style::Close);
    gameWindow.setFramerateLimit(30);
    // create user event for screen
    sf::Event screenEvent;

    // instantiates and sets up all graphic objects
    setupTitleScreen(gameWindow);
    setupStartScreen(gameWindow);
    setupInsideHouse(gameWindow);

    // start game by setting ENTER_TITLE_SCREEN_FLAG
    setFlag(0);

    // run program while window is open - game loop
    while(gameWindow.isOpen()) {
        
        if(hasFlag(0)) {
            // process player input and draws title screen
            processTitleScreenInput(gameWindow, screenEvent);
            drawTitleScreen(gameWindow);
        }
        else if(hasFlag(1)) {
            // process player input and draws title screen
            processStartScreenInput(gameWindow, screenEvent);
            drawStartScreen(gameWindow);
        }
        else if(hasFlag(2)) {
            // process player input and draws title screen
            processInsideHouseInput(gameWindow, screenEvent);
            drawInsideHouse(gameWindow);
        }
    }
    return 0;
}

