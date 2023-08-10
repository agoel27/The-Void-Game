#include <SFML/Graphics.hpp>
//#include <SFML/Graphics/RectangleShape.hpp>
//#include <vector>
//#include <deque>
//#include <fstream>
#include <stdlib.h>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 800), "It's Working");
    sf::Event e;
    
    //WORLD
    sf::RectangleShape world(sf::Vector2f(800, 800));
    world.setFillColor(sf::Color(200, 230, 150));

    //PLAYER
    sf::Sprite player;
    sf::Texture player_forward;
    player_forward.loadFromFile("resources/player.png");
    player.setTexture(player_forward);
    player.setScale(0.1f, 0.1f);

    sf::Vector2f player_position(0, 0);

    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                window.close();
        }

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

        //ALL DRAWING CODE GOES HERE
        player.setTexture(player_forward);
        //player.setTextureRect(sf::IntRect(State*player_sheet.getSize().y,0,player_sheet.getSize().y,player_sheet.getSize().y)); //SpriteSheet

        player.setPosition(player_position);

        //DRAW ORDER
        window.draw(world);
        window.draw(player);
        window.display();
    }
}
