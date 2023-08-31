[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=11529694&assignment_repo_type=AssignmentRepo)
 
# The Void Game
 
Authors: [Ivan Marozau](https://github.com/MatterCollapse),[Aryan Goel](https://github.com/agoel27),[Angel Hernandez](https://github.com/ahern650),[Jacob Rozenkrants](https://github.com/jar04)

## Project Description
### Why is it important or interesting to you?
* We have always felt a sense of excitement playing decision-based games that involve exploring different paths and seeing how our choices shape outcomes. Turning gaming into a real adventure gets us pumped to create a project with meaningful choices and their impact on players.
### What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
* SFML Library for C++
### What will be the input/output of your project?
Input
* Player movement with 'WASD' keys 
* Interaction with environment - Picking up items with 'E' key, Clicking on items to interact
* Menu - Start Screen Menu and Inventory Menu
  
Output
* Textbox Narration - Tells player objective and story + guides player
* Game Screens
* Character and Item Sprites
* Animation for moving items

### What are the features that the project provides? This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted.
Controls
* 'WASD' keys move player
* 'E' key picks up items
* Clicking objects iteracts with items
* Enter key or Spacebar advances Textbox text or closes Textbox

Visuals
* SFML renders graphics and sprites to the game window
* 2-frame animations will scroll through a sprite sheet for each movement direction + stationary

Interactables/Game Objects
* Item that populates the narration box when player clicks on item
* Item that adds to the inventory when player presses 'E' key near item
* Item that is pushable through character collision

UI
* Title screen advances when Enter key is pressed
* Text Field input for player name and favorite beverage on start screen menu
* Button input - Choose 1/2 sprite designs (male, female) on start screen menu
* Button input - Submit Button advances start screen menu
* Textbox that can have text sent to it
* Inventory that has contains items

## Naming Convention
Class Name 
* Is a noun
* Starts with uppercase letter
* Follows CamelCase
* No underscores

Variable Name
* Contextually describes its value
* Follows camelCase
* Underscores only for prefixes (such as p_ for pointer)
* Digits allowed but not as first letter
* Pointer variables place the ‘*’ near the variable name and not data type
* Constants should be all uppercase and separated by underscores

Function Name
* Contextually describes its function
* Begins with a verb
* Follows camelCase

File Name
* Follows camelCase

## User Interface Specification
Includes a navigation diagram for our screens and the layout of each of those screens

### Navigation Diagram
![Navigation Diagram](https://github.com/cs100/final-project-thevoidgame/blob/master/NavigationDiagram.png?raw=true)
* This Navigation Diagram represents a high-level visual overview of the user's journey within the game interface. It outlines the sequence of interactions and steps that players will follow to transition between screens and progress through the game. The green boxes correspond to distinct screen views. The connecting arrows and labels correspond to specific user actions or events that trigger the transition between screens.

### Screen Layouts
![Layout Diagram](https://github.com/cs100/final-project-thevoidgame/blob/master/ProjectDiagram.png?raw=true)

## Class Diagram
![Class Diagram](https://github.com/cs100/final-project-thevoidgame/blob/master/ClassDiagram.png?raw=true)
* Screen Manager has the main function that contains the game loop which handles which screens to draw and process
* Each screen class depends on the GameObject, Interactables, UI, and Manager classes to draw graphic elements and process player input
* Story Beats class contains game flags that set or clear based on progression on player through the game
* Interaction Manager class handles interactables and populates the textbox based on the interactable and story beats

### Class Diagram Updates
* Originally the Screen Manager handled which screens to draw, drawing all screens, and processesing all screens.
* In accordance with the Single Responsibility Principle, Screen Manager now only handles which screens to draw and process in its game loop. 
* It does not hold all the keybinds and it does not create gameobjects. There are classes responsible just for the objects on their screen. 
* Now Screen Manager will not be bogged down by large blocks of gameobject instantiation. 
 
## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
## Screenshots
 > Screenshots of the input/output after running your application
 ![Title Screen](https://github.com/cs100/final-project-thevoidgame/blob/master/titleScreen.png?raw=true)
 ![Start Screen](https://github.com/cs100/final-project-thevoidgame/blob/master/startScreen.png?raw=true)
 ![Inventory](https://github.com/cs100/final-project-thevoidgame/blob/master/inventory.png?raw=true)
 ![Key](https://github.com/cs100/final-project-thevoidgame/blob/master/key.png?raw=true)
 ![Key Grabbed](https://github.com/cs100/final-project-thevoidgame/blob/master/keyGrabbed.png?raw=true)
 ![Outside](https://github.com/cs100/final-project-thevoidgame/blob/master/outside.png?raw=true)
 ![Room](https://github.com/cs100/final-project-thevoidgame/blob/master/room.png?raw=true)
 ![Textbox](https://github.com/cs100/final-project-thevoidgame/blob/master/textbox.png?raw=true)
## Installation/Usage
 > The Github contains a compressed Build file. Once extracted, the EXE inside runs the game
## Testing
 > The project was Alpha tested by each member. It was run repeatedly with varying inputs to test visual rendering, collision, input handling, menu transitions, animation, and dialogue
 
