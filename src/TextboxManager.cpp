#include "../header/TextboxManager.h"
#include <sstream>
#include <iostream>

TextboxManager::TextboxManager()
{
    _font.loadFromFile("resources/pixelFont.ttf");
    _text.setFont(_font);
    _continueText.setFont(_font);
    _continueText.setString("Press Enter/Space to continue");

    _textbox.setSize(sf::Vector2f(1200 - 2 * _boxMargin, 125));

    _textbox.setPosition(sf::Vector2f(_boxMargin, 800 - _textbox.getSize().y - _boxMargin));
    _text.setPosition(sf::Vector2f(_boxMargin + _textMargin, _textbox.getPosition().y));
    _continueText.setPosition(sf::Vector2f(1200 - _boxMargin - _textMargin - _continueText.getGlobalBounds().width, 800 - _boxMargin - _textMargin - _continueText.getGlobalBounds().height));

    _textbox.setFillColor(sf::Color(0, 0, 0));
    _text.setFillColor(sf::Color(255, 255, 255));
    _continueText.setFillColor(sf::Color::White);

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
        target.draw(_continueText);
    }
}