#ifndef INTERACTIONMANAGER_H
#define INTERACTIONMANAGER_H
#include "Interactable.h"
#include "TextboxManager.h"
#include <vector>

class InteractionManager
{
    private:
        std::vector<Interactable>* _interactables;
        //AudioManager _audioManager;
        void Interact(Interactable& Interactable, TextboxManager& textbox);
    public:
        InteractionManager(std::vector<Interactable>& interactables);
        ~InteractionManager();
        void EventUpdate(sf::Event& e, TextboxManager& textbox);

};

#endif