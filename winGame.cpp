#include <iostream>
#include <unistd.h>
#include <fstream>
#include "winGame.h"
using namespace std;

string name;
int life = 100;


// when the player passes all the tasks with positive value of CP left, this printout will be shown to indicate the success of game.
// the game will end right after printing the printout
// the information including the name, success and remain value of CP will be stored in a file "result.txt"
void winGame() {
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
    cout << "                You successfully rescue your dog!!!!! Congraduations!!!!               " << endl;
    usleep(10000);
    cout << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  < E N D     O F     G A M E >  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;

	ofstream fout;
    fout.open("result.txt", ios::app);
    if ( fout.fail() ) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    fout << "Name" << ": " << name << endl;
    fout << "Result: " << "win the game with " << life << " CP left." << endl;
    fout.close();
    exit(0);
}
