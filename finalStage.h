// finalStage.h
#ifndef FINALSTAGE_H
#define FINALSTAGE_H

// char array poker is used to indicate the poker card held by the player
// int array pokerNum is used to indicate the face value of the poker
// maxNumOfPoker is 5 which is the maximum number of card owned bu the player
char poker[13] = {'A','2','3','4','5','6','7','8','9','x','J','Q','K'};
int pokerNum[13] = {1,2,3,4,5,6,7,8,9,10,10,10,10};
const int maxNumOfPoker = 5;

struct player;
void calBlackjack(int num, char number[maxNumOfPoker], char a, int *mina, int *maxa, int *minto, int *maxto);
void blackjack();
void finalStage();

#endif
