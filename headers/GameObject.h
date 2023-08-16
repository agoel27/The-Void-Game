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
    public:
        sf::Vector2f GetScale(){
            return _scale;
        }
        void SetScale(float x, float y){
            _scale.x = x;
            _scale.y = y;
            }
        sf::Vector2f GetPosition(){
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
        void SetTextureRect(float left, float top, float height, float width);
        GameObject(sf::Vector2f position, sf::Vector2f scale, std::string texturePath);
        void Render();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
#endif