# comp2113project
Minjae Jo 3035742712
Jong Seung Lee 3035555547
  
Typing game

**Brief Description**
   - The game is aimed to improve the typing speed for the random words and the reaction speed.


**Rules**

Input
   - File Input
     - Dictionary including words
     - Previous Scores
       - Highest Score for one session
       - Higest Accuracy
       - Higest Speed
   - User Input for searching words
     - Player might input a integer for the length of the string that user has to type. (If the user types 5, the string that the user has to type would be e.g.) apple)
     - Player might input speicific alphabets (e.g.) 'a', 'b', 'c' and so on)
     - Player also have to specify level (three different levels: hard, medium, easy)
     - Input Format : "startgame #level #length #alphabets"


Data Structure/Functions
  - Data structure recording the highest score or correct-streak
     - Store value as in array or class-set up
  - Function for calculation of the score, accuracy(simple calculation), typing speed (by <ctime> library).
  - Function to display highest typing scores if user type 'userscore'
  - Function for termination condition - time limit adjustment for difficulties
      - On a scale of 1 to 3 (hard, medium, easy), user would have different time limits.

  
Output
   - Output within a program
     - Words for the game
     - Score display after the termination of eaach session
     - Score function output if the user typed "userscore"
   - Output to File
     - Score highest scores, accuracy, and speed if it is higher than the value stored in the file.

  
Game Termination Conditions
   - Must type each character correctly. If user fail to maintain certain level of accuracy will lose.
   - Must follow the time limit or will lose.
   - Exit the session if user type 'q' after the game.
  

Restriction
* cannot use any library that needs to be downloaded from internet.
* need to be complied to academy server - test with X2go.
