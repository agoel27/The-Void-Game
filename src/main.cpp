#include <SFML/Graphics.hpp>
#include <stdlib.h>

sf::RenderWindow window(sf::VideoMode(800, 800), "It's Working");
    
//WORLD
sf::RectangleShape world(sf::Vector2f(800, 800));

//PLAYER
sf::Sprite player;
sf::Texture player_forward;

sf::Vector2f player_position(0, 0);

void RenderAll()
{
    //run render on all GameObjects
    
    player.setTexture(player_forward);
    //player.setTextureRect(sf::IntRect(State*player_sheet.getSize().y,0,player_sheet.getSize().y,player_sheet.getSize().y)); //SpriteSheet

    player.setPosition(player_position);

    //DRAW ORDER
    window.draw(world);
    window.draw(player);
    window.display();
}

void MovementUpdate()
{
    //MOVEMENT
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player_position.x -= 0.2f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player_position.x += 0.2f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player_position.y -= 0.2f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        player_position.y += 0.2f;
    }
}

void Update()
{
    //run update on all Instatntiated Objects
    MovementUpdate();
}

int main() {
    sf::Event e;

    world.setFillColor(sf::Color(200, 230, 150));

    player_forward.loadFromFile("resources/player.png");
    player.setTexture(player_forward);
    player.setScale(0.1f, 0.1f);

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