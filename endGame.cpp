#include <iostream>
#include <unistd.h>
#include "endGame.h"
using namespace std;

bool lose;

void endGame() {
    lose = true;
    cout << endl << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl << endl;;
    cout << "                              You fail to save your dog.                               " << endl;
    usleep(5000);
    cout << endl << "                  You can never see your dog and you are very upset.                   " << endl;
    usleep(5000);
    cout << endl << "                             - - G A M E     O V E R - -" << endl;
}