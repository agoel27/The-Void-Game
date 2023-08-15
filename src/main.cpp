#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <stdlib.h>

sf::RenderWindow window(sf::VideoMode(800, 800), "It's Working");
    
//WORLD
sf::RectangleShape world(sf::Vector2f(800, 800));

//GameObjects
GameObject player(sf::Vector2f(0,0), sf::Vector2f(.1f, .1f), "resources/player.png");

void RenderAll()
{
    //Render must be called on all objects before they are drawn
    player.Render();

    //DRAW ORDER
    window.draw(world);
    window.draw(player);
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
    //run update on all Instatntiated Objects
    MovementUpdate();
}

int main() {
    sf::Event e;

    world.setFillColor(sf::Color(200, 230, 150));

    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }

        Update();

        RenderAll();
    }
}