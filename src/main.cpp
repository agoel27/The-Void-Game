#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Interactable.h"
#include "TextboxManager.h"
#include "InteractionManager.h"
#include <stdlib.h>
#include <vector>

sf::RenderWindow window(sf::VideoMode(800, 800), "It's Working");
    
//WORLD
sf::RectangleShape world(sf::Vector2f(800, 800));

//GameObjects
GameObject flooring(sf::Vector2f(1 * 64, 2 * 64), sf::Vector2f(2.0f, 2.0f), "resources/room.png");
GameObject walls(sf::Vector2f(0, 0), sf::Vector2f(2.0f, 2.0f), "resources/room.png");
GameObject player(sf::Vector2f(2 * 64, 3 * 64), sf::Vector2f(.1f, .1f), "resources/player.png");
std::vector<GameObject> GameObjects;

//Interactables
//Interactable key(sf::Vector2f(0,0), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "...", Interactable::text);
Interactable bed(sf::Vector2f(6 * 64, 1 * 64 + 32), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "A bed", Interactable::text);
Interactable table(sf::Vector2f(3 * 64, 2 * 64 + 32), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "A table", Interactable::text);
Interactable bedside_table(sf::Vector2f(7 * 64, 1 * 64 + 32), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "...", Interactable::text);
Interactable chair(sf::Vector2f(2 * 64 + 32, 3 * 64), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "...", Interactable::text);
Interactable wardrobe(sf::Vector2f(2 * 64, 1 * 64 + 32), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "...", Interactable::text);
Interactable bookshelf(sf::Vector2f(1 * 64, 4 * 64), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "...", Interactable::text);
Interactable bookshelf2(sf::Vector2f(1 * 64, 5 * 64), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "...", Interactable::text);
Interactable windowsill(sf::Vector2f(4 * 64, 1 * 64), sf::Vector2f(2.0f, 2.0f), "resources/room.png", "...", Interactable::text);
Interactable door(sf::Vector2f(6 * 64, 8 * 64), sf::Vector2f(2.0f, 2.0f), "resources/room.png", "...", Interactable::text);
std::vector<Interactable> Interactables;

//UI
TextboxManager textBox;
InteractionManager interactionManager(Interactables);

void RenderAll()
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

void MovementUpdate()
{
    sf::Vector2f moveVector(0,0);
    //MOVEMENT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        moveVector.x -= 0.2f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        moveVector.x += 0.2f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        moveVector.y -= 0.2f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        moveVector.y += 0.2f;
    }
    
    player.AddPosition(moveVector.x, moveVector.y);
}

void EventUpdate(sf::Event& e)
{
    //run update on all Instantiated Objects
    if((e.type == sf::Event::KeyPressed))
    {
        //Key press events
        if(e.key.code == sf::Keyboard::Space)
            textBox.Next();

    }
    interactionManager.EventUpdate(e, textBox);
}

void Update()
{
    //run update on all Instantiated Objects
    MovementUpdate();
}

int main() {
    sf::Event e;

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

    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
            
            EventUpdate(e);
        }

        Update();

        RenderAll();
    }
}