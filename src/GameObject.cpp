#include "../header/GameObject.h"

GameObject::GameObject(sf::Vector2f position, sf::Vector2f scale, std::string texturePath) {
    _position = sf::Vector2f(position.x, position.y);
    _scale = sf::Vector2f(scale.x, scale.y);
    SetScale(scale.x, scale.y);
    SetPosition(position.x, position.y);
    _spriteSheet.loadFromFile(texturePath);
    _sprite.setTexture(_spriteSheet);
    _collides = true;
    _pushable = false;
}

GameObject::GameObject(sf::Vector2f position, sf::Vector2f scale, std::string texturePath, bool collides, bool pushable) {
    _position = sf::Vector2f(position.x, position.y);
    _scale = sf::Vector2f(scale.x, scale.y);
    SetScale(scale.x, scale.y);
    SetPosition(position.x, position.y);
    _spriteSheet.loadFromFile(texturePath);
    _sprite.setTexture(_spriteSheet);
    _collides = collides;
    _pushable = pushable;
}

sf::FloatRect GameObject::GetCollisionRect() const{
    sf::FloatRect spriteRect = GetSpriteRect();
    return sf::FloatRect(spriteRect.left + _colliderRectOffset.left,
    spriteRect.top + _colliderRectOffset.top,
    spriteRect.width - _colliderRectOffset.width - _colliderRectOffset.left,
    spriteRect.height - _colliderRectOffset.height - _colliderRectOffset.top);
}
void GameObject::SetTextureRect(float left, float top, float height, float width){
    _textureRect.left = left;
    _textureRect.top = top;
    _textureRect.height = height;
    _textureRect.width = width;
    _sprite.setTextureRect(_textureRect);
}
void GameObject::SetColliderRect(float left, float top, float bottom, float right){
    _colliderRectOffset.left = left;
    _colliderRectOffset.top = top;
    _colliderRectOffset.height = bottom;
    _colliderRectOffset.width = right;
}

void GameObject::Render(){
    //Update Texture
    _sprite.setTexture(_spriteSheet);
    //player.setTextureRect(sf::IntRect(State*player_sheet.getSize().y,0,player_sheet.getSize().y,player_sheet.getSize().y)); //SpriteSheet
    
    //Update transforms
    _sprite.setScale(_scale);
    _sprite.setPosition(_position);

    _textureRect.left = 0;
    _textureRect.top = 0;
    _textureRect.width = _spriteSheet.getSize().x;
    _textureRect.height = _spriteSheet.getSize().y;
}

void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // Debug Code, display collider bounds
    //sf::RectangleShape rectangle;
    //rectangle.setFillColor(sf::Color(255,255,255));
    //rectangle.setPosition(sf::Vector2f(GetCollisionRect().left, GetCollisionRect().top));
    //rectangle.setSize(sf::Vector2f(GetCollisionRect().width, GetCollisionRect().height));
    //target.draw(rectangle);
    target.draw(_sprite);
}