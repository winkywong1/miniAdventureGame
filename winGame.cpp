#include <iostream>
#include <unistd.h>
#include "winGame.h"
using namespace std;

bool lose;

void winGame() {
    lose = false;
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
    cout << "                You successfully rescue your dog!!!!! Congraduations!!!!               " << endl;
    usleep(5000);
    cout << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  < E N D     O F     G A M E >  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
}