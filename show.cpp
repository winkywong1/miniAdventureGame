#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "show.h"
using namespace std;

vector<string> bag;
int life = 100;

// player may not remember all the variation of the CP and items in bag
// this function is to display this two information in every different scenarios
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
