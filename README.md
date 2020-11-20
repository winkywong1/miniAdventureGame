# miniAdventure
A simple adventure game

Group: 122
- Member: 3035695189 Wong Wing Kei
- Member: 3035691195 Mak Ka Ho

//

Game description:
- We are planning to create a text-based adventure game.
- Every player gets 100 Strength at the beginning.
- The aim is to rescue the dog and there will be lots of challenges and choices have to be made by the player.
- Different Choices may lead to different ending and scenarios.
- The challenges may cost either the increase or the decrease of strength.
- Once the strength of player turns 0, the game will end and the player will lose.

//

Route: 
1. fork in the road
2. lake / woodhouse
3. wolf
4. monster game
5. castle
6. final mission
                       
During different scenarios in the game, a few simple games are included:
1. Word and number guessing game (word game will have tips provided to the user to guess)
2. Rock paper scissors
3. Monster game
4. Blackjack for the final round of the game

//

Win: Passing all the challenges without getting 0 CP 

// 

List of features that we plan to implement:
1. Requirement 1: Generation of random game sets or events
- the rock paper scissors and blackjack played by the computer will generate different results
- player cannot guess the output referring to the last round
- for word-guessing game, there are in total 3 possible words and it will be randomly given to the player to guess 

2. Requirement 2: Data structure for storing game status
- arrays and struct will both be used to store the result and input
- take blackjack as the example:
  - char array is built for storing the cards in hand of both the player and the dealer
  - struct is used for determining all the value of cards, total value of cards and the exact poker holded by the player and dealer
  
3. Requirement 3: Dynamic memory management
- vector, pointer operators are implemented in the game
- vector is used to keep track the items owned by the player
  - things may be appended or removed due to the decision made by the player
  - when the task requires player to have some specific items to pass, searching the vector can check whether the player owns the required items or not
- pointer operators are included in the search of items in bag and blackjack game. 
  - pointer operators are used to access the value at the address available in the pointer variable 
    (pass by reference instead of pass by value)
    
4. Requirement 3: File input/output
- output the result of the game (player's name, success/failure, CP left) to a file "result.txt"

5. Program code with multiple files
- all the functions are seperated in different files by categories and combined in Makefile

