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

Plot:

A simple adventure game

Group: 122

Member: 3035695189 Wong Wing Kei Member: 3035691195 Mak Ka Ho //

Game description:

We are planning to create a simple adventure game.- There are three difficulty levels in total, "Easy", "Normal", "Hard". Every player gets 100% Strength at the beginning. There will be some challenges for players to solve. The player should choose different decision during each challenge Each decision will bring different outcomes.

// At the beginning of the game, the player will choose from 3 paths, wooden huts and lake. If they choose wooden huts, they will hear a child crying. They can choose comfort him or not. If they choose to comfort her, the child will be happy and give the player a steak. If not, the child will feel annoyed and the players will be deducted 20 cp value If they choose lake, they have to play rock-paper-scissors with a fairy. They need to win the fairy to get a fish. Otherwise, they cannot get anything food from the fairy

After this forked road, the player will have to encounter a wolf. If the player obtains steak in the previous session, they can give the wolf steak. Then they can be safe. Then they have to choose between apple and banana. If they choose apple, they can obtain the key but if they choose the banana, they will not obtain the key and will lose 20 cp value. Then the player will arrive at the castle

When the player has no steak to feed the wolf, they have to choose the ways to defend. If they choose to defend the wolf using stick, their cp value will be reduced by 10. If they choose not to defend , they will lose 30 cp value. After the wolf, they will face the little red riding hood. They can choose to thank the little red riding hood or not. If they choose to do so, they can gain 20 cp value. Otherwise, 20 cp value will be deducted and an apple will fall down from the trees. If the player choose to eat, they can obtain the key but if not, they will still get the key when the apple is broken No matter how the player treat the apple, they can get the key.

Then the player enter the castle. There will be a dog in front of the castle. If the player has the key, he can enter the castle.

After entering the castle, the player will have to face a ghost. The ghost will ask him to choose a number. If the player choose odd number, his cp value will be lowered by 30. If the player choose even number, the ghost will ask the player for making friends. If the player permit, nothing will be lost. If not, the ghost will be angry and 10 cp value will be deducted. No matter how the ghost respond, the player can proceed forward to the room keeping the dog If the player now have the ghost as a friend, he can call the ghost to open the door for him If not, he can also choose to hit the door, but this action will cost a 20 reduction in CP value. Otherwise, if the player choose to give up, he fails and the game will end. If he does not choose to give up, the last task is to remember the dogs name. If he successfully guess the name, he wins the game. Otherwise, he loses the game.

Back to the castle entrance. If he does not have the key, he can choose to play a game to obtain the key. If he choose not to play the game, he loses and the game end. If he choose to play the game, he needs to guess a word If he can guess the word correctly, he can get the key. Otherwise, he will lose the game.

//

Assumption: 

1. The player will not tell lie. There is a scene checking the player whether he/she has steak. He/she should answer according the real situation
2. The player can only quit game once
3. When the player quit game, the game status will be stored in a file. When he comes back, he can continue the game

//

Route: 
1. fork in the road
2. lake / woodhouse
3. wolf
4. monster game
5. castle
6. final mission
(restaurant: for recover CP)
                       
During different scenarios in the game, a few simple games are included:
1. Word and number guessing game (word game will have tips provided to the user to guess)
2. Rock paper scissors
3. Monster game
4. Bingo
5. Blackjack for the final round of the game

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
- print the winning or losing message by reading line from file "winGameMsg.txt" and "endGameMsg.txt"
- there will be files to store the player's game status. 
- after the player come back for the game, he can continue the situation before he leave the game

5. Program code with multiple files
- all the functions are seperated in different files by categories and combined in Makefile

