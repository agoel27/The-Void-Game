#include "TextboxManager.h"
#include <sstream>
#include <iostream>

TextboxManager::TextboxManager()
{
    _font.loadFromFile("../resources/pixelFont.ttf");
    _text.setFont(_font);

    _textbox.setSize(sf::Vector2f(800 - 2 * _boxMargin, 400 - 2 * _boxMargin));

    _textbox.setPosition(sf::Vector2f(0 + _boxMargin + 250, 400 + _boxMargin));
    _text.setPosition(sf::Vector2f(0 + _boxMargin + _textMargin + 250, 400 + _boxMargin + _textMargin));

    _textbox.setFillColor(sf::Color(0, 0, 0));
    _text.setFillColor(sf::Color(255, 255, 255));

    if(_border > 0)
    {
        _textbox.setOutlineColor(sf::Color(255, 255, 255));
        _textbox.setOutlineThickness(_border);
    }
}
void TextboxManager::SetText(std::string text, char delimiter)
{
    //Clear Queue
    while(_textLines.size() > 0)
    {
        _textLines.pop();
    }

    //divide text into _textLines using delimiter
    std::stringstream sstream(text);
    std::string line;
    while(std::getline(sstream, line, delimiter))
    {
        _textLines.push(line);
    }
}
void TextboxManager::Next()
{
    if(_textLines.size() > 0)
    {
        _textLines.pop();
    }
}
void TextboxManager::Render()
{
    if(_textLines.size() > 0)
    {
        _text.setString(_textLines.front());  
    }
}
void TextboxManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(_textLines.size() > 0)
    {
        //we have lines to display
        target.draw(_textbox);
        target.draw(_text);
    }
}