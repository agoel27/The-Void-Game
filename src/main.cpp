#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Interactable.h"
#include "TextboxManager.h"
#include <stdlib.h>
#include <vector>

sf::RenderWindow window(sf::VideoMode(800, 800), "It's Working");
    
//WORLD
sf::RectangleShape world(sf::Vector2f(800, 800));

//GameObjects
GameObject player(sf::Vector2f(0,0), sf::Vector2f(.1f, .1f), "resources/player.png");

//Interactables
Interactable bed(sf::Vector2f(0,0), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "A bed", Interactable::text);
Interactable table(sf::Vector2f(160,80), sf::Vector2f(2.0f, 2.0f), "resources/furniture.png", "A table", Interactable::text);
std::vector<Interactable> Interactables;

//UI
TextboxManager textBox;

void RenderAll()
{
    //Render must be called on all objects before they are drawn
    for(int i = 0; i < Interactables.size(); i++)
        Interactables[i].Render();
    player.Render();
    textBox.Render();

    //DRAW ORDER
    window.draw(world);
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

void Update()
{
    //run update on all Instantiated Objects
    MovementUpdate();
}

int main() {
    sf::Event e;

    world.setFillColor(sf::Color(200, 230, 150));

    bed.SetTextureRect(7 * 32, 2 * 32, 2 * 32, 32); //left offset, top offset, Y size, X size
    table.SetTextureRect(11 * 32, 2 * 32, 3 * 32, 2 * 32); //left offset, top offset, Y size, X size
    Interactables.push_back(bed);
    Interactables.push_back(table);

    //example textbox set
    //textBox.SetText("The Dog\nRan away from\nIt's owner.", '\n');

    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();

            if((e.type == sf::Event::KeyPressed))
            {
                //Key press events
                if(e.key.code == sf::Keyboard::Space)
                    textBox.Next();
            }
        }

        Update();

        RenderAll();
    }
}