#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "start.h"
#include "path.h"

using namespace std;

string name;
vector<string> bag;

void background() {
    cout << endl << "---------------------------------------------------------------------------------------" << endl << endl;
    char content[] = 
        "                    Your favouraite dog was kidnapped to the forest.                   \n"
        "        You are worried about him so you decide to go in the forest to save him.       \n"
        "         You bring a wood stick for protection and you are full of energy now.         \n";
    for (int i = 0; i < sizeof(content); i++) {
        cout << content[i];
        usleep(3000);
    }
    cout << endl;
    usleep(3000);
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << endl;
    bag.push_back("stick");
    folk();
}

void information() {
    cout << "Please enter your name: ";
    cin >> name;
    cout << endl << "Hello, " << name << ". " << endl << endl;
    cout << "---------------------------------------------------------------------------------------" << endl << endl;
    char word[] = "Here are some basic instructions: \n"
    "In the adventure, you may face a lot of difficulties.\n"
    "Press the corresponding botton to make your choice.\n"
    "Different decision may lead to a completely different situation.\n"
    "Try to make the best choice and survive to the end.\n";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    cout << endl << "---------------------------------------------------------------------------------------" << endl << endl;
    cout << "Are you ready to start your adventure? (y: yes / n: no)" << endl;
    char choice;
    cin >> choice;
    while (choice != 'y') {
        cout << endl;
        if (choice == 'n') {
            char comfort[] = "Are you worried about the adventure?\n" 
                "There is nothing to worried about! We believe in you.\n"
                "Now, are you ready to start your adventure? (y: yes / n: no)\n";
            for (int i = 0; i < sizeof(comfort); i++) {
                cout << comfort[i];
                usleep(3000);
            }
            cin >> choice;
        }
        else if (choice != 'y' && choice != 'n') {
            char wrong[] = "Invalid Input! Please answer again.\n"
                "Now, are you ready to start your adventure? (y: yes / n: no)\n";
            for (int i = 0; i < sizeof(wrong); i++) {
                cout << wrong[i];
                usleep(3000);
            }
            cin >> choice;
        }
    }
    background();
}

