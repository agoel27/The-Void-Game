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
sf::RectangleShape world(sf::Vector2f(1200, 800));

//GameObjects
GameObject flooring(sf::Vector2f(1 * 64 + 300, 2 * 64), sf::Vector2f(2.0f, 2.0f), "resources/room.png");
GameObject walls(sf::Vector2f(0 + 300, 0), sf::Vector2f(2.0f, 2.0f), "resources/room.png");
GameObject player(sf::Vector2f(2 * 64 + 300, 3 * 64), sf::Vector2f(.1f, .1f), "resources/player.png");
std::vector<GameObject> GameObjects;

//Interactables
//Interactable key(sf::Vector2f(0,0), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "...", Interactable::text);
Interactable bed(sf::Vector2f(6 * 64 + 300, 1 * 64 + 32), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "Feeling Sleepy?", Interactable::text);
Interactable table(sf::Vector2f(3 * 64 + 300, 2 * 64 + 32), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "Where's the food?", Interactable::text);
Interactable bedside_table(sf::Vector2f(7 * 64 + 300, 1 * 64 + 32), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "There's tablets in here.\nNo wait they're hydratable dinosaur sponges.", Interactable::text);
Interactable chair(sf::Vector2f(2 * 64 + 32 + 300, 3 * 64), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "For Sitting and Stuff.", Interactable::text);
Interactable wardrobe(sf::Vector2f(2 * 64 + 300, 1 * 64 + 32), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "The usual.", Interactable::text);
Interactable bookshelf(sf::Vector2f(1 * 64 + 300, 4 * 64), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "The books have no titles, the pages are empty.", Interactable::text);
Interactable bookshelf2(sf::Vector2f(1 * 64 + 300, 5 * 64), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "There's a box of herbs and a pop vinyl.", Interactable::text);
Interactable windowsill(sf::Vector2f(4 * 64 + 300, 1 * 64), sf::Vector2f(2.0f, 2.0f), "resources/room.png", "Thick with Dirt?", Interactable::text);
Interactable door(sf::Vector2f(6 * 64 + 300, 8 * 64), sf::Vector2f(2.0f, 2.0f), "resources/room.png", "It's locked", Interactable::text);
std::vector<Interactable> Interactables;

//UI
TextboxManager textBox;
InteractionManager interactionManager(Interactables);

/*
    This function instantiates and sets up all the inside house screen objects using SFML graphics
    Called from main() before game loop

    Input:  insideHouseWindow - alias of RenderWindow object
*/
void setupInsideHouse (sf::RenderWindow& window) {
    world.setFillColor(sf::Color(10, 9, 9));

    flooring.SetTextureRect(10 * 32, 0 * 32, 7 * 32, 8 * 32);
    walls.SetTextureRect(0 * 32, 0 * 32, 9 * 32, 10 * 32);
    GameObjects.push_back(flooring);
    GameObjects.push_back(walls);

    bed.SetTextureRect(7 * 32, 2 * 32, 2 * 32, 32); //left offset, top offset, Y size, X size
    table.SetTextureRect(11 * 32, 2 * 32, 3 * 32, 2 * 32); //left offset, top offset, Y size, X size
    //key
    bedside_table.SetTextureRect(13 * 32, 0 * 32, 2 * 32, 32);
    chair.SetTextureRect(21 * 32, 4 * 32, 2 * 32, 32);
    wardrobe.SetTextureRect(6 * 32, 0 * 32, 2 * 32, 32);
    bookshelf.SetTextureRect(0, 2 * 32, 2 * 32, 32);
    bookshelf2.SetTextureRect(0, 6 * 32, 2 * 32, 32);
    windowsill.SetTextureRect(10 * 32, 7 * 32, 32, 32);
    door.SetTextureRect(10 * 32, 8 * 32, 2 * 32, 32);
    Interactables.push_back(bed);
    Interactables.push_back(table);
    Interactables.push_back(bedside_table);
    Interactables.push_back(chair);
    Interactables.push_back(wardrobe);
    Interactables.push_back(bookshelf);
    Interactables.push_back(bookshelf2);
    Interactables.push_back(windowsill);
    Interactables.push_back(door);
}

/*
    This function processes the player input from the inside house screen
    Called from main() within game loop

    Input:  insideHouseWindow - alias of RenderWindow object
            insideHouseEvent  - alias of Event object
    Output: 
            closes window if player closes window :)
*/
void processInsideHouseInput(sf::RenderWindow& window, sf::Event& event) {
    // checks all window events triggered since last iteration of loop - event loop
    while (window.pollEvent(event)) {
        // checks type of event
        if (event.type == sf::Event::Closed)
            window.close();

        insideHouseEventUpdate(event);
    }

    //Runs update functions in all applicable objects
    insideHouseUpdate();
}

void insideHouseEventUpdate(sf::Event& event)
{
    //perform input-related updates
    if((event.type == sf::Event::KeyPressed))
    {
        //Key press events
        if(event.key.code == sf::Keyboard::Space)
            textBox.Next();

    }
    interactionManager.EventUpdate(event, textBox);
}

void insideHouseUpdate()
{
    // update player movement
    movementUpdate();
}

/*
    This function draws all the graphics objects to the inside house screen
    Called from main() within game loop

    Input:  insideHouseWindow - alias of RenderWindow object
    Output: all objects drawn to screen
*/
void drawInsideHouse(sf::RenderWindow& window)
{
    //Render must be called on all objects before they are drawn
    for(int i = 0; i < GameObjects.size(); i++)
        GameObjects[i].Render();
    for(int i = 0; i < Interactables.size(); i++)
        Interactables[i].Render();
    player.Render();
    textBox.Render();

    //DRAW ORDER
    window.draw(world);
    for(int i = 0; i < GameObjects.size(); i++)
        window.draw(GameObjects[i]);
    for(int i = 0; i < Interactables.size(); i++)
        window.draw(Interactables[i]);
    window.draw(player);
    window.draw(textBox);

    //Display
    window.display();
}

/*
    This function updates the player's position dependent on the arrow key pressed
    Called from processInsideHouseInput()

    Output: updates player postion
*/
void movementUpdate()
{
    sf::Vector2f moveVector(0,0);
    float moveSpeed = 5.0f;
    //MOVEMENT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        moveVector.x -= moveSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        moveVector.x += moveSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        moveVector.y -= moveSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        moveVector.y += moveSpeed;
    }
    
    player.AddPosition(moveVector.x, moveVector.y);
}