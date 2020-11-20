#include <iostream>
#include <unistd.h>
#include <fstream>
#include "endGame.h"
using namespace std;

string name;
int life = 100;

// when the player fails to pass all the tasks or his/her CP reaches equal or less than 0, this printout will be shown to indicate the failure of game.
// the game will end right after printing the printout
// the information including the name, failure and remain value of CP will be stored in a file "result.txt"
void endGame() {
    cout << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl << endl;;
    cout << "                              You fail to save your dog.                               " << endl;
    usleep(5000);
    cout << endl << "                  You can never see your dog and you are very upset.                   " << endl;
    usleep(5000);
    cout << endl << "                             - - G A M E     O V E R - -" << endl;

	ofstream fout;
    fout.open("result.txt", ios::app);
    if ( fout.fail() ) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    fout << "Name" << ": " << name << endl;
    fout << "Result: " << "lose the game with " << life << " CP left." << endl;
    fout.close();
    exit(0);
}
