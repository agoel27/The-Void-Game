// header file for insideHouseScreen.cpp
#ifndef INSIDEHOUSESCREEN_H
#define INSIDEHOUSESCREEN_H

#include <SFML/Graphics.hpp>

void setupInsideHouse(sf::RenderWindow&);
void processInsideHouseInput(sf::RenderWindow&, sf::Event&);
void drawInsideHouse(sf::RenderWindow&);
void movementUpdate();


#endif
