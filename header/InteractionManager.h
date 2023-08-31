#ifndef INTERACTIONMANAGER_H
#define INTERACTIONMANAGER_H
#include "Interactable.h"
#include "TextboxManager.h"
#include "InventoryManager.h"
#include <vector>

class InteractionManager
{
    private:
        std::vector<Interactable>* _interactables;
        //AudioManager _audioManager;
        void Interact(Interactable& Interactable, TextboxManager& textbox);
        void Interact(Interactable& Interactable, InventoryManager& inventoryManager);
        bool _isInventoryOpen;
        Interactable* _interActableToBeAdded;
    public:
        InteractionManager(std::vector<Interactable>& interactables);
        void EventUpdate(sf::Event& e, TextboxManager& textbox);
        void EventUpdate(sf::Event& e, InventoryManager& inventoryManager);
        void setInventoryClosed();
        void setInventoryOpen();
        bool getInventoryCondition();
        Interactable& getInteractableToBeAdded();
};

#endif
