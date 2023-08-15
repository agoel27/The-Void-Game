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
    public:
        void SetScale(float x, float y){
            _scale.x = x;
            _scale.y = y;
            }
        void SetPosition(float x, float y){
            _position.x = x;
            _position.y = y;
            }
        void AddPosition(float x, float y){
            _position.x += x;
            _position.y += y;
            }
        GameObject(sf::Vector2f position, sf::Vector2f scale, std::string texturePath);
        void Render();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};
#endif