#include <iostream>
#include <fstream>
#include <unistd.h>
#include "quitGame.h"
#include "stat.h"
using namespace std;

void quitGame() {
    cout << endl;
    cout << "Your game status will be stored." << endl;
    cout << "The game will be started from the beginning of your previous scenario." << endl;
    cout << "You can take a rest and finish the adventrue later." << endl;
	ofstream gs;
    gs.open("gameStatus.txt", ios::app);
    if ( gs.fail() ) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }
    gs << name << " " << life << " " << level.front();
    gs << endl;

    gs.close();
    exit(0);
}