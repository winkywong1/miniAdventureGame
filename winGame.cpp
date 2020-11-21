#include <iostream>
#include <unistd.h>
#include <fstream>
#include "winGame.h"
#include "stat.h"
using namespace std;

// when the player passes all the tasks with positive value of CP left, this printout will be shown to indicate the success of game.
// the game will end right after printing the printout
// the information including the name, success and remain value of CP will be stored in a file "result.txt"
void winGame() {
    ifstream fin;
    fin.open("winGameMsg.txt");
    if (fin.fail()){
        cout<<"error in file opening"<<endl;
        exit(1);
    }
    string winMsg;
    while (getline(fin,winMsg)){
        cout << winMsg << endl;
    }
    fin.close();

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
