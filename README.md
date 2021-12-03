# COMP2113 Project: Typing Game
Minjae Jo 3035742712
Jong Seung Lee 3035555547
  
**Typing Game Brief Description**

   - The game is aimed to improve the typing speed for the random words.

**Rules**

   1. User first select numbers of word for the session (10 or 20 or 30 words)
   2. Then each word will show up on the screen, user has to type a given word maintaining at least 70% accuracy - all inputs are case-sensitive
   3. If the user fails, then it's game over
   4. Else, the game will end if the user finishes all the entries of the word
   5. For each entries and end of the game session, accuracy, typing speed and time taken will be shown 

**Requirements**
1. Generation of Random game sets or events:
   - Random words are extracted from the input.txt file to be tested by the user
2. Data structure for storing game status:
   - Selection of difficulty (# of words to be tested in given amount of time)
   - Recording user's accuracy rate, average typing character speed per minute, and time taken per input
3. Dynamic memory management:
   - Used vector as dynamic memory structure to store all words from input.txt file
4. File I/O:
   - File input of the word text file
   - Output textfile to append game results of totalword, correctword, and totaltime
5. Program codes in multiple files:
   - Two .cpp files and a header file is made
6. Proper indentation and naming styles, and In-code documentation:
   - All presented inside the code files

**How to run**
   - Put all files in same directory then open cmd then type these two commands.
     - g++ -pedantic-errors -std=c++11 main.cpp gamefunc.cpp -o main
     - ./main

**Demonstration Video**
1. Running game with 10 words and able to maintain accuracy over 70% until end of the game
2. Running game with 20 words and unable to maintain accuracy over 70% until end of the game so game over
3. Loading instruction
4. Loading saved accumulative record for the past sessions.
5. Loading deleting saved record function and not decide it to delete past record 
6. Loading deleting saved record function and decide it to delete past record, verifying the deletion with saved record function
7. Exiting program
