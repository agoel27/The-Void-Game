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
bool tryMoveGameObject(GameObject& obj, sf::Vector2f direction);
bool tryPush(GameObject& obj, sf::Vector2f direction);
bool checkCollision(GameObject& obj, sf::Vector2f direction);
bool isInRect(sf::FloatRect, sf::Vector2f);
void movementUpdate();


#endif
