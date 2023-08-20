/*
    header file for StoryBeats.cpp
    defines flags for the game
*/ 
#ifndef STORY_BEATS_H
#define STORY_BEATS_H

// Define flags using macros
#define ENTER_START_SCREEN 0
#define ENTER_INSIDE_HOUSE 1
// ... define the next flag in increasing order
// ex: #define ENTER_GAME 1
// ex: #define BEVERAGE_COLLECTED 2
// ex: #define KEY_COLLECTED 3

void setFlag(int flag);
void clearFlag(int flag);
bool hasFlag(int flag);

#endif
