#include "../header/Interactable.h"

Interactable::Interactable(sf::Vector2f position, sf::Vector2f scale, std::string texturePath, std::string description, Type type, std::string objectName) : GameObject(position, scale, texturePath)
{
    _description = description;
    _type = type;
    _objectName = objectName;
}

Interactable::Interactable(sf::Vector2f position, sf::Vector2f scale, std::string texturePath, std::string description, Type type, bool collides, bool pushable, std::string objectName) : GameObject(position, scale, texturePath, collides, pushable)
{
    _description = description;
    _type = type;
    _objectName = objectName;
}