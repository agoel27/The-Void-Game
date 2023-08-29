#ifndef INTERACTABLE_H
#define INTERACTABLE_H
#include "GameObject.h"

class Interactable : public GameObject
{
    public:
        enum Type {
            text, //only text, nothing else
            text_inventory, //text, then added to inventory. Only story-based uses
            text_inventory_equipable, //text, then added to inventory. Can be equiped (moved to equipment slot)
            text_inventory_consumable //text, then added to inventory. Can be consumed (destroyed)
        };
        Interactable(sf::Vector2f position, sf::Vector2f scale, std::string texturePath, std::string description, Type type = text, std::string objectName = "");
        std::string GetDescription() {
            return _description;
        }
        Type GetType() {
            return _type;
        }
        std::string GetName() {
            return _objectName;
        }
    private:
        Type _type;
        std::string _description;
        std::string _objectName;
};

#endif