#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "show.h"
using namespace std;

vector<string> bag;
int life = 100;

void show() {
    cout << endl;
    usleep(15000);
    vector<string>::iterator thing;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "        CP: " << life << "                    Bag: ";
    for (thing = bag.begin(); thing != bag.end(); thing++) 
        cout << *thing << ' ';
    cout << endl << "---------------------------------------------------------------------------------------" << endl;
}
