#include <iostream>
#include "../header/StoryBeats.h"

/*
    Implementation of flag-related functions
    NOTE: Add a {false} to the flags[] list if you added a flag in StoryBeats.h
*/

// array to store flag values
bool gameFlags[] = {false, false, false, false, false}; // Initialize all flags as false

/*
    This function sets a flag in the game to true

    Input:  flag - indicates which flag it refers to  
    Output: sets appropriate flag to true 
*/
void setFlag(int flag)
{
    if (flag >= 0 && flag < sizeof(gameFlags) / sizeof(gameFlags[0])) {
        gameFlags[flag] = true;
        std::cout << "flag " << flag << " set" << std::endl;
    }
    else {
        std::cout << "flag " << flag << " does not exist" << std::endl;
    }
}

/*
    This function sets a flag in the game to false

    Input:  flag - indicates which flag it refers to  
    Output: sets appropriate flag to false 
*/
void clearFlag(int flag)
{
    if (flag >= 0 && flag < sizeof(gameFlags) / sizeof(gameFlags[0])) {
        gameFlags[flag] = false;
        std::cout << "flag " << flag << " cleared" << std::endl;
    }
    else {
        std::cout << "flag " << flag << " does not exist" << std::endl;
    }
}

/*
    This function returns the value of a flag in the game

    Input:  flag - indicates which flag it refers to  
    Output: true if flag is set 
            false if flag is not set/cleared
*/
bool hasFlag(int flag)
{
    if (flag >= 0 && flag < sizeof(gameFlags) / sizeof(gameFlags[0])) {
        return gameFlags[flag];
    }
    std::cout << "flag " << flag << " does not exist" << std::endl;
    return false;
}
