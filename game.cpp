#include <iostream>
#include <unistd.h>
#include <fstream>
#include "endGame.h"
#include "start.h"

using namespace std;
string name;
int life = 100;
bool lose;

int main() {
	ofstream fout;
    fout.open("result.txt", ios::app);

    if ( fout.fail() ) {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    system("clear");

    if (life <= 0) {
        lose = true;
        endGame();
    }
    while (!lose)
        information();

    fout << "Name" << ": " << name << endl;
    if (lose)
        fout << "Result: " << "lose the game with " << life << " CP left." << endl;
    if (!lose)
        fout << "Result: " << "win the game with " << life << " CP left." << endl;
    fout.close();
    
    return 0;
}