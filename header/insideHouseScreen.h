// header file for insideHouseScreen.cpp
#ifndef INSIDEHOUSESCREEN_H
#define INSIDEHOUSESCREEN_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Interactable.h"
#include "TextboxManager.h"
#include "InteractionManager.h"
#include <stdlib.h>
#include <vector>

void setupInsideHouse(sf::RenderWindow&);
void processInsideHouseInput(sf::RenderWindow&, sf::Event&);
void drawInsideHouse(sf::RenderWindow&);
void insideHouseEventUpdate(sf::Event& e);
void insideHouseUpdate();
void movementUpdate();


#endif
