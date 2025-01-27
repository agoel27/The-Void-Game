#include "../header/InteractionManager.h"
#include <iostream>
#include "../header/StoryBeats.h"

InteractionManager::InteractionManager(std::vector<Interactable>& interactables)
{
    _interactables = &interactables;
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
                    if(iter->GetName() == "door" && hasFlag(5)) {
                        iter->SetDescription("It's unlocked");
                        iter->SetTextureRect(11*32, 8*32, 2*32, 32);
                        clearFlag(2);
                        setFlag(6);
                    }
                    if((iter->GetName() == "outsideDoor") && hasFlag(5)) {
                        clearFlag(6);
                        setFlag(2);
                    }
                    
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

void InteractionManager::EventUpdate(sf::Event& event, InventoryManager& inventoryManager)
{
    if(_interactables != nullptr && event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Right)
        {
            setInventoryOpen();
            for(auto iter = _interactables->end()-1; iter != _interactables->begin()-1; iter--)
            {
                sf::FloatRect rect = iter->GetSpriteRect();
                if(event.mouseButton.x >= rect.left && event.mouseButton.x <= rect.left + rect.width
                && event.mouseButton.y >= rect.top && event.mouseButton.y <= rect.top + rect.height)
                {

                    std::cout << "Using inventory " << std::endl;
                    Interact(*iter, inventoryManager);
                    return;
                }
            }
        }
    }
}


void InteractionManager::Interact(Interactable& Interactable, InventoryManager& inventoryManager)
{
    if(Interactable.GetName() == "key") {
        setFlag(5);
    }
    _interActableToBeAdded = &Interactable;
    inventoryManager.SetText(Interactable.GetDescription(), '\n');
}


void InteractionManager::setInventoryClosed()
{
    _isInventoryOpen = false;
}
void InteractionManager::setInventoryOpen()
{
    _isInventoryOpen = true;
}
bool InteractionManager::getInventoryCondition()
{
    return _isInventoryOpen;
}

Interactable& InteractionManager::getInteractableToBeAdded()
{
    return *_interActableToBeAdded;
}
