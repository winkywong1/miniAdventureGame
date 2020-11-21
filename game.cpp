#include <iostream>
#include <unistd.h>
#include <fstream>
#include "start.h"
#include "stat.h"
#include "wolf.h"
#include "monsterPlay.h"
#include "castle.h"
#include "finalStage.h"
using namespace std;

string name;
vector<string> bag;
int life = 100;
bool lose;
int chance = 0;
list<string> level;

// For Blackjack
// char array poker is used to indicate the poker card held by the player
// int array pokerNum is used to indicate the face value of the poker
char poker[13] = {'A','2','3','4','5','6','7','8','9','x','J','Q','K'};
int pokerNum[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};

// ask whether the player has played before or want to start a new game
// if the player has played before, he/she can go back to the previous section and continue the game
// lose of items in bag will be counted as the punishment but CP will remain the same
int main() {   
    system("clear");
    cout << "Press C to continue the last game" << endl;
    cout << "Press S to start a new game" << endl;
    cout << "> ";
    char status;
    cin >> status;
    cout << endl;
    while (status != 'C' && status != 'S') {
        cout << "Invalid Input! Please answer again.\n";
        cout << "Continue the last game or Start a new game (C: continue / S: start) ";
        cin >> status;
    }
    if (status == 'C') {
        cout << "Please input your name: " << endl;
        string conName;
        cin >> conName;

        ifstream checkGs;
        checkGs.open("gameStatus.txt");
        if (checkGs.fail()) {
            cout << "Error in file opening!" << endl;
            exit(1);
        }

		string line;
        vector<string> userInfo;
        string inWord = "";
		while (getline(checkGs, line)) {  
            for (auto x : line) {
                if (x == ' ') {
                    userInfo.push_back(inWord);
                    inWord = "";
                }
                else {
                    inWord = inWord + x;
                }
            }
            userInfo.push_back(inWord);
        }

        checkGs.close();
        
        for (int i = 0; i < userInfo.size(); i++) {
            if (userInfo[i] == conName) {
                name = userInfo[i];
                int inLife = stoi(userInfo[i+1]);
                life = inLife;
                if (userInfo[i+2] == "wolf") {
                    wolf();
                }
                if (userInfo[i+2] == "monster") {
                    shoot();
                }
                if (userInfo[i+2] == "castle") {
                    castleIn();
                }
                if (userInfo[i+2] == "final") {
                    finalStage();
                }
            }
        }
    }

    if (status == 'S') {
        information();
    }

    return 0;
}
