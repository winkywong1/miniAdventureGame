#include <iostream>
#include <unistd.h>
#include <vector>
#include "wolf.h"
#include "show.h"
#include "endGame.h"
#include "monsterPlay.h"
#include "castle.h"
using namespace std;

vector<string> bag;
int life = 100;

void defense() {
    char answer;
    cout << "Will you use the stick to defense and keep you safe, or do nothing?" << endl;
    cout << "Your response: (y: defense / n: not defense)" << endl;
    cin >> answer;
    cout << endl;
    bool canDefense;
    vector<string>::iterator find;
    while (answer != 'y' && answer != 'n') {
        cout << "Invalid Input! Please answer again.\n";
        cout << "Your response: (y: yes / n: no) ";
        cin >> answer;
    }
    if (answer == 'y') {
        for (find = bag.begin(); find != bag.end(); find++) {
            if (*find == "stick") 
                canDefense = true;
        }
    }
    if (answer == 'n') {
        canDefense = false;
    }

    if (canDefense) {
        char cD[] = "You try your best to defense and protect yourself. \n"
            "Although you lost your stick during the fight, you only can a little hurt. \n \n" 
            "Your CP is decreased by 10. You keep your tired body to keep on the adventure";
        for (int i = 0; i < sizeof(cD); i++) {
            cout << cD[i];
            usleep(3000);
        }
        life -= 10;
        vector<string>::iterator item = bag.begin();
        for (int j = 0; j < bag.size(); j++) {        
            if (*item == "stick") {
                bag.erase(bag.begin() + j);
            }
            item++;
        }
    }
    else {
        char nD[] = "You choose not to fight with the wolf so you are seriously injuried. \n"
        "Although you are hurt, you still insist to keep on your journey. \n \n" 
        "Your CP is decreased by 30. You now keep on the adventure";
        for (int k = 0; k < sizeof(nD); k++) {
            cout << nD[k];
            usleep(3000);
        }
        life -= 30;
    }
    cout << endl;
    if (life <= 0) {
        cout << endl << "- - - - - - Your CP is 0. You don't have enough energy to finish the journey. - - - - - - " << endl;
        endGame();
    }
    shoot();
}

void wolf() {
    show();
    cout << endl;
    char word[] = "You walk in the forest and you accidentally meet a wolf. \n"
        "The wolf is scary and horrible He is full of hunger. ";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    cout << endl;
    char answer;
    cout << "Do you have any food that can give him and avoid being eaten? (y: yes / n: no)" << endl;
    cin >> answer;
    cout << endl;
    bool haveFood;
    if (answer == 'n') {
        haveFood = false;
    }
    if (answer == 'y') {
        vector<string>::iterator find;
        for (find = bag.begin(); find != bag.end(); find++) {
            if ((*find == "steak") || (*find == "fish")) 
                haveFood = true;
            else
                haveFood = false;
        }
    }

    if (haveFood) {
        char food[] = "The wolf is happy and full now. \n"
            "He walks away without hurting you and you are safe now. \n \n" 
            "You can keep on your adventure.\n \n";
        for (int j = 0; j < sizeof(food); j++) {
            cout << food[j];
            usleep(3000);
        }
        bag.pop_back();
        shoot();
    }
    if (!haveFood) {
        char nofood[] = "You have no food to give him!! \n"
            "The wolf is very angry!!!!!! \n"
            "He is going to attack you and you are thinking if you should defense or not \n \n";
        for (int k = 0; k < sizeof(nofood); k++) {
            cout << nofood[k];
            usleep(3000);
        }
        defense();
    }
    cout << endl;
}
