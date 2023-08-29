#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject : public sf::Drawable
{
    private:
        sf::Sprite _sprite;
        sf::Vector2f _position;
        sf::Vector2f _scale;
        sf::Texture _spriteSheet;
        sf::IntRect _textureRect;
        sf::FloatRect _colliderRectOffset;
        bool _collides;
        bool _pushable;
    public:
        sf::Vector2f GetScale() const{
            return _scale;
        }
        void SetScale(float x, float y){
            _scale.x = x;
            _scale.y = y;
            }
        sf::Vector2f GetPosition() const{
            return _position;
        }
        void SetPosition(float x, float y){
            _position.x = x;
            _position.y = y;
            }
        void AddPosition(float x, float y){
            _position.x += x;
            _position.y += y;
            }
        sf::FloatRect GetSpriteRect() const{
            return _sprite.getGlobalBounds();
        }
        sf::FloatRect GetCollisionRect() const;
        void setCollides(bool newVal){
            _collides = newVal;
        }
        bool Collides(){
            return _collides;
        }
        void setPushable(bool newVal){
            _pushable = newVal;
        }
        bool Pushable(){
            return _pushable;
        }
        void SetTextureRect(float left, float top, float height, float width);
        void SetColliderRect(float left, float top, float bottom, float right);
        GameObject(sf::Vector2f position, sf::Vector2f scale, std::string texturePath);
        GameObject(sf::Vector2f position, sf::Vector2f scale, std::string texturePath, bool collides, bool pushable);
        void Render();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
#endif