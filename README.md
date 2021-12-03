# COMP2113 Project: Typing Game
Minjae Jo 3035742712
Jong Seung Lee 3035555547
  
**Typing Game Brief Description**
   - The game is aimed to improve the typing speed for the random words.

**Rules**
   1. User first select numbers of word for the session. 
   2. "User can also choose numbers of word to challenge. (10, 20, 30 words)" << endl;
   3. Then "User has to type a given word maintaining at least 70% accuracy." << endl;
	cout << "All inputs Are case sensitive." << endl;
	cout << "User can also view their cumulative record. (can be reset)" << endl;
	cout << "Please enjoy and type 'e' and enter key to exit" << endl;


**Requirements**
1. Generation of Random game sets or events:
   - Random words are extracted from the input.txt file to be tested by the user.

2. Data structure for storing game status:
   - Selection of difficulty (# of words to be tested in given amount of time)
   - Recording user's accuracy rate, average typing speed per minute, and time taken per input

3. Dynamic memory management:
   - Used vector as dynamic memory structure to store all words

4. File I/O:
   - File input of the word text file
   - Output textfile to append game results of totalword, correctword, and totaltime

5. Program codes in multiple files:
   - Two .cpp files and a header file is made

6. Proper indentation and naming styles, and In-code documentation:
   - All presented inside the code files

**Code Features**
Input
   - File Input
     - Dictionary including words
     - Previous User Result
       - Highest Accuracy
       - Highest Speed
   - User Input for searching words
     - Player has to specify level (three different levels: hard, medium, easy)
     - Input Format : "startgame #length

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
     - Score function output if the user  ""
   - Output to File
     - Overwrite accuracy and speed if it is higher than the value stored in the file.

Game Termination Conditions
   - Must type each character correctly. If user fail to maintain certain level of accuracy will lose.
   - Exit the session if user type '5' after session ends.

**How to run**
   - Put all files in same directory then open cmd then type these two commands.
     - g++ -pedantic-errors -std=c++11 main.cpp gamefunc.cpp -o main
     - ./main
