#include <stdlib.h>     // exit, EXIT_FAILURE
#include <iostream>
#include "../header/outsideScreen.h"
#include "../header/StoryBeats.h"

/*
    Implements outside house screen related functions
        - Renders outside house screen
        - Handles keyboard inputs from player

    NOTE:
    
    Texture might break depending on where you compile this file from
        - Definitely works if working directory is ../final-project-thevoidgame
*/

bool tryOutsidePush(GameObject& obj, sf::Vector2f direction);

//GameObjects
GameObject outsidePlayer_m(sf::Vector2f(2 * 64 + 300, 3 * 64), sf::Vector2f(3,3), "resources/M_05.png");
GameObject outsidePlayer_f(sf::Vector2f(2 * 64 + 300, 3 * 64), sf::Vector2f(3,3), "resources/F_08.png");
GameObject outsideHouse(sf::Vector2f(584 - 48, 375 - 176), sf::Vector2f(2.0f, 2.0f), "resources/main_houses.png");
std::vector<GameObject> outsideGameObjects;

//Interactables
Interactable outsideDoor(sf::Vector2f(584, 375), sf::Vector2f(2.0f, 2.0f), "resources/room.png", "*It's unlocked*", Interactable::text, "outsideDoor");
Interactable well(sf::Vector2f(425, 275), sf::Vector2f(2.0f, 2.0f), "resources/decorative_props.png", "*The well's bottomless darkness conceal both secrets and despair* \n*Jump in?* \n*Haha probably not a good idea!*", Interactable::text);
Interactable emptyBoxesHorizontal(sf::Vector2f(375, 500), sf::Vector2f(2.0f, 2.0f), "resources/decorative_props.png", "*Boxes adrift in an abyss of nothingness*", Interactable::text, true, true);
Interactable emptyBoxesLong(sf::Vector2f(250, 500), sf::Vector2f(2.0f, 2.0f), "resources/decorative_props.png", "*Alone in the black void, all that remain are empty boxes, harboring untold mysteries*", Interactable::text);
Interactable emptyBoxesVertical(sf::Vector2f(325, 400), sf::Vector2f(2.0f, 2.0f), "resources/decorative_props.png", "*Hollow boxes echo with the weight of the unknown*", Interactable::text, true, true);
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

    outsidePlayer_m.SetTextureRect(0,0,17,17);
    outsidePlayer_f.SetTextureRect(0,0,17,17);
    outsideHouse.SetTextureRect(24 * 32 + 8, 4 * 32 + 8, 4 * 32 + 8, 2 * 32 + 16);
    outsideDoor.SetTextureRect(11*32, 8*32, 2*32, 32);
    well.SetTextureRect(8, 13*32, 2*32, 32+16);
    emptyBoxesHorizontal.SetTextureRect(4*32 + 16, 10*32, 32, 32+8);
    emptyBoxesLong.SetTextureRect(6*32 + 16, 10*32 + 8, 32+8, 32+8);
    emptyBoxesVertical.SetTextureRect(4*32, 11*32 + 8, 32+16, 32);

    outsideHouse.SetColliderRect(0, 0, 0, 0);
    well.SetColliderRect(0, 0, 0, 0);
    emptyBoxesHorizontal.SetColliderRect(0, 0, 0, 0);
    emptyBoxesLong.SetColliderRect(0, 0, 0, 0);
    emptyBoxesVertical.SetColliderRect(0, 0, 0, 0);

    outsideGameObjects.push_back(outsideHouse);
    outsideInteractables.push_back(outsideDoor);
    outsideInteractables.push_back(well);
    outsideInteractables.push_back(emptyBoxesHorizontal);
    outsideInteractables.push_back(emptyBoxesLong);
    outsideInteractables.push_back(emptyBoxesVertical);

    outsideTextBox.SetText("THIS CAN'T BE!!!,WHAT HAPPENED TO EVERYTHING,WHY IS IT ALL A VOID???,*If the reality of this emptiness becomes unbearable* \n*I'll lull you into slumber and strip your memories away*,*Then you shall awaken once more* \n*Destined to endure this dreadful revelation anew*,WHO WAS THAT!?,", ',');
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

    if(hasFlag(3)) {
        outsidePlayer_m.Render();
    }
    else if(hasFlag(4)) {
        outsidePlayer_f.Render();
    }
    outsideTextBox.Render();

    //DRAW ORDER
    for(int i = 0; i < outsideGameObjects.size(); i++)
        window.draw(outsideGameObjects[i]);
    for(int i = 0; i < outsideInteractables.size(); i++)
        window.draw(outsideInteractables[i]);
    if(hasFlag(3)) {
        window.draw(outsidePlayer_m);
    }
    else if(hasFlag(4)) {
        window.draw(outsidePlayer_f);
    }
    window.draw(outsideTextBox);

    //Display
    window.display();
}

/*
    A helper function that checks if a point is in the global bounds of a rect

    Input:
    float rectangle
    point

    Output: bool is the point in the rectangle
*/
bool isInOutsideRect(sf::FloatRect rect, sf::Vector2f point)
{
    if(point.x >= rect.left && point.x <= rect.left + rect.width
        && point.y >= rect.top && point.y <= rect.top + rect.height)
    {
        return true;
    }
    return false;
}

/*
    Input: 
    an object and a movement direction
    the list of gameObjects in the scene
    the list of interactables in the scene

    Output: whether moving will cause the object to intersect another collider
*/
bool checkOutsideCollision(GameObject& obj, sf::Vector2f direction)
{
    sf::FloatRect colliderRect = obj.GetCollisionRect();
    colliderRect.left += direction.x;
    colliderRect.top += direction.y;

    //run a click comparison for all 4 corners of new rect for each gameobject
    for(auto iter = outsideGameObjects.end()-1; iter != outsideGameObjects.begin()-1; iter--)
    {
        if(!iter->Collides() || &obj == &(*iter)) continue;

        sf::FloatRect rect = iter->GetCollisionRect();
        //top left
        //bottom left
        //top right
        //bottom right
        if (isInOutsideRect(rect, sf::Vector2f(colliderRect.left, colliderRect.top))
        || isInOutsideRect(rect, sf::Vector2f(colliderRect.left, colliderRect.top + colliderRect.height))
        || isInOutsideRect(rect, sf::Vector2f(colliderRect.left + colliderRect.width, colliderRect.top))
        || isInOutsideRect(rect, sf::Vector2f(colliderRect.left + colliderRect.width, colliderRect.top + colliderRect.height)))
        {
            return tryOutsidePush(*iter, direction);
        }
    }
    //run a click comparison for all 4 corners of new rect for each interactable
    for(auto iter = outsideInteractables.end()-1; iter != outsideInteractables.begin()-1; iter--)
    {
        if(!iter->Collides() || &obj == &(*iter)) continue;

        sf::FloatRect rect = iter->GetCollisionRect();
        //top left
        //bottom left
        //top right
        //bottom right
        if (isInOutsideRect(rect, sf::Vector2f(colliderRect.left, colliderRect.top))
        || isInOutsideRect(rect, sf::Vector2f(colliderRect.left, colliderRect.top + colliderRect.height))
        || isInOutsideRect(rect, sf::Vector2f(colliderRect.left + colliderRect.width, colliderRect.top))
        || isInOutsideRect(rect, sf::Vector2f(colliderRect.left + colliderRect.width, colliderRect.top + colliderRect.height)))
        {
            return tryOutsidePush(*iter, direction);
        }
    }

    return false;
}

/*
    Input: an object and a movement direction

    Output: whether movement was successful
*/
bool tryMoveOutsideGameObject(GameObject& obj, sf::Vector2f direction)
{
    if(!checkOutsideCollision(obj, direction))
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
    applies a push to an object

    Input: an object and a movement direction

    Output: whether a hard collision occured
*/
bool tryOutsidePush(GameObject& obj, sf::Vector2f direction)
{
    if(obj.Pushable())
    {
        return !tryMoveOutsideGameObject(obj, direction);
    }
    else{
        return true;
    }
}

/*
    This function updates the player's position dependent on the WASD key pressed
    Called from outsideHouseUpdate()

    Output: updates player postion
*/
void outsideMovementUpdate()
{
    sf::Vector2f moveVector(0,0);
    float moveSpeed = 5.0f;
  
    if (hasFlag(3)) 
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            int xTexture = 0;
            xTexture = (int)outsidePlayer_m.GetPosition().y / 25 % 3;
            xTexture *= 17;

            outsidePlayer_m.SetTextureRect(32,xTexture,17,17);
            moveVector.y -= moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            int xTexture = 0;
            xTexture = (int)outsidePlayer_m.GetPosition().y / 25 % 3;
            xTexture *= 17;

            outsidePlayer_m.SetTextureRect(0,xTexture,17,17);
            moveVector.y += moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            int yTexture = 0;
            yTexture = (int)outsidePlayer_m.GetPosition().x / 25 % 3;
            yTexture *= 17;

            outsidePlayer_m.SetTextureRect(48,yTexture,17,17);
            moveVector.x -= moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            int yTexture = 0;
            yTexture = (int)outsidePlayer_m.GetPosition().x / 25 % 3;
            yTexture *= 17;

            outsidePlayer_m.SetTextureRect(16,yTexture,17,17);
            moveVector.x += moveSpeed;
        }
    }
    else if (hasFlag(4)) 
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            int xTexture = 0;
            xTexture = (int)outsidePlayer_f.GetPosition().y / 25 % 3;
            xTexture *= 17;

            outsidePlayer_f.SetTextureRect(32,xTexture,17,17);
            moveVector.y -= moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            int xTexture = 0;
            xTexture = (int)outsidePlayer_f.GetPosition().y / 25 % 3;
            xTexture *= 17;

            outsidePlayer_f.SetTextureRect(0,xTexture,17,17);
            moveVector.y += moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            int yTexture = 0;
            yTexture = (int)outsidePlayer_f.GetPosition().x / 25 % 3;
            yTexture *= 17;

            outsidePlayer_f.SetTextureRect(48,yTexture,17,17);
            moveVector.x -= moveSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            int yTexture = 0;
            yTexture = (int)outsidePlayer_f.GetPosition().x / 25 % 3;
            yTexture *= 17;

            outsidePlayer_f.SetTextureRect(16,yTexture,17,17);
            moveVector.x += moveSpeed;
        }
    }
    if (hasFlag(3)) {
        tryMoveOutsideGameObject(outsidePlayer_m, moveVector);
    }
    else if (hasFlag(4)) {
        tryMoveOutsideGameObject(outsidePlayer_f, moveVector);
    }
}

