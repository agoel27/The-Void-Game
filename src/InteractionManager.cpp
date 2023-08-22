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
void InteractionManager::EventUpdate(sf::Event& event, TextboxManager& textbox)
{
    if(_interactables != nullptr && event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            for(auto iter = _interactables->end()-1; iter != _interactables->begin()-1; iter--)
            {
                sf::FloatRect rect = iter->GetSpriteRect();
                if(event.mouseButton.x >= rect.left && event.mouseButton.x <= rect.left + rect.width
                && event.mouseButton.y >= rect.top && event.mouseButton.y <= rect.top + rect.height)
                {
                    std::cout << "Interacting with " << iter->GetDescription() << std::endl;
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