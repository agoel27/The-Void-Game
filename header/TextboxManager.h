#ifndef TEXTBOXMANAGER_H
#define TEXTBOXMANAGER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <queue>

class TextboxManager : public sf::Drawable
{
    private:
        std::queue<std::string> _textLines;
        sf::RectangleShape _textbox;
        sf::Font _font;
        sf::Text _text;
        float _border = 5.0f;
        float _boxMargin = 20.0f;
        float _textMargin = 20.0f;
    public:
        TextboxManager();
        void SetText(std::string text, char delimiter);
        void Next();
        void Render();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif