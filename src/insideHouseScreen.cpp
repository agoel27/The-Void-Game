#include <stdlib.h>     // exit, EXIT_FAILURE
#include <iostream>
#include "../header/insideHouseScreen.h"

/*
    Implements inside house screen related functions
        - Renders inside house screen
        - Handles keyboard inputs from player

    NOTE:
    
    Texture might break depending on where you compile this file from
        - Definitely works if working directory is ../final-project-thevoidgame
*/

//WORLD
sf::RectangleShape world;

//PLAYER
sf::Sprite player;
sf::Texture player_forward;

sf::Vector2f player_position(0, 0);

/*
    This function instantiates and sets up all the inside house screen objects using SFML graphics
    Called from main() before game loop

    Input:  insideHouseWindow - alias of RenderWindow object
*/
void setupInsideHouse (sf::RenderWindow& insideHouseWindow) {
    // loads player sprite from resources directory
    if (!player_forward.loadFromFile("resources/player.png"))
    {
        std::cout << "ERROR: could not load the player sprite from resources directory\n - Please check the note at the top of <screenName>.cpp\n";
        exit (EXIT_FAILURE);
    }
    
    // sets background size
    world.setSize(sf::Vector2f(800, 800));
    // sets background color
    world.setFillColor(sf::Color(200, 230, 150));
    // sets player sprite
    player.setTexture(player_forward);
    //sets sprite size
    player.setScale(0.1f, 0.1f);
    //player.setTextureRect(sf::IntRect(State*player_sheet.getSize().y,0,player_sheet.getSize().y,player_sheet.getSize().y)); //SpriteSheet
}

/*
    This function processes the player input from the inside house screen
    Called from main() within game loop

    Input:  insideHouseWindow - alias of RenderWindow object
            insideHouseEvent  - alias of Event object
    Output: 
            closes window if player closes window :)
*/
void processInsideHouseInput(sf::RenderWindow& insideHouseWindow, sf::Event& insideHouseEvent) {
    // checks all window events triggered since last iteration of loop - event loop
    while (insideHouseWindow.pollEvent(insideHouseEvent)) {
        // checks type of event
        switch (insideHouseEvent.type) {
            // key pressed
            case sf::Event::KeyPressed:
                // update player movement
                movementUpdate();
                break;
            // "close requested" event: close the window
            case sf::Event::Closed:
                insideHouseWindow.close();
                break;
            // don't process other types of events
            default:
                break;
        }
    }
}

/*
    This function draws all the graphics objects to the inside house screen
    Called from main() within game loop

    Input:  insideHouseWindow - alias of RenderWindow object
    Output: all objects drawn to screen
*/
void drawInsideHouse(sf::RenderWindow& insideHouseWindow)
{
    // clears window with black color
    insideHouseWindow.clear(sf::Color::Black);

    //DRAW ORDER
    insideHouseWindow.draw(world);
    insideHouseWindow.draw(player);

    // ends current frame
    insideHouseWindow.display();
}

/*
    This function updates the player's position dependent on the arrow key pressed
    Called from processInsideHouseInput()

    Output: updates player postion
*/
void movementUpdate()
{
    //MOVEMENT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player_position.x -= 10.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player_position.x += 10.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player_position.y -= 10.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        player_position.y += 10.f;
    }
    player.setPosition(player_position);
}