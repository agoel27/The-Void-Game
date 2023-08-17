#include "InteractionManager.h"
#include <iostream>

InteractionManager::InteractionManager(std::vector<Interactable>& interactables)
{
    _interactables = &interactables;
}
InteractionManager::~InteractionManager()
{
    delete _interactables;
}
void InteractionManager::EventUpdate(sf::Event& e, TextboxManager& textbox)
{
    if(_interactables != nullptr && e.type == sf::Event::MouseButtonPressed)
    {
        if (e.mouseButton.button == sf::Mouse::Left)
        {
            for(auto iter = _interactables->begin(); iter != _interactables->end(); iter++)
            {
                sf::FloatRect rect = iter->GetSpriteRect();
                if(e.mouseButton.x >= rect.left && e.mouseButton.x <= rect.left + rect.width
                && e.mouseButton.y >= rect.top && e.mouseButton.y <= rect.top + rect.height)
                {
                    Interact(*iter, textbox);

                    return;
                }
            }
        }
    }
}
void InteractionManager::Interact(Interactable& Interactable, TextboxManager& textbox)
{
    textbox.SetText(Interactable.GetDescription(), '\n');
}