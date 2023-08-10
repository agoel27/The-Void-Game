[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=11529694&assignment_repo_type=AssignmentRepo)
 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# The Void Game
 > Your author list below should include links to all members GitHub (remove existing author).
 
 > Authors: [Ivan Marozau](https://github.com/MatterCollapse),[Aryan Goel](https://github.com/agoel27),[Angel Hernandez](https://github.com/ahern650),[Jacob Rozenkrants](https://github.com/jar04)

 > You will be forming a group of **FOUR** students and working on an interesting project. The project has 4 phases, each one with specific requirements. A list of proposed project ideas that have been successful in previous quarters is listed in the project specifications document on Canvas. You can select an idea from the list and start thinking about the features you will implement. If you want to propose your own original idea, you will have to contact your instructor to discuss the project and obtain written permission before you submit your project proposal (Phase 1). The project work should be divided almost equally among team members. You can of course help each other, but it needs to be clear who will be responsible for which features. Additionally, you are expected to follow Scrum patterns, specifically the use of a Scrum (Project) board, Sprints, and Scrum meetings.

 > ## Expectations
 > * The backend of your project should be implemented in C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 > * **Each member of the group must actively participate in the Github Project board, writing unit tests, and reviewing commited code.**
> * All project phases are to be submitted to this GitHub repository. You should modify this README file to reflect the different phases of the project. In addition, you should regularly hold sprint meetings with your group. You will need to hold two to three scrum/check-in meetings with your lab TA/reader at different times in addition to the final demo.

## Project Description
 ### Why is it important or interesting to you?
 > I've always felt a sense of excitement playing decision-based games that involve exploring different paths and seeing how my choices shape outcomes. Turning gaming into a real adventure gets me pumped to create a project with meaningful choices and their impact on players.
 ### What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
SFML Library for C++
 ### What will be the input/output of your project?
 Input
 > * User movement with arrow keys 
 > * Interaction with environment - Picking up objects, Using objects
 > * Menu - Inventory, Equipable Items, Main Menu
 > * Save Method?
 > 
Output
 > * Textbox Narration - Tells player objective and story/guides player
 > * Game changes according to the player’s decisions
 > * Beginning room, character sprites, music(?), sprite for objects in the room, animation(?) for moving objects
 ### What are the features that the project provides? This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted.
 > 
Controls
 > * Movement keys move player
 > * Interact button searches for nearest interactable and triggers it
 > * Enter key/Spacebar/click on screen moves textbox text along or closes textbox
 > * Push/pull objects(?)
 > 
Visuals
 > * SFML will render sprites to a windows application
 > * Rudimentary 2-frame animations will scroll through a sprite sheet for each movement direction + stationary
 > * Royalty Free sprites
 > 
Audio(?)
 > * Two tracks of music, a during game and a win game
 > * Button interaction sound effects
 > 
Interactables
 > * Objects that populate the narration box when interacted with
 > * Objects that add themselves to your inventory when interacted with
 > 
UI
 > * Before game starts
 > * Ask for player name
 > * Ask for player’s favorite beverage that they drink in the morning
 > * Choose ⅓ sprites designs (male, female, androgynus)
 > * Narration box that can have text sent to it and expands/shrinks to contain it. If there is too much text, player input can move it along. 
 > * Inventory/hotbar that has your items
 > * Equipable Items character menu - could change character sprite appearance?
 > * Quit game button
 > 

 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
![Navigation Diagram](https://github.com/cs100/final-project-thevoidgame/blob/master/NavigationDiagram.png?raw=true)
This Navigation Diagram represents a high-level visual overview of the user's journey within the game interface. It outlines the sequence of interactions and steps that players will follow to transition between screens and progress through the game. The green boxes correspond to distinct screen views. The connecting arrows and labels correspond to specific user actions or events that trigger the transition between screens.

### Screen Layouts
![Layout Diagram](https://github.com/cs100/final-project-thevoidgame/blob/master/ProjectDiagram.png?raw=true)

## Class Diagram
![Class Diagram](https://github.com/cs100/final-project-thevoidgame/blob/master/ClassDiagram.png?raw=true)
All classes with an update function depend on main, it is in charge of running the update loop
Gameobjects contain all the information necessary to render themselves to the screen, main calls these renders at the end of update.
The general flow is that main instantiates all gameobjects, interactables, and managers in the game and enters an update loop until the game is closed. 
The interaction manager handles interactables and populates the textbox based on the interactable and story beats
Buttons for the main menu will most likely also be handled by main. 
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
