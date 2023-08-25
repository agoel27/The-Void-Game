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
GameObject flooring(sf::Vector2f(1 * 64 + 300, 2 * 64), sf::Vector2f(2.0f, 2.0f), "resources/room.png", false, false);
GameObject leftWall(sf::Vector2f(0 + 300, 0), sf::Vector2f(2.0f, 2.0f), "resources/room.png");
GameObject rightWall(sf::Vector2f(9 * 64 + 300, 0), sf::Vector2f(2.0f, 2.0f), "resources/room.png");
GameObject topWall(sf::Vector2f(64 + 300, 0), sf::Vector2f(2.0f, 2.0f), "resources/room.png");
GameObject bottomLeftWall(sf::Vector2f(64 + 300, 7 * 64 + 36), sf::Vector2f(2.0f, 2.0f), "resources/room.png");
GameObject bottomRightWall(sf::Vector2f(64 * 7 + 300, 7 * 64 + 36), sf::Vector2f(2.0f, 2.0f), "resources/room.png");
GameObject doorFrame(sf::Vector2f(64 * 6 + 300, 7 * 64), sf::Vector2f(2.0f, 2.0f), "resources/room.png", false, false);
GameObject player(sf::Vector2f(2 * 64 +  + 300, 6 * 64), sf::Vector2f(.05f, .05f), "resources/player.png");
std::vector<GameObject> GameObjects;

//Interactables
Interactable key(sf::Vector2f(6 * 64 + 16 + 300, 2 * 64), sf::Vector2f(1.0f, 1.0f), "resources/key.png", "There it is!", Interactable::text, false, false);
Interactable bed(sf::Vector2f(6 * 64 + 300, 2 * 64 - 16), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "Feeling Sleepy?", Interactable::text, true, true);
Interactable table(sf::Vector2f(3 * 64 + 300, 4 * 64), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "Where's the food?", Interactable::text);
Interactable bedside_table(sf::Vector2f(7 * 64 + 300, 2 * 64 - 16), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "There's tablets in here.\nNo wait they're hydratable dinosaur sponges.", Interactable::text);
Interactable wardrobe(sf::Vector2f(2 * 64 + 300, 1 * 64 + 24), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "The usual.", Interactable::text);
Interactable chair(sf::Vector2f(2 * 64 + 32 + 300, 4 * 64 + 32), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "For Sitting and Stuff.", Interactable::text);
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
    leftWall.SetTextureRect(0 * 32, 0 * 32, 9 * 32, 1 * 32);
    rightWall.SetTextureRect(9 * 32, 0 * 32, 9 * 32, 1 * 32);
    topWall.SetTextureRect(1 * 32, 0 * 32, 2 * 32, 8 * 32);
    bottomLeftWall.SetTextureRect(1 * 32, 7 * 32 + 18, 2 * 32 - 18, 5 * 32);
    bottomRightWall.SetTextureRect(7 * 32, 7 * 32 + 18, 2 * 32 - 18, 2 * 32);
    doorFrame.SetTextureRect(6 * 32, 7 * 32, 1 * 32, 1 * 32);



    GameObjects.push_back(flooring);
    GameObjects.push_back(leftWall);
    GameObjects.push_back(rightWall);
    GameObjects.push_back(topWall);
    GameObjects.push_back(bottomLeftWall);
    GameObjects.push_back(bottomRightWall);
    GameObjects.push_back(doorFrame);



    windowsill.SetTextureRect(10 * 32, 7 * 32, 32, 32);
    wardrobe.SetTextureRect(6 * 32, 0 * 32, 2 * 32 - 16, 32);
    //key
    bed.SetTextureRect(7 * 32, 2 * 32 + 16, 2 * 32 - 16, 32); //left offset, top offset, Y size, X size
    table.SetTextureRect(11 * 32, 2 * 32 + 32, 2 * 32 - 8, 2 * 32); //left offset, top offset, Y size, X size
    bedside_table.SetTextureRect(13 * 32, 0 * 32 + 16, 1 * 32, 32);
    chair.SetTextureRect(21 * 32, 4 * 32 + 16, 2 * 32 - 24, 32 - 8);
    bookshelf.SetTextureRect(0, 2 * 32 + 8, 2 * 32 - 8, 32 - 16);
    bookshelf2.SetTextureRect(0, 6 * 32 + 8, 2 * 32 - 8, 32 - 16);
    door.SetTextureRect(10 * 32, 8 * 32, 2 * 32, 32);



    wardrobe.SetColliderRect(6, 1, 6, 6);
    bed.SetColliderRect(5, 20, 0, 5);
    table.SetColliderRect(10, 3, 13, 10);
    bedside_table.SetColliderRect(3, 13, 9, 3);
    chair.SetColliderRect(3, 5, 8, 10);



    Interactables.push_back(key);
    Interactables.push_back(windowsill);
    Interactables.push_back(wardrobe);
    Interactables.push_back(bed);
    Interactables.push_back(bedside_table);
    Interactables.push_back(table);
    Interactables.push_back(chair);
    Interactables.push_back(bookshelf);
    Interactables.push_back(bookshelf2);
    Interactables.push_back(door);
}

/*
    This function processes the player input from the inside house screen
    Called from main() within game loop

    Input:  window - alias of RenderWindow object
            event  - alias of Event object
    Output: 
            closes window if player closes window :)
*/
void processInsideHouseInput(sf::RenderWindow& window, sf::Event& event) {
    // checks all window events triggered since last iteration of loop - event loop
    while (window.pollEvent(event)) {
        // checks type of event
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed)
            if (event.key.code == sf::Keyboard::Escape)
                window.close();

        insideHouseEventUpdate(event);
    }

    //Runs update functions in all applicable objects
    insideHouseUpdate();
}

void insideHouseEventUpdate(sf::Event& event)
{
    //perform input-related updates
    if(event.type == sf::Event::KeyPressed)
    {
        //Key press events
        if(event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Enter)
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

    Input:  window - alias of RenderWindow object
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

    tryMoveGameObject(player, moveVector);
}

/*
    Input: an object and a movement direction

    Output: whether movement was successful
*/
bool tryMoveGameObject(GameObject& obj, sf::Vector2f direction)
{
    if(!checkCollision(obj, direction))
    {
        obj.AddPosition(direction.x, direction.y);
        return true;
    }
    else
    {
        return false;
    }
}

/*
    Input: 
    an object and a movement direction
    the list of gameObjects in the scene
    the list of interactables in the scene

    Output: whether moving will cause the object to intersect another collider
*/
bool checkCollision(GameObject& obj, sf::Vector2f direction)
{
    sf::FloatRect colliderRect = obj.GetCollisionRect();
    colliderRect.left += direction.x;
    colliderRect.top += direction.y;

    //run a click comparison for all 4 corners of new rect for each gameobject
    for(auto iter = GameObjects.end()-1; iter != GameObjects.begin()-1; iter--)
    {
        if(!iter->Collides() || &obj == &(*iter)) continue;

        sf::FloatRect rect = iter->GetCollisionRect();
        //top left
        //bottom left
        //top right
        //bottom right
        if (isInRect(rect, sf::Vector2f(colliderRect.left, colliderRect.top))
        || isInRect(rect, sf::Vector2f(colliderRect.left, colliderRect.top + colliderRect.height))
        || isInRect(rect, sf::Vector2f(colliderRect.left + colliderRect.width, colliderRect.top))
        || isInRect(rect, sf::Vector2f(colliderRect.left + colliderRect.width, colliderRect.top + colliderRect.height)))
        {
            return tryPush(*iter, direction);
        }
    }
    //run a click comparison for all 4 corners of new rect for each interactable
    for(auto iter = Interactables.end()-1; iter != Interactables.begin()-1; iter--)
    {
        if(!iter->Collides() || &obj == &(*iter)) continue;

        sf::FloatRect rect = iter->GetCollisionRect();
        //top left
        //bottom left
        //top right
        //bottom right
        if (isInRect(rect, sf::Vector2f(colliderRect.left, colliderRect.top))
        || isInRect(rect, sf::Vector2f(colliderRect.left, colliderRect.top + colliderRect.height))
        || isInRect(rect, sf::Vector2f(colliderRect.left + colliderRect.width, colliderRect.top))
        || isInRect(rect, sf::Vector2f(colliderRect.left + colliderRect.width, colliderRect.top + colliderRect.height)))
        {
            return tryPush(*iter, direction);
        }
    }

    return false;
}

/*
    applies a push to an object

    Input: an object and a movement direction

    Output: whether a hard collision occured
*/
bool tryPush(GameObject& obj, sf::Vector2f direction)
{
    if(obj.Pushable())
    {
        return !tryMoveGameObject(obj, direction);
    }
    else{
        return true;
    }
}

/*
    A helper function that checks if a point is in the global bounds of a rect

    Input:
    float rectangle
    point

    Output: bool is the point in the rectangle
*/
bool isInRect(sf::FloatRect rect, sf::Vector2f point)
{
    if(point.x >= rect.left && point.x <= rect.left + rect.width
        && point.y >= rect.top && point.y <= rect.top + rect.height)
    {
        return true;
    }
    return false;
}