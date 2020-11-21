#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "castle.h"
#include "finalStage.h"
#include "show.h"
#include "winGame.h"
#include "endGame.h"
#include "bingo.h"
#include "stat.h"
using namespace std;

// show that the player reach a locked door
// ask the player to choose between 3 choices:
// 1.ask help from the ghost
// 2.directly break into the room
// 3.give up
// If the player chooses option 1, he/she will be checked whether the ghost is his/her friend
// If not his/her friend, the player is not able to choose option one
// If the ghost is his/her friend, the player will be brought to the final stage
// If the player chooses option 2, he/she will decrease in CP value in exchange
// If the player chooses option 3, he/she will directly end the game and considered as a loser
void castleDoor() {
    show();
    cout << endl;
    char word[] = "You search room by room and you finally reach the last room. \n"
        "Your dog probably is locked in this room but you cannot go in there.";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    cout << endl;
    char op[] = "You now have three options: \n"
        "1. ask the ghost for help if she is your accompany \n"
        "2. break into the room \n"
        "3. feel frustrated and give up to save your dog \n";
    for (int j = 0; j < sizeof(op); j++) {
        cout << op[j];
        usleep(3000);
    }
    bool haveG;
    vector<string>::iterator find;
    for (find = bag.begin(); find != bag.end(); find++) {
        if (*find == "ghost") 
            haveG = true;
        else
            haveG = false;
    }

    cout << endl << "You will choose option 1, 2 or 3? (1 / 2 / 3)" << endl;
    int option;
    cin >> option;
    while (option != 1 && option != 2 && option != 3) {
        cout << "Invalid Input! Please answer again.\n";
        cout << "You will choose option 1, 2 or 3? (1 / 2 / 3)";
        cin >> option;
    }
    if (option == 1 && haveG) {
        cout << "The ghost passes through the wall and unlocks the door inside the room." << endl;
        cout << "You can finally get in." << endl;
        cout << "Your dog is excited about seeing you and you reach the last challenge." << endl;
        finalStage();
    }
    while (option == 1 && !haveG) {
        cout << "You are not staying with the ghost so you can't choose option 1.\n";
        cout << "Please choose option 2 or 3. Will you choose 2 or 3? (2 / 3)\n";
        cin >> option;
    }
    if (option == 2) {
        cout << "You use your body to hit the body until it opens." << endl;
        cout << "You successfully open the door but you are hurt during the calBackjack." << endl;
        cout << "Your CP is decreased by 20." << endl;
        life -= 20;
        cout << "However, you finally see your dog! You reach the last challenge." << endl;
        if (life <= 0) {
            if (chance == 0)
                bingo();
        }
        else
            finalStage();
    }
    if (option == 3) {
        cout << "You give up saving your dog." << endl;
        cout << "You hear he is crying but you turn and leave the castle." << endl;
        endGame();
    }
    sleep(2);
}


// allow the player to choose if he/she makes friend with the ghost
// If the player choose yes, ghost will follow him/her
// If the player choose no, the player will face a reduction in CP value by 10
void withGhost() {
    cout << "Will you invite her to join your adventure? (y: yes / n: no)" << endl;
    char answer;
    cin >> answer;
    cout << endl;
    while (answer != 'y' && answer != 'n') {
        cout << "Invalid Input! Please answer again.\n";
        cout << "Your response: (y: yes / n: no) ";
        cin >> answer;
    }
    if (answer == 'y') {
        cout << "You ask for help from the ghost and she is glad for your invitation." << endl;
        cout << "You two become accompany and continue the journey together." << endl;
        bag.push_back("ghost");
    }
    if (answer == 'n') {
        cout << "The ghost thinks you just act like the other people abandoning her." << endl;
        cout << "She is angry so she slaps your right on your face and rans away." << endl << endl;
        life -= 10;
        cout << "Your CP is decreased by 10. It is very close to save your dog!" << endl;
    }
    if (life <= 0) {
        if (chance == 0) {
            bingo();
        }
        else {
            cout << "You have used your one and only one chance to go to the restaurant." << endl;
            endGame();
        }
    }
}


// allow the player to guess a number
// If the player guess an even number, the ghost will ask the player to be friend or not (withGhost)
// Otherwise, decrease the player 30 in CP value
void castleGhost() {
    cout << endl;
    char word[] = "The ghost said, \"I am so bored. I want you to play a game with me.\" \n"
        "\"How about you choose a number between 1 and 10? \" \n"
        "You have no choice and you have to play with her. \n";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }

    int guessNum;
    cout << "Please choose a number (1 - 10): " << endl;
    cin >> guessNum;
    cout << endl;
    if (guessNum % 2 == 0) {
        char even[] = "The ghost said, \"I love even number! Everything is so perfect when it is even.\" \n";
        for (int j = 0; j < sizeof(even); j++) {
            cout << even[j];
            usleep(3000);
        }
        cout << endl << "The ghost is happy and satisfied. You feel sad for her for being alone all the time." << endl;
        withGhost();
    }
    else if (guessNum % 2 != 0) {
        char odd[] = "The ghost said, \"I hate odd number!!! I hate to be alone!!!\" \n"
            "\"Why everybody left me here and escape from me by all mean.\" \n" 
            "\"I hate you!!!!!!\"";
        for (int k = 0; k < sizeof(odd); k++) {
            cout << odd[k];
            usleep(3000);
        }
        cout << endl << "The ghost is furious and she attacks you." << endl;
        cout << "You cannot see that happened and you get hurt seriously." << endl;
        cout << endl;
        life -= 30;
        cout << "Your CP is decreased by 30. It is very close to save your dog!" << endl;
        if (life <= 0) {
            if (chance == 0) {
                bingo();
            }
            else {
                cout << "You have used your one and only one chance to go to the restaurant." << endl;
                endGame();
            }
        }
    }
    castleDoor();
}


// direct the player to the ghost right after the player gets into the castle
void castle() {
    show();
    cout << endl;
    char word[] = "You use the key to enter the castle. \n"
        "The castle is enormous and you almost get lost in there. \n"
        "Something suddenly comes out and scared you a lot.\n"
        "You find out that she is a ghost.\n";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    castleGhost();
}


// use vector(dynamic memory) to store three different words
// randomly generate a number to become the index of the vector
// maximum 3 trials are given
// add 1 to the number of trial in each loop to count the trial number
// once the number of trial reaches 3, the while loop will end
// there will be an additional tip after each failed trial
// if the player is able to guess the hidden word, the key for entering the castle will be provided
// otherwise, the player will lose the game since he/she is not able to enter the castle by using the key
void guessKey() {
    show();
    cout << endl;
    char word[] = "You gain a chance to get the key for entering the castle. \n"
        "You have to play a word guessing game. \n"
        "If you successfully guess the word, you can get the key.\n"
        "You only have 3 chances. You can get tip after each failure.\n"
        "Please guess the word in lowercase. ";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }

    vector<string> guessWord;
    guessWord.push_back("treasure");
    guessWord.push_back("puppy");
    guessWord.push_back("halloween");
    srand(time(NULL));
    int rnum = rand() % 3;
    string hereWord = guessWord[rnum];

    string userAnswer;
    int trial = 0;
    bool correct = false;
    if (userAnswer == hereWord)
        correct = true;
    cout << endl;

    while ((!correct) && (trial != 3)) {
        cout << endl;
        if (hereWord == "treasure") {
            if (trial == 0) {
                cout << "< 7 words >" << endl;
                cout << "1st Tip: valuable" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
            if (trial == 1) {
                cout << "Wrong Guess!" << endl;
                cout << "2nd Tip: always involove in stories about pirates" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
            if (trial == 2) {
                cout << "Wrong Guess!" << endl;
                cout << "3rd Tip: example like money, gold" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
        }

        if (hereWord == "puppy") {
            if (trial == 0) {
                cout << "< 5 words >" << endl;
                cout << "1st Tip: animal" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
            if (trial == 1) {
                cout << "Wrong Guess!" << endl;
                cout << "2nd Tip: little baby" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
            if (trial == 2) {
                cout << "Wrong Guess!" << endl;
                cout << "3rd Tip: a kind of pet" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
        }

        if (hereWord == "halloween") {
            if (trial == 0) {
                cout << "< 9 words >" << endl;
                cout << "Tip: festival" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }

            if (trial == 1) {
                cout << "Wrong Guess!" << endl;
                cout << "Tip: candy" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
            if (trial == 2) {
                cout << "Wrong Guess!" << endl;
                cout << "Tip: no holiday" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
        }
    }
    cout << endl;
    if (correct) {
        char con[] = "Congratulations! Your answer is correct! Awesome. \n"
            "You can use your key to go into the castle now.\n";
        for (int j = 0; j < sizeof(con); j++) {
            cout << con[j];
            usleep(3000);
        }
        castle();
    }
    if (!correct) {
        cout << endl << "You fail to guess the right word." << endl;
        cout << "The answer should be " << hereWord << endl;
        endGame();
    }
    cout << endl;
}



// check if the player has the key by accessing the bag (a vector to store items owned by the player in bag)
// allow the player to enter the castle if key is present
// allow the player to choose to play word-guessing game to get the key or directly give up
void castleIn() {
    show();
    cout << endl;
    char word[] = "You finally reach the castle, where your dog is in there. \n"
        "You walk to the door and find out that there is a huge lock. You need a key to open it.\n"
        "Do you have a key? (y: yes / n: no) \n";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    char input;
    cin >> input;
    cout << endl;
    bool haveKey;
    vector<string>::iterator find;
    for (find = bag.begin(); find != bag.end(); find++) {
        if (*find == "key" && input == 'y') 
            haveKey = true;
        else 
            haveKey = false;
        
    }
    if (haveKey) {
        cout << "Woohooo~ You successfully use the key to get in the castle." << endl;
        cout << "You are ready to save your dog!" << endl;
        bag.pop_back();
        castle();
    }
    else {
        cout << "An elf jumps out and said, \"Sad for you, " << name << ".\" \n";
        cout << "\"Seems you got no key in hand. Do you want a last choice to get the key?\"" << endl;
        cout << "Your response: (y: yes / n: no) " << endl;
        char answer;
        cin >> answer;
        while (answer != 'y' && answer != 'n') {
            cout << "Invalid Input! Please answer again.\n";
            cout << "Your response: (y: yes / n: no) ";
            cin >> answer;
        }
        if (answer == 'y')
            guessKey();
        if (answer == 'n') 
            endGame();
    }
    cout << endl;
}
