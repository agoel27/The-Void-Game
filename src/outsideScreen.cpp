#include <stdlib.h>     // exit, EXIT_FAILURE
#include <iostream>
#include "../header/outsideScreen.h"

/*
    Implements outside house screen related functions
        - Renders outside house screen
        - Handles keyboard inputs from player

    NOTE:
    
    Texture might break depending on where you compile this file from
        - Definitely works if working directory is ../final-project-thevoidgame
*/

//GameObjects
GameObject outsidePlayer(sf::Vector2f(584, 375), sf::Vector2f(4,4), "resources/M_05.png");
GameObject outsideHouse(sf::Vector2f(584 - 48, 375 - 176), sf::Vector2f(2.0f, 2.0f), "resources/main_houses.png");
std::vector<GameObject> outsideGameObjects;

//Interactables
Interactable outsideDoor(sf::Vector2f(584, 375), sf::Vector2f(2.0f, 2.0f), "resources/room.png", "It's unlocked", Interactable::text, "outsideDoor");
Interactable well(sf::Vector2f(425, 275), sf::Vector2f(2.0f, 2.0f), "resources/decorative_props.png", "The well's bottomless darkness conceal both secrets and despair \nJump in? \nHaha probably not a good idea!", Interactable::text);
Interactable emptyBoxesHorizontal(sf::Vector2f(375, 500), sf::Vector2f(2.0f, 2.0f), "resources/decorative_props.png", "Boxes adrift in an abyss of nothingness", Interactable::text);
Interactable emptyBoxesLong(sf::Vector2f(250, 500), sf::Vector2f(2.0f, 2.0f), "resources/decorative_props.png", "Alone in the black void, all that remain are empty boxes, harboring untold mysteries.", Interactable::text);
Interactable emptyBoxesVertical(sf::Vector2f(325, 400), sf::Vector2f(2.0f, 2.0f), "resources/decorative_props.png", "Hollow boxes echo with the weight of the unknown.", Interactable::text);
std::vector<Interactable> outsideInteractables;

//UI
TextboxManager outsideTextBox;
InteractionManager outsideInteractionManager(outsideInteractables);

/*
    This function instantiates and sets up all the outside house screen objects using SFML graphics
    Called from main() before game loop

    Input:  outsideHouseWindow - alias of RenderWindow object
*/
void setupOutsideHouse (sf::RenderWindow& window) {
    
    outsideDoor.SetTextureRect(11*32, 8*32, 2*32, 32);
    well.SetTextureRect(8, 13*32, 2*32, 32+16);
    emptyBoxesHorizontal.SetTextureRect(4*32 + 16, 10*32, 32, 32+8);
    emptyBoxesLong.SetTextureRect(6*32 + 16, 10*32 + 8, 32+8, 32+8);
    emptyBoxesVertical.SetTextureRect(4*32, 11*32 + 8, 32+16, 32);
    outsideInteractables.push_back(outsideDoor);
    outsideInteractables.push_back(well);
    outsideInteractables.push_back(emptyBoxesHorizontal);
    outsideInteractables.push_back(emptyBoxesLong);
    outsideInteractables.push_back(emptyBoxesVertical);

    outsideHouse.SetTextureRect(24 * 32 + 8, 4 * 32 + 8, 4 * 32 + 8, 2 * 32 + 16);
    outsideGameObjects.push_back(outsideHouse);

    outsidePlayer.SetTextureRect(0,0,17,17);
}

/*
    This function processes the player input from the outside house screen
    Called from main() within game loop

    Input:  outsideHouseWindow - alias of RenderWindow object
            outsideHouseEvent  - alias of Event object
    Output: 
            closes window if player closes window :)
*/
void processOutsideHouseInput(sf::RenderWindow& window, sf::Event& event) {
    // checks all window events triggered since last iteration of loop - event loop
    while (window.pollEvent(event)) {
        // checks type of event
        if (event.type == sf::Event::Closed)
            window.close();

        outsideHouseEventUpdate(event);
    }

    //Runs update functions in all applicable objects
    outsideHouseUpdate();
}

void outsideHouseEventUpdate(sf::Event& event)
{
    //perform input-related updates
    if(event.type == sf::Event::KeyPressed)
    {
        //Key press events
        if(event.key.code == sf::Keyboard::Space)
            outsideTextBox.Next();

    }
    outsideInteractionManager.EventUpdate(event, outsideTextBox);
}

void outsideHouseUpdate()
{
    // update player movement
    outsideMovementUpdate();
}

/*
    This function draws all the graphics objects to the outside house screen
    Called from main() within game loop

    Input:  outsideHouseWindow - alias of RenderWindow object
    Output: all objects drawn to screen
*/
void drawOutsideHouse(sf::RenderWindow& window)
{
    // clears window with black color
    window.clear(sf::Color(10, 9, 9));

    //Render must be called on all objects before they are drawn
    for(int i = 0; i < outsideGameObjects.size(); i++)
        outsideGameObjects[i].Render();
    for(int i = 0; i < outsideInteractables.size(); i++)
        outsideInteractables[i].Render();
    outsidePlayer.Render();
    outsideTextBox.Render();

    //DRAW ORDER
    for(int i = 0; i < outsideGameObjects.size(); i++)
        window.draw(outsideGameObjects[i]);
    for(int i = 0; i < outsideInteractables.size(); i++)
        window.draw(outsideInteractables[i]);
    window.draw(outsidePlayer);
    window.draw(outsideTextBox);

    //Display
    window.display();
}

/*
    This function updates the player's position dependent on the WASD key pressed
    Called from outsideHouseUpdate()

    Output: updates player postion
*/
void outsideMovementUpdate()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
    {
        int xTexture = 0;
        xTexture = (int)outsidePlayer.GetPosition().y / 25 % 3;
        xTexture *= 17;

        outsidePlayer.SetTextureRect(32,xTexture,17,17);
        outsidePlayer.AddPosition(0,-5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
    {
        int xTexture = 0;
        xTexture = (int)outsidePlayer.GetPosition().y / 25 % 3;
        xTexture *= 17;

        outsidePlayer.SetTextureRect(0,xTexture,17,17);
        outsidePlayer.AddPosition(0,+5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
    {
        int yTexture = 0;
        yTexture = (int)outsidePlayer.GetPosition().x / 25 % 3;
        yTexture *= 17;

        outsidePlayer.SetTextureRect(48,yTexture,17,17);
        outsidePlayer.AddPosition(-5,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
    {
        int yTexture = 0;
        yTexture = (int)outsidePlayer.GetPosition().x / 25 % 3;
        yTexture *= 17;

        outsidePlayer.SetTextureRect(16,yTexture,17,17);
        outsidePlayer.AddPosition(+5,0);
    }
}