#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>
#include "path.h"
#include "show.h"
#include "wolf.h"
using namespace std;

vector<string> bag;
int life = 100;

void lake() {
    show();
    cout << endl;
    char word[] = "You walk to the right side of the road and you see a lake in front of you. \n"
        "You decide to take a rest next to the lake. \n"
        "When you are sitting down, your wood stick falls into the lake. \n" 
        "You have no idea what to do.\n"
        "Suddenly, a fairy comes out from the lake and says, \n"
        "\"Seems that you lost your stick. Let's play a game! If you win, you can give it back.\"\n \n"
        "< Rock, Paper, Scissors > \n"
        "Rock crushes Scissors, Paper covers Rock, Scissors cuts Paper\n";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    cout << endl;
    char userChoice;
    cout << "You decide to play: (r: rock / p: paper / s: scissors)? " << endl;
    bool userWin = false;
    bool again = false;
    char randChoice[3] = {'r','p','s'};
    char fairyDecision;
    srand(time(NULL));
    fairyDecision = randChoice[rand() % 3];

    cin >> userChoice;
    cout << endl;
    
    while (userChoice != 'r' && userChoice != 'p' && userChoice != 's') {
        cout << "Invalid Input! Play again. (r: rock / p: paper / s: scissors)? " << endl;
        fairyDecision = randChoice[rand() % 3];
        cin >> userChoice;
    }

    while (fairyDecision == userChoice) {
        cout << "Fairy plays " << fairyDecision << endl;
        cout << "Draw. Play again.  (r: rock / p: paper / s: scissors)? " << endl;
        fairyDecision = randChoice[rand() % 3];
        cin >> userChoice;
    }

    if (fairyDecision == 'r') {
        if (userChoice == 'p')
            userWin = true;
        if (userChoice == 's')
            userWin = false;
    }
    else if (fairyDecision == 'p') {
        if (userChoice == 's')
            userWin = true;
        if (userChoice == 'r')
            userWin = false;
    }
    else if (fairyDecision == 's') {
        if (userChoice == 'r')
            userWin = true;
        if (userChoice == 'p')
            userWin = false;
    }

    if (userWin) {
        cout << "Fairy plays " << fairyDecision << endl;
        cout << "Fairy said, \"Congraduations!! Here is your stick. Also, this fish is a bonus for you.\"" << endl;
        bag.push_back("fish");
    }
    if (!userWin) {
        cout << "Fairy plays " << fairyDecision << endl;
        cout << "Fairy said, \"Sorry for you. I afraid that I cannot give your stick back. Bye~\"" << endl;
        cout << "You are unhappy and frustrated so you hit on a tree and pass out." << endl << endl;
        cout << "You lose 20 CP." << endl;
        life -= 20;
        bag.pop_back();
    }
    cout << endl;
    wolf();
}

void woodhouse() {
    show();
    cout << endl;
    char word[] = "You walk to the left side of the road and you see a wooden hut in front of you. \n"
        "You would like to go inside and take a rest. \n" 
        "When you get in there, you see a poor little boy crying with no reason.";
        for (int i = 0; i < sizeof(word); i++) {
            cout << word[i];
            usleep(3000);
        }
    cout << endl;
    char answer;
    cout << "Would you comfort him and see if anything can help? (y: yes / n: no)" << endl;
    cin >> answer;
    cout << endl;

    while (answer != 'y' && answer != 'n') {
        cout << "Invalid Input! Please answer again.\n";
        cout << "Your response: (y: yes / n: no) ";
        cin >> answer;
    }
    if (answer == 'y') {
        char comfort[] = "The kid cried because his robot is broken. \n"
        "He feels better now after your comfort. \n" 
        "He is very happy so he gives you a steak to thanks for your compassion. \n \n"
        "You receive a steak and keep on your adventure.";
        for (int j = 0; j < sizeof(comfort); j++) {
            cout << comfort[j];
            usleep(3000);
        }
        bag.push_back("steak");
    }
    if (answer == 'n') {
        char notcomfort[] = "The kid keeps crying so you cannot take a nap. \n"
        "You are bothered and you are not energetic as before anymore. \n \n" 
        "Your CP is decreased by 20. You keep your tired body to keep on the adventure";
        for (int k = 0; k < sizeof(notcomfort); k++) {
            cout << notcomfort[k];
            usleep(3000);
        }
        life -= 20;
    }
    cout << endl;
    wolf();
}

void folk() {
    char input;
    char word[] = "You just walk into the forest and meet your first fork in the road (literally).\n"
        "Now, go left or right (l: left / r: right)? ";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    cin >> input;
    cout << endl;
    while (input != 'l' && input != 'r') {
        cout << "Invalid Input! Please answer again.\n";
        cout << "Go left or right (l: left / r: right)? ";
        cin >> input;
    }
    if (input == 'l')
        woodhouse();
    if (input == 'r')
        lake();
}
