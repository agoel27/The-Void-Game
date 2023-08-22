#include "../header/Interactable.h"

Interactable::Interactable(sf::Vector2f position, sf::Vector2f scale, std::string texturePath, std::string description, Type type) : GameObject(position, scale, texturePath)
{
    _description = description;
    _type = type;
}