#include <iostream>
#include <unistd.h>
#include <string>
#include "finalStage.h"
#include "show.h"
#include "winGame.h"
#include "endGame.h"
#include "quitGame.h"
#include "stat.h"
using namespace std;

// calculate the minimum value and maximum value of the card according to the poker got by the player
// since getting Ace can count the value as 1 or 11, there will be minimum and maximum value
// minimum and maximum value of the total value of all the cards held by the player to check whether it is fewer than, larger than or equal to 21
void calBlackjack(int num, char number[5], char a, int *mina, int *maxa, int *minto, int *maxto) {
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


// introduce the game "Blackjack" to the player to ensure the player knows how to play the game
// all the cards given to the dealer and player are in random. different round may have different card received.
// the player can choose to hit or stand by know his/her own card value
// once the player finished, it is dealer's turn to show his card to the player and choose hit or stand
// dealer has to hit when the value is smaller than 17, otherwise he has to stand
// if the dealer wins, the player cannot save his/her dog and loses the game
// if the player wins or it is a draw, the player still can win and save the dog, which lead to the end of the game
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
    char UshowPo[5];
    char DshowPo[5];

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
    cout << "\"I have got a ";
    if (dealer.card1 == 'x')
        cout << "10.\"" << endl << endl;
    else 
        cout << dealer.card1 << ".\"" << endl << endl;
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
            break;
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
    if (dealer.mintotal >= 17)
        dealerHits = false;

    while (dealerHits && !Dbust) {
        if (dealer.mintotal == 21 || dealer.maxtotal == 21) {
            dealerWins = true;
            break;
        }
        if (dealer.mintotal >= 17) {
            break;
        }
        if (dealerCard == 2) {
            dealer.card3 = poker[rand() % 13];
            calBlackjack(dealerCard, DshowPo, dealer.card3, &dealer.minVcard3, &dealer.maxVcard3, &dealer.mintotal, &dealer.maxtotal);
        }
        else if (dealerCard == 3) {
            user.card4 = poker[rand() % 13];
            calBlackjack(dealerCard, DshowPo, dealer.card4, &dealer.minVcard4, &dealer.maxVcard4, &dealer.mintotal, &dealer.maxtotal);
        }
        else if (dealerCard == 4) {
            user.card5 = poker[rand() % 13];
            calBlackjack(dealerCard, DshowPo, dealer.card5, &dealer.minVcard5, &dealer.maxVcard5, &dealer.mintotal, &user.maxtotal);
        }
        dealerCard += 1;
        usleep(300000);
        cout << "Hit! Let\'s see what I get. ";
        for (int j = 0; j < dealerCard; j++) {
            if (DshowPo[j] == 'x')
                cout << "10 ";
            else
                cout << DshowPo[j] << " ";
        }
        cout << ". " << endl;
        usleep(300000);
        if (dealer.mintotal < 17)  {
            dealerHits = true;
        }
        if (dealer.mintotal >= 17) {
            dealerHits = false;
            break;
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
    if ((!Ubust) && (!Dbust)) {
        if (!userWins && !dealerWins) {
            if (dealer.mintotal > user.mintotal) {
                cout << "Bad guy said, \"Ha ha ha, you lose little boy. Say bye to your dog.\"" << endl << endl;
                endGame();
            }
            if (dealer.mintotal < user.mintotal) {
                cout << "Bad guy said, \"I can\'t believe that you beat me. No one ever wins me.\"" << endl;
                cout << "\"Okay, fine. You win. You can take your dog away.\"" << endl << endl;
                winGame();
            }
            if (dealer.mintotal == user.mintotal) {
                cout << "Bad guy said, \"Okay... It\'s a draw...\"" << endl;
                cout << "\"But we have make a deal that only playing one round.\"" << endl;
                cout << "\"Fine, lucky you. Just take your dog and go away.\"" << endl << endl;
                winGame();
            } 
        }
        if (userWins && !dealerWins) {
                cout << "Bad guy said, \"I can\'t believe that you beat me. No one ever wins me.\"" << endl;
                cout << "\"Okay, fine. You win. You can take your dog away.\"" << endl << endl;
                winGame();
        }
        if (!userWins && dealerWins) {
            cout << "Bad guy said, \"Ha ha ha, you lose little boy. Say bye to your dog.\"" << endl << endl;
            endGame();
        }
        if (userWins && dealerWins) {
            cout << "Bad guy said, \"Okay... It\'s a draw...\"" << endl;
            cout << "\"But we have make a deal that only playing one round.\"" << endl;
            cout << "\"Fine, lucky you. Just take your dog and go away.\"" << endl << endl;
            winGame();
        }
    }
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
}




// after different paths or challenges, the player finally sees the bad guy who kidnapped the dog
// it drives to the game Blackjack as the final mission
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
    cout << endl;
    level.pop_front();
    cout << "            Press C to continue                  Press Q to quit the game           " << endl;
    char decision;
    cout << "> ";
    cin >> decision;
    if (decision == 'Q')
        quitGame();
    if (decision == 'C')
        blackjack();
}
