// header file for insideHouseScreen.cpp
#ifndef OUTSIDESCREEN_H
#define OUTSIDESCREEN_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Interactable.h"
#include "TextboxManager.h"
#include "InteractionManager.h"
#include <stdlib.h>
#include <vector>

void setupOutsideHouse(sf::RenderWindow&);
void processOutsideHouseInput(sf::RenderWindow&, sf::Event&);
void drawOutsideHouse(sf::RenderWindow&);
void outsideHouseEventUpdate(sf::Event& e);
void outsideHouseUpdate();
void outsideMovementUpdate();


#endif
