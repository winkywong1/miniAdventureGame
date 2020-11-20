#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <fstream>

using namespace std;

string name;
vector<string> bag;
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
    cout << endl << "---------------------------------------------------------------------------------------" << endl;
}

void winGame() {
    lose = false;
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
    cout << "                You successfully rescue your dog!!!!! Congraduations!!!!               " << endl;
    usleep(10000);
    cout << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  < E N D     O F     G A M E >  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
}

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

// finalStage

char poker[13] = {'A','2','3','4','5','6','7','8','9','x','J','Q','K'};
int pokerNum[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
const int maxNumOfPoker = 5;

void calBlackjack(int num, char number[maxNumOfPoker], char a, int *mina, int *maxa, int *minto, int *maxto) {
    number[num] = a;
    srand(time(NULL));
    for (int i = 0; i < 13; i++) {
        if (a == poker[i]) {
            if (a == 'A') {
                *mina = 1;
                *maxa = 11;
            }
            else if (a == 'x') {
                *mina = 10;
                *maxa = 10;
            }
            else {
                *mina = pokerNum[i];
                *maxa = pokerNum[i];
            }
        }
    }
    *minto += *mina;
    *maxto += *maxa;
}

void blackjack() {
    cout << endl << "---------------------------------------------------------------------------------------" << endl << endl;
    cout << "                                << B L A C K J A C K >>                                " << endl << endl;
    cout << "---------------------------------------------------------------------------------------" << endl << endl;;

    char word[] = "Rule of Blackjack: \n"
        "1. Your aim is to get a total of 21 points according to the face value of the card.\n"
        "2. An Ace can count as either 1 or 11. \n"
        "3. All 10, J, Q and K count as 10. \n"
        "4. If you get a total of points more than 21, your hand is a BUST and you lose the game. \n"
        "5. If the hands of you and the dealer are both bust, you still lose the game. \n"
        "6. If you get 21 points, even if the dealer get 21 points, you still win. \n"
        "7. If you and the dealer do not bust, you can win only if your total is higher.\n"
        "8. Hit = want a more card ; Stand = keep the card and stop taking anymore card. \n";

    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    cout << endl;

    bool userHits = true;
    bool dealerHits = true;
    bool Ubust = false;
    bool Dbust = false;
    bool userWins, dealerWins;
    int round = 1;
    int userCard = 2;
    int dealerCard = 2;
    char UshowPo[maxNumOfPoker];
    char DshowPo[maxNumOfPoker];

    struct player
    {
        char card1, card2, card3, card4, card5;
        int mintotal, maxtotal, minVcard1, maxVcard1, minVcard2, maxVcard2, minVcard3, maxVcard3, minVcard4, maxVcard4, minVcard5, maxVcard5;
    };    

    player dealer, user;
    dealer.mintotal = 0;    dealer.maxtotal = 0;
    dealer.minVcard1 = 0;    dealer.maxVcard1 = 0;
    dealer.minVcard2 = 0;    dealer.maxVcard2 = 0;
    dealer.minVcard3 = 0;    dealer.maxVcard3 = 0;
    dealer.minVcard4 = 0;    dealer.maxVcard4 = 0;
    dealer.minVcard5 = 0;    dealer.maxVcard5 = 0;

    user.mintotal = 0;    user.maxtotal = 0;
    user.minVcard1 = 0;    user.maxVcard1 = 0;
    user.minVcard2 = 0;    user.maxVcard2 = 0;
    user.minVcard3 = 0;    user.maxVcard3 = 0;
    user.minVcard4 = 0;    user.maxVcard4 = 0;
    user.minVcard5 = 0;    user.maxVcard5 = 0;

    dealer.card1 = poker[rand() % 13];
    dealer.card2 = poker[rand() % 13];
    user.card1 = poker[rand() % 13];
    user.card2 = poker[rand() % 13];

    calBlackjack(0, DshowPo, dealer.card1, &dealer.minVcard1, &dealer.maxVcard1, &dealer.mintotal, &dealer.maxtotal);
    calBlackjack(1, DshowPo, dealer.card2, &dealer.minVcard2, &dealer.maxVcard2, &dealer.mintotal, &dealer.maxtotal);
    calBlackjack(0, UshowPo, user.card1, &user.minVcard1, &user.maxVcard1, &user.mintotal, &user.maxtotal);
    calBlackjack(1, UshowPo, user.card2, &user.minVcard2, &user.maxVcard2, &user.mintotal, &user.maxtotal);
    
    cout << "-------------------------------------- Dealer ---------------------------------------" << endl << endl;
    cout << "Bad guy said, \"Let me be the dealer.\"" << endl;
    cout << "\"I have got a " << dealer.card1 << ".\"" << endl << endl;
    cout << "Now is your turn to play." << endl << endl;
    sleep(1);
    cout << "-------------------------------------- Round " << round << " --------------------------------------" << endl << endl;
    char input1;
    cout << "You are holding ";
    for (int i = 0; i < userCard; i++) {
        if (UshowPo[i] == 'x')
            cout << "10 ";
        else
            cout << UshowPo[i] << " ";
    }
    cout << ". " << endl;
    cout << "The smaller possible sum of card is " << user.mintotal << " and the larger possible is " << user.maxtotal << ". " << endl;

    while (userHits && !Ubust) {
        if (user.mintotal == 21 || user.maxtotal == 21) {
            userWins = true;
            cout << endl << "Blackjack!!! Amazing!!! Let\'s how is it the dealer" << endl;
            cout << endl << "Press SPACE to continue" << endl << endl;
            char space;
            cin >> space;
            if (space == ' ')
                break;
        }
        cout << endl;
        round += 1;
        usleep(30000);
        cout << "-------------------------------------- Round " << round << " --------------------------------------" << endl;
        cout << endl;
        cout << "Do you want to hit or to stand? (h: hit / s: stand)" << endl;
        char input;
        cin >> input;
        cout << endl;
        while (input != 'h' && input != 's') {
            cout << "Invalid Input! Please answer again.\n";
            cout << "Do you want to hit or to stand? (h: hit / s: stand)";
            cin >> input;
        }
        if (input == 'h') {
            userHits = true;
            if (userCard == 2) {
                user.card3 = poker[rand() % 13];
                calBlackjack(userCard, UshowPo, user.card3, &user.minVcard3, &user.maxVcard3, &user.mintotal, &user.maxtotal);
            }
            if (userCard == 3) {
                user.card4 = poker[rand() % 13];
                calBlackjack(userCard, UshowPo, user.card4, &user.minVcard4, &user.maxVcard4, &user.mintotal, &user.maxtotal);
            }
            if (userCard == 4) {
                user.card5 = poker[rand() % 13];
                calBlackjack(userCard, UshowPo, user.card5, &user.minVcard5, &user.maxVcard5, &user.mintotal, &user.maxtotal);
            }
            userCard += 1;
            cout << "You choose to hit. Now you have got ";
            for (int i = 0; i < userCard; i++) {
                if (UshowPo[i] == 'x')
                    cout << "10 ";
                else
                    cout << UshowPo[i] << " ";
            }
            cout << ". " << endl;
            cout << "The smaller possible sum of card is " << user.mintotal << " and the larger possible is " << user.maxtotal << ". " << endl;
        }
        if (input == 's') {
            userHits = false;
            cout << "You choose to stand." << endl;
            cout << "The smaller possible sum of card is " << user.mintotal << " and the larger possible is " << user.maxtotal << ". " << endl;
            cout << endl;
        }
        if (user.mintotal > 21) {
            Ubust = true;
            cout << endl;
            cout << "!!!!! BUST !!!!!" << endl;
            break;
        }
        if (user.mintotal == 21 || user.maxtotal == 21) {
            userWins = true;
            cout << endl;
            cout << "Bingo!!! Black Jack!!! :D" << endl;
            break;
        }
    }
    cout << endl << "------------------------------------ Dealer's Turn ------------------------------------" << endl << endl;
    cout << "Bad guy said, \"Well, you finished then now is my turn.\"" << endl;
    cout << "I am holding ";
    for (int i = 0; i < dealerCard; i++) {
        if (DshowPo[i] == 'x')
            cout << "10 ";
        else
            cout << DshowPo[i] << " ";
    }
    cout << ". " << endl;

    if (dealer.mintotal < 17)  
        dealerHits = true;

    while (dealerHits && !Dbust) {
        if (dealer.mintotal == 21 || dealer.maxtotal == 21) {
            dealerWins = true;
            break;
        }
        if (dealerCard == 2) {
            dealer.card3 = poker[rand() % 13];
            calBlackjack(dealerCard, DshowPo, dealer.card3, &dealer.minVcard3, &dealer.maxVcard3, &dealer.mintotal, &dealer.maxtotal);
        }
        if (dealerCard == 3) {
            user.card4 = poker[rand() % 13];
            calBlackjack(dealerCard, DshowPo, dealer.card4, &dealer.minVcard4, &dealer.maxVcard4, &dealer.mintotal, &dealer.maxtotal);
        }
        if (dealerCard == 4) {
            user.card5 = poker[rand() % 13];
            calBlackjack(dealerCard, DshowPo, dealer.card5, &dealer.minVcard5, &dealer.maxVcard5, &dealer.mintotal, &user.maxtotal);
        }
        dealerCard += 1;
        usleep(30000);
        cout << "Hit! Let\'s see what I get. ";
        for (int j = 0; j < dealerCard; j++) {
            if (DshowPo[j] == 'x')
                cout << "10 ";
            else
                cout << DshowPo[j] << " ";
        }
        cout << ". " << endl;
        usleep(30000);
        if (dealer.mintotal < 17)  {
            dealerHits = true;
        }
        if (dealer.mintotal >= 17) {
            dealerHits = false;
        }
        if (dealer.mintotal > 21) {
            Dbust = true;
            cout << endl;
            cout << "!!!!! WHAT??? BUST !!!!!" << endl;
            break;
        }
        if (dealer.mintotal == 21 || dealer.maxtotal == 21) {
            dealerWins = true;
            cout << endl;
            cout << "Bad guy said, \"Woohooooo!! 21!!!!\"" << endl;
            break;
        }
    }
    cout << endl;
    sleep(1);
    cout << "---------------------------------------------------------------------------------------" << endl << endl;
    if ((Ubust) && (Dbust)) {
        cout << "Bad guy said, \"Although I busted, you are still counted as lose, poor guy.\"" << endl;
        cout << "\"Say bye to your dog!\"" << endl << endl;
        endGame();
    }
    if ((Ubust) && (!Dbust)) {
        cout << "Bad guy said, \"Ha ha ha, you lose little boy. Say bye to your dog.\"" << endl << endl;
        endGame();
    }
    if ((!Ubust) && (Dbust)) {
        cout << "Bad guy said, \"I can\'t believe that you beat me. No one ever wins me.\"" << endl;
        cout << "\"Okay, fine. You win. You can take your dog away.\"" << endl << endl;
        winGame();
    }

    if ((!Ubust) && (!Dbust)) {
        if ((userWins && !dealerWins) || (dealer.mintotal > user.mintotal)) {
            cout << "Bad guy said, \"I can\'t believe that you beat me. No one ever wins me.\"" << endl;
            cout << "\"Okay, fine. You win. You can take your dog away.\"" << endl << endl;
            winGame();
        }
        if ((!userWins && dealerWins) || (dealer.mintotal < user.mintotal)) {
            cout << "Bad guy said, \"Ha ha ha, you lose little boy. Say bye to your dog.\"" << endl << endl;
            endGame();
        }
        if ((userWins && dealerWins) || (dealer.mintotal == user.mintotal)) {
            cout << "Bad guy said, \"Okay... It\'s a draw...\"" << endl;
            cout << "\"But we have make a deal that only playing one round.\"" << endl;
            cout << "\"Fine, lucky you. Just take your dog and go away.\"" << endl << endl;
            winGame();
        }
    }
}

void finalStage() {
    show();
    cout << endl;
    char word[] = "You meet your dog after so many obstacles. \n"
        "HOWEVER, the bad guy sits right next to the dog and keeps you away from him. \n"
        "The bad guy said, \"You want to save your dog? IMPOSSIBLE!\" \n ...... \n"
        "\"Unless... you win me in the blackjack. I am master of blackjack.\" \n"
        "\"And we just need to play one round. What do you think?\"\n";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    cout << endl << "\"At least it is a chance...,\" you think." << endl;
    cout << "Just give it a try!" << endl;
    blackjack();
}

// castle

void castleDoor() {
    show();
    cout << endl;
    char word[] = "You search room by room and you finally reach the last room. \n"
        "Your dog probably is locked in this room but you cannot go in there.";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    cout << endl;
    char op[] = "You now have three options: \n"
        "1. ask the ghost for help if she is your accompany \n"
        "2. break into the room \n"
        "3. frustrated and give up to save your dog \n";
    for (int j = 0; j < sizeof(op); j++) {
        cout << op[j];
        usleep(3000);
    }
    bool haveG;
    vector<string>::iterator find;
    for (find = bag.begin(); find != bag.end(); find++) {
        if (*find == "ghost") 
            haveG = true;
        else
            haveG = false;
    }

    cout << endl << "You will choose option 1, 2 or 3? (1 / 2 / 3)" << endl;
    int option;
    cin >> option;
    while (option != 1 && option != 2 && option != 3) {
        cout << "Invalid Input! Please answer again.\n";
        cout << "You will choose option 1, 2 or 3? (1 / 2 / 3)";
        cin >> option;
    }
    if (option == 1 && haveG) {
        cout << "The ghost passes through the wall and unlocks the door inside the room." << endl;
        cout << "You can finally get in." << endl;
        cout << "Your dog is excited about seeing you and you reach the last challenge." << endl;
        finalStage();
    }
    while (option == 1 && !haveG) {
        cout << "You are not staying with the ghost so you can't choose option 1.\n";
        cout << "Please choose option 2 or 3. Will you choose 2 or 3? (2 / 3)\n";
        cin >> option;
    }
    if (option == 2) {
        cout << "You use your body to hit the body until it opens." << endl;
        cout << "You successfully open the door but you are hurt during the calBackjack." << endl;
        cout << "Your CP is decreased by 20." << endl;
        life -= 20;
        cout << "However, you finally see your dog! You reach the last challenge." << endl;
        if (life <= 0) {
            cout << "Your CP is 0. You don't have enough energy to finish the journey." << endl;
            endGame();
        }
        else
            finalStage();
    }
    if (option == 3) {
        cout << "You give up saving your dog." << endl;
        cout << "You hear he is crying but you turn and leave the castle." << endl;
        endGame();
    }
    sleep(2);
}

void withGhost() {
    cout << "Will you invite her to join your adventure? (y: yes / n: no)" << endl;
    char answer;
    cin >> answer;
    cout << endl;
    while (answer != 'y' && answer != 'n') {
        cout << "Invalid Input! Please answer again.\n";
        cout << "Your response: (y: yes / n: no) ";
        cin >> answer;
    }
    if (answer == 'y') {
        cout << "You ask for help from the ghost and she is glad for your invitation." << endl;
        cout << "You two become accompany and continue the journey together." << endl;
        bag.push_back("ghost");
    }
    if (answer == 'n') {
        cout << "The ghost thinks you just act like the other people abandoning her." << endl;
        cout << "She is angry so she slaps your right on your face and rans away." << endl << endl;
        life -= 10;
        cout << "Your CP is decreased by 10. It is very close to save your dog!" << endl;
    }
    if (life <= 0)
        endGame();
}

void castleGhost() {
    cout << endl;
    char word[] = "The ghost said, \"I am so bored. I want you to play a game with me.\" \n"
        "\"How about you choose a number between 1 and 10? \" \n"
        "You have no choice and you have to play with her. \n";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }

    int guessNum;
    cout << "Please choose a number (1 - 10): " << endl;
    cin >> guessNum;
    cout << endl;
    if (guessNum % 2 == 0) {
        char even[] = "The ghost said, \"I love even number! Everything is so perfect when it is even.\" \n";
        for (int j = 0; j < sizeof(even); j++) {
            cout << even[j];
            usleep(3000);
        }
        cout << endl << "The ghost is happy and satisfied. You feel sad for her for being alone all the time." << endl;
        withGhost();
    }
    else if (guessNum % 2 != 0) {
        char odd[] = "The ghost said, \"I hate odd number!!! I hate to be alone!!!\" \n"
            "\"Why everybody left me here and escape from me by all mean.\" \n" 
            "\"I hate you!!!!!!\"";
        for (int k = 0; k < sizeof(odd); k++) {
            cout << odd[k];
            usleep(3000);
        }
        cout << endl << "The ghost is furious and she attacks you." << endl;
        cout << "You cannot see that happened and you get hurt seriously." << endl;
        cout << endl;
        life -= 30;
        cout << "Your CP is decreased by 30. It is very close to save your dog!" << endl;
        if (life <= 0) {
            cout << "Your CP is 0. You don't have enough energy to finish the journey." << endl;
            endGame();
        }
    }
    castleDoor();
}

void castle() {
    show();
    cout << endl;
    char word[] = "You use the key to enter the castle. \n"
        "The castle is enormous and you almost get lost in there. \n"
        "Something suddenly comes out and scared you a lot.\n"
        "You find out that she is a ghost.\n";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }
    castleGhost();
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
    srand(time(NULL));
    int rnum = rand() % 3;
    string hereWord = guessWord[rnum];

    string userAnswer;
    int trial = 0;
    bool correct = false;
    if (userAnswer == hereWord)
        correct = true;
    cout << endl;

    while ((!correct) && (trial != 3)) {
        cout << endl;
        if (hereWord == "treasure") {
            if (trial == 0) {
                cout << "< 7 words >" << endl;
                cout << "1st Tip: valuable" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
            if (trial == 1) {
                cout << "Wrong Guess!" << endl;
                cout << "2nd Tip: always involove in stories about pirates" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
            if (trial == 2) {
                cout << "Wrong Guess!" << endl;
                cout << "3rd Tip: example like money, gold" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
        }

        if (hereWord == "puppy") {
            if (trial == 0) {
                cout << "< 5 words >" << endl;
                cout << "1st Tip: animal" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
            if (trial == 1) {
                cout << "Wrong Guess!" << endl;
                cout << "2nd Tip: little baby" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
            if (trial == 2) {
                cout << "Wrong Guess!" << endl;
                cout << "3rd Tip: a kind of pet" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
        }

        if (hereWord == "halloween") {
            if (trial == 0) {
                cout << "< 9 words >" << endl;
                cout << "Tip: festival" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }

            if (trial == 1) {
                cout << "Wrong Guess!" << endl;
                cout << "Tip: candy" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
            if (trial == 2) {
                cout << "Wrong Guess!" << endl;
                cout << "Tip: no holiday" << endl;
                cout << "Your guess is: " << endl;
                cin >> userAnswer;
                trial += 1;
                if (userAnswer == hereWord) {
                    correct = true;
                    break;
                }
            }
        }
    }
    cout << endl;
    if (correct) {
        char con[] = "Congraduations! Your answer is correct! Awesome. \n"
            "You can use your key to go into the castle now.\n";
        for (int j = 0; j < sizeof(con); j++) {
            cout << con[j];
            usleep(3000);
        }
        castle();
    }
    if (!correct) {
        cout << endl << "You fail to guess the right word." << endl;
        cout << "The answer should be " << hereWord << endl;
        endGame();
    }
    cout << endl;
}

void castleIn() {
    show();
    cout << endl;
    char word[] = "You finally reach the castle, where your dog is in there. \n"
        "You walk to the door and find out that there is a huge lock. You need a key to open it.\n"
        "Do you have a key? (y: yes / n: no) \n";
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
        if (*find == "key" && input == 'y') 
            haveKey = true;
        else 
            haveKey = false;
        
    }
    if (haveKey) {
        cout << "Woohooo~ You successfully use the key to get in the castle." << endl;
        cout << "You are ready to save your dog!" << endl;
        castle();
    }
    else {
        cout << "An elf jumps out and said, \"Sad for you, " << name << ".\" \n";
        cout << "\"Seems you got no key in hand. Do you want a last choice to get the key?\"" << endl;
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
    cout << endl;
}

// monsterPlay

struct monsterposition{
    int minx, miny, maxx, maxy;
};
monsterposition mp;

struct ballotposition{
    int mina, minb, maxa, maxb;
};
ballotposition bp;

void monsterpos(int &p, int &q, int &r, int &s)
{
    int sizeofmonster = 40;
    srand(time(NULL));
    int a=rand()%100, b=rand()%100;
    p = a - (sizeofmonster/2);
    q = b - (sizeofmonster/2);
    r = a + (sizeofmonster/2);
    s = b + (sizeofmonster/2);
}
void ballotpos(int &p,int &q,int &r,int &s,int &c,int &d){
    int sizeofballot = 30;
    p = c - (sizeofballot/2);
    q = d - (sizeofballot/2);
    r = c + (sizeofballot/2);
    s = d + (sizeofballot/2);
}

bool IsOverlap(monsterposition p, ballotposition q) {
  if ( p.minx > q.maxa || p.miny > q.maxb || q.mina > p.maxx || q.minb > p.maxy){
    return false;
  }
  else{
    return true;
  }
}

void shoot(){
    show();
    cout << endl;
    char word[] = "Now a monster bird is in front of you. This monster bird is invisible but its body is big. \n"
    "You get a cannon. The cannon contains 5 ballots and you can use it to shoot to any position.\n"
    "Successfully hitting the monster is an advantage for your adventure journey.\n"
    "The monster is 40cm x 40cm while your ballot is 30cm x 30cm.\n"
    "Imagine there is a grid in front of you with x-axis (0-100) and y-axis (0-100).\n"
    "Please input a pair of numbers indicating x-axis and y-axis of the center to show you location of your shooting target.\n";

    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(10000);
    }
    
    int c,d;
    cout << "x-axis & y-axis: ";
    cin >> c >> d;
    monsterpos(mp.minx, mp.miny, mp.maxx, mp.maxy);
    ballotpos(bp.mina, bp.minb, bp.maxa, bp.maxb,c,d);
    
    if (IsOverlap(mp,bp)) {
        cout << "You win! You get a key on the hand of the monster. " << endl;
        bag.push_back("key");
    }

    int trial = 1;
    while (!IsOverlap(mp,bp)){
        cout << "You fail to hit the monster! You lose 10 CP. Please try again." << endl;
        life -= 10;
        cout << "x-axis & y-axis: ";
        cin >> c >> d;
        monsterpos(mp.minx, mp.miny, mp.maxx, mp.maxy);
        ballotpos(bp.mina, bp.minb, bp.maxa, bp.maxb,c,d);
        if (IsOverlap(mp,bp)){
            cout << "You win! You get a key on the hand of the monster. " << endl;
            bag.push_back("key");
        }
        else {
            trial += 1;
        }
        if (trial == 5) {
            life -= 10;
            cout << endl << "You fail to hit the monster and it flies away." << endl;
            break;
        }
    }
    cout << endl <<"These numbers indicate the position of the monster bird"<<endl;
    cout << "Top right corner:   x-max = " << mp.maxx << " ; y-max = " << mp.maxy << endl;
    cout << "Bottom left corner: x-min = " << mp.minx << " ; y-max = " << mp.miny << endl << endl;
    cout<<"These number are the explosion range of your cannon"<<endl;
    cout << "Top right corner:   x-max = " << bp.maxa << " ; y-max = " << bp.maxb << endl;
    cout << "Bottom left corner: x-min = " << bp.mina << " ; y-max = " << bp.minb << endl;
    cout << endl << "Your CP now is " << life << ". " << endl;
    if (life <= 0) {
        cout << "Your CP is 0. You don't have enough energy to finish the journey." << endl;
        endGame();
    }
    castleIn();
}

// wolf

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
    cout << endl;
    if (life <= 0) {
        cout << "Your CP is 0. You don't have enough energy to finish the journey." << endl;
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

// path

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
    srand(time(NULL));
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
        cout << "You are unhappy and frustrated so you hit on a tree and pass out." << endl << endl;
        cout << "You lose 20 CP." << endl;
        life -= 20;
        bag.pop_back();
    }
    cout << endl;
    if (life <= 0) {
        cout << "Your CP is 0. You don't have enough energy to finish the journey." << endl;
        endGame();
    }
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
    cout << endl;
    if (life <= 0) {
        cout << "Your CP is 0. You don't have enough energy to finish the journey." << endl;
        endGame();
    }
    wolf();
}

void folk() {
    char input;
    char word[] = "You just walk into the forest and meet your first folk in the road (literally).\n"
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

// start

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

// main

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
