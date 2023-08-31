#include "../header/InventoryManager.h"
#include <sstream>
#include <iostream>
#include<string>
#include "../header/StoryBeats.h"

InventoryManager::InventoryManager()
{
    _inventoryItem = NULL;
    _isFull = false;
    _font.loadFromFile("resources/pixelFont.ttf");
    
    _inventory.setPosition(sf::Vector2f(0 + _boxMargin + 900, 50 + _boxMargin));
    _inventory2.setPosition(sf::Vector2f(0 + _boxMargin + 900, 250 + _boxMargin));
    _inventory3.setPosition(sf::Vector2f(0 + _boxMargin + 900, 50 + _boxMargin));
    _inventory4.setPosition(sf::Vector2f(0 + _boxMargin + 900 + (300 - 2 * _boxMargin), 50 + _boxMargin));
    
    
    _inventory.setSize(sf::Vector2f(300 - 2 * _boxMargin, 50 - 2 * _boxMargin));
    _inventory2.setSize(sf::Vector2f(300 - 2 * _boxMargin, 50 - 2 * _boxMargin));
    _inventory3.setSize(sf::Vector2f(50 - 2 * _boxMargin, 250 - 2 * _boxMargin));
    _inventory4.setSize(sf::Vector2f(50 - 2 * _boxMargin, 250 - 2 * _boxMargin));
    

    _inventory.setFillColor(sf::Color(175, 75, 0));
    _inventory2.setFillColor(sf::Color(175, 75, 0));
    _inventory3.setFillColor(sf::Color(175, 75, 0));
    _inventory4.setFillColor(sf::Color(175, 75, 0));

    if(_border > 0)
    {
        _inventory.setOutlineColor(sf::Color(0, 0, 0));
        _inventory2.setOutlineColor(sf::Color(0, 0, 0));
        _inventory3.setOutlineColor(sf::Color(0, 0, 0));
        _inventory4.setOutlineColor(sf::Color(0, 0, 0));
        _inventory.setOutlineThickness(_border);
        _inventory2.setOutlineThickness(_border);
        _inventory3.setOutlineThickness(_border);
        _inventory4.setOutlineThickness(_border);
    }

}
//Do not
void InventoryManager::SetText(std::string text, char delimiter)
{
    //Clear Queue
    Exit();
    std::string line;
    _textLines.push(line);
}

//Do not need
void InventoryManager::Exit()
{
    while(_textLines.size() > 0)
    {
        _textLines.pop();
    }
}
void InventoryManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(_textLines.size() > 0)
    {
        //we have lines to display
        target.draw(_inventory);
        target.draw(_inventory2);
        target.draw(_inventory3);
        target.draw(_inventory4);
        //target.draw(_text);
    }
}

void InventoryManager::inventoryWithItem()
{
    
    _inventoryItem->SetPosition(0 + _boxMargin + 975, 75 + _boxMargin);
    _inventoryItem->SetScale(4.0f, 4.0f);
    
    
}

void InventoryManager::addItem(GameObject& object)
{
    _inventoryItem = &object;
    _isFull = true;   
    inventoryWithItem();
}

void InventoryManager::dropItem(GameObject& object)
{
    clearFlag(5);
    _isFull = false;
    _inventoryItem->SetPosition(object.GetPosition().x, object.GetPosition().y);
    _inventoryItem->SetScale(1.0f, 1.0f);
}

bool InventoryManager::getIsInventoryFull()
{
    return _isFull;
}
