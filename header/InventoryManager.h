#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <string>
#include <queue>

class InventoryManager : public sf::Drawable
{
    private:
        GameObject* _inventoryItem;
        std::queue<std::string> _textLines;
        sf::RectangleShape _inventory;
        sf::RectangleShape _inventory2;
        sf::RectangleShape _inventory3;
        sf::RectangleShape _inventory4;
        sf::Font _font;
        sf::Text _text;

        bool _isFull;
        float _border = 5.0f;
        float _boxMargin = 20.0f;
        float _textMargin = 5.0f;
        void inventoryWithItem();
    public:
        InventoryManager();
        void addItem(GameObject& object);
        void SetText(std::string text, char delimiter);
        void Exit();
        void dropItem(GameObject& object);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        bool getIsInventoryFull();

};

#endif
