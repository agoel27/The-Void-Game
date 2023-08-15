#include "GameObject.h"

GameObject::GameObject(sf::Vector2f position, sf::Vector2f scale, std::string texturePath) {
    _position = sf::Vector2f(position.x, position.y);
    _scale = sf::Vector2f(scale.x, scale.y);
    SetScale(scale.x, scale.y);
    SetPosition(position.x, position.y);
    _spriteSheet.loadFromFile(texturePath);
    _sprite.setTexture(_spriteSheet);
}

void GameObject::Render(){
    //Update Texture
    _sprite.setTexture(_spriteSheet);
    //player.setTextureRect(sf::IntRect(State*player_sheet.getSize().y,0,player_sheet.getSize().y,player_sheet.getSize().y)); //SpriteSheet
    
    //Update transforms
    _sprite.setScale(_scale);
    _sprite.setPosition(_position);
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite);
}