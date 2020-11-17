#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

string name;
vector<string> bag;
vector<int> levelSucceed;
int life = 100;
bool lose;

void show() {
    cout << endl;
    usleep(15000);
    vector<string>::iterator thing;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "        CP: " << life << "                    Bag: ";
    for (thing = bag.begin(); thing != bag.end(); thing++) 
        cout << *thing << ' ';
    cout << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
}

void endGame() {
    lose = true;
    cout << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    cout << endl;
    cout << "You fail to save your dog." << endl;
    usleep(5000);
    cout << endl;
    cout << "You can never see your dog and you are very upset." << endl;
    usleep(5000);
    cout << endl;
    cout << "                                   G A M E     O V E R" << endl;
}

void castle() {

}

void guessKey() {
    show();
    cout << endl;
    char word[] = "You gain a chance to get the key for entering the castle. \n"
        "You have to play a word guessing game. \n"
        "If you successfully guess the word, you can get the key.\n"
        "You only have 3 chances. You can get tip after each failure.\n"
        "Please guess the word in lowercase. ";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }

    vector<string> guessWord;
    guessWord.push_back("treasure");
    guessWord.push_back("puppy");
    guessWord.push_back("halloween");
    int rnum = rand() % 3;
    string hereWord = guessWord[rnum];

    string userAnswer;
    int trial = 0;
    bool correct;

    cout << endl;

    while (!correct && trial != 3) {
        cout << endl;
        if (hereWord == "treasure") {
            if (trial == 0) {
                cout << "< 7 words >" << endl;
                cout << "1st Tip: valuable" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
            }
            if (trial == 1) {
                cout << "Wrong Guess!" << endl;
                cout << "2nd Tip: always involove in stories about pirates" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
            }
            if (trial == 2) {
                cout << "Wrong Guess!" << endl;
                cout << "3rd Tip: example like money, gold" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
            }
        }

        if (hereWord == "puppy") {
            if (trial == 0) {
                cout << "< 5 words >" << endl;
                cout << "1st Tip: animal" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
            }
            if (trial == 1) {
                cout << "Wrong Guess!" << endl;
                cout << "2nd Tip: little baby" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
            }
            if (trial == 2) {
                cout << "Wrong Guess!" << endl;
                cout << "3rd Tip: a kind of pet" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
            }
        }

        if (hereWord == "halloween") {
            if (trial == 0) {
                cout << "< 9 words >" << endl;
                cout << "Tip: festival" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
            }
            if (trial == 1) {
                cout << "Wrong Guess!" << endl;
                cout << "Tip: candy" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
            }
            if (trial == 2) {
                cout << "Wrong Guess!" << endl;
                cout << "Tip: no holiday" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
            }
        }
        if (userAnswer == hereWord) {
            correct = true;
            break;
        }
    }

    if (correct) {
        char con[] = "Congraduations! Your answer is correct! Awesome. \n"
            "You can use your key to go into the castle now.";
        for (int j = 0; j < sizeof(con); j++) {
            cout << con[j];
            usleep(3000);
        }
        bag.push_back("key");
        castle();
    }
    else {
        endGame();
    }
}

void castleIn() {
    show();
    cout << endl;
    char word[] = "You finally reach the castle, where your dog is in there. \n"
        "You walk to the door and find out that there is a huge lock. You need a key to open it.\n"
        "Do you have a key? (y: yes / n: no) ";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    char input;
    cin >> input;
    cout << endl;
    bool haveKey;
    vector<string>::iterator find;
    for (find = bag.begin(); find != bag.end(); find++) {
        if (*find == "key" && input == 'y') {
            haveKey = true;
        }
        else {
            haveKey = false;
        }
    }
    if (haveKey) {
        cout << "Woohooo~ You successfully use the key to get in the castle." << endl;
        cout << "You are ready to save your dog!" << endl;
    }
    else {
        cout << "An elf jumps out and said, \"Sad for you, " << name << ". \n";
        cout << "Seems you got no key in hand. Do you want a last choice to get the key?\"" << endl;
        cout << "Your response: (y: yes / n: no) " << endl;
        char answer;
        cin >> answer;
        while (answer != 'y' && answer != 'n') {
            cout << "Invalid Input! Please answer again.\n";
            cout << "Your response: (y: yes / n: no) ";
            cin >> answer;
        }
        if (answer == 'y')
            guessKey();
        if (answer == 'n') 
            endGame();
    }
}

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
}

void wolf() {
    show();
    cout << endl;
    char word[] = "You walk in the forrest and you accidentally meet a wolf. \n"
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
    vector<string>::iterator find;
    for (find = bag.begin(); find != bag.end(); find++) {
        if (answer == 'y') {
            if (*find == "steak" || *find == "fish")
                haveFood = true;
            else
                haveFood = false;
        }
        else
            haveFood = false;
    }

    if (haveFood) {
        char food[] = "The wolf is happy and full now. \n"
        "He walks away without hurting you and you are safe now. \n \n" 
        "You can keep on your adventure.";
        for (int j = 0; j < sizeof(food); j++) {
            cout << food[j];
            usleep(3000);
        }
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

}

void lake() {
    show();
    cout << endl;
    char word[] = "You walk to the right side of the road and you see a lake in front of you. \n"
        "You decide to take a rest next to the lake. \n"
        "When you are sitting down, your wood stick falls into the lake. \n" 
        "You have no idea what to do.\n"
        "Suddenly, a fairy comes out from the lake and says, \n"
        "\"Seems that you lost your stick. Let's play a game! If you win, you can give it back.\"\n \n"
        "< Rock, Paper, Scissors > \n"
        "Rock crushes Scissors, Paper covers Rock, Scissors cuts Paper\n";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    cout << endl;
    char userChoice;
    cout << "You decide to play: (r: rock / p: paper / s: scissors)? " << endl;
    bool userWin = false;
    bool again = false;
    char randChoice[3] = {'r','p','s'};
    char fairyDecision;
    fairyDecision = randChoice[rand() % 3];

    cin >> userChoice;
    cout << endl;
    
    while (userChoice != 'r' && userChoice != 'p' && userChoice != 's') {
        cout << "Invalid Input! Play again. (r: rock / p: paper / s: scissors)? " << endl;
        fairyDecision = randChoice[rand() % 3];
        cin >> userChoice;
    }

    while (fairyDecision == userChoice) {
        cout << "Fairy plays " << fairyDecision << endl;
        cout << "Draw. Play again.  (r: rock / p: paper / s: scissors)? " << endl;
        fairyDecision = randChoice[rand() % 3];
        cin >> userChoice;
    }

    if (fairyDecision == 'r') {
        if (userChoice == 'p')
            userWin = true;
        if (userChoice == 's')
            userWin = false;
    }
    else if (fairyDecision == 'p') {
        if (userChoice == 's')
            userWin = true;
        if (userChoice == 'r')
            userWin = false;
    }
    else if (fairyDecision == 's') {
        if (userChoice == 'r')
            userWin = true;
        if (userChoice == 'p')
            userWin = false;
    }

    if (userWin) {
        cout << "Fairy plays " << fairyDecision << endl;
        cout << "Fairy said, \"Congraduations!! Here is your stick. Also, this fish is a bonus for you.\"" << endl;
        bag.push_back("fish");
    }
    if (!userWin) {
        cout << "Fairy plays " << fairyDecision << endl;
        cout << "Fairy said, \"Sorry for you. I afraid that I cannot give your stick back. Bye~\"" << endl;
        cout << "You are unhappy and frustrated so you hit on a tree and pass out." << endl;
        cout << "You lose 20 CP." << endl;
        life -= 20;
        bag.pop_back();
    }
    cout << endl;
    wolf();
}

void woodhouse() {
    show();
    cout << endl;
    char word[] = "You walk to the left side of the road and you see a wooden hut in front of you. \n"
        "You would like to go inside and take a rest. \n" 
        "When you get in there, you see a poor little boy crying with no reason.";
        for (int i = 0; i < sizeof(word); i++) {
            cout << word[i];
            usleep(3000);
        }
    cout << endl;
    char answer;
    cout << "Would you comfort him and see if anything can help? (y: yes / n: no)" << endl;
    cin >> answer;
    cout << endl;

    while (answer != 'y' && answer != 'n') {
        cout << "Invalid Input! Please answer again.\n";
        cout << "Your response: (y: yes / n: no) ";
        cin >> answer;
    }
    if (answer == 'y') {
        char comfort[] = "The kid cried because his robot is broken. \n"
        "He feels better now after your comfort. \n" 
        "He is very happy so he gives you a steak to thanks for your compassion. \n \n"
        "You receive a steak and keep on your adventure.";
        for (int j = 0; j < sizeof(comfort); j++) {
            cout << comfort[j];
            usleep(3000);
        }
        bag.push_back("steak");
    }
    if (answer == 'n') {
        char notcomfort[] = "The kid keeps crying so you cannot take a nap. \n"
        "You are bothered and you are not energetic as before anymore. \n \n" 
        "Your CP is decreased by 20. You keep your tired body to keep on the adventure";
        for (int k = 0; k < sizeof(notcomfort); k++) {
            cout << notcomfort[k];
            usleep(3000);
        }
        life -= 20;
    }
    wolf();
}

void tree() {
    show();
    cout << endl;

}

void red() {
    show();
    cout << endl;

}


void folk() {
    char input;
    char word[] = "You just walk into the forrest and meet your first folk in the road (literally).\n"
        "Now, go left or right (l: left / r: right)? ";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    cin >> input;
    cout << endl;
    while (input != 'l' && input != 'r') {
        cout << "Invalid Input! Please answer again.\n";
        cout << "Go left or right (l: left / r: right)? ";
        cin >> input;
    }
    if (input == 'l')
        woodhouse();
    if (input == 'r')
        lake();
}

void background() {
    cout << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << endl;
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

void level() {
    if ((levelSucceed.size()) == 0)
        lake();
}

void instruction() {
    char word[] = "Here are some basic instructions: \n"
    "In the adventure, you may face a lot of difficulties.\n"
    "Press the corresponding botton to make your choice.\n"
    "Different decision may lead to a completely different situation.\n"
    "Try to make the best choice and survive to the end.\n";

    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
}

void information() {
    cout << "Please enter your name: ";
    cin >> name;
    cout << endl;
    cout << "Hello, " << name << ". " << endl;
    cout << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << endl;
    instruction();
    cout << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << endl;
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

int main() {
    system("clear");
    if (life <= 0)
        lose = true;
    while (!lose)
        information();

    return 0;
}
