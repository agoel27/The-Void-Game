/*
    header file for StoryBeats.cpp
    defines flags for the game
*/ 
#ifndef STORY_BEATS_H
#define STORY_BEATS_H

// Define flags using macros
#define ENTER_TITLE_SCREEN 0
#define ENTER_START_SCREEN 1
#define ENTER_INSIDE_HOUSE 2
#define KEY_COLLECTED 3
#define ENTER_OUTSIDE_HOUSE 4
// ... define the next flag in increasing order
// ex: #define ENTER_GAME 4
// ex: #define BEVERAGE_COLLECTED 5
// ex: #define KEY_COLLECTED 6

void setFlag(int flag);
void clearFlag(int flag);
bool hasFlag(int flag);

#endif
