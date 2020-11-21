# include <iostream>
# include <fstream>
# include <unistd.h>
using namespace std;

int life = 100;
void bingo(){
    cout << endl;
    char word[] = "You are tired and you reach the restaurant. \n"
        "In this restaurant, you will have the chance to replenish your CP value. \n"
        "You will play a game and your performance of this game will determine the gain in CP value. \n \n" 
        "There are 25 numbers on the card, arranging in a 5 x 4 manner. \n"
        "The number should be between 1 and 100. \n"
        "The waitress is holding the 20 cards and plays Bingo with you. \n"
        "You have to write 5 groups of number, each group contains 2 numbers. \n"
        "That means there are total 10 numbers inputted by you. \n"
        "We will calculate the sum and difference of each group of numbers.  \n"
        "After inputing the number, each group of number will be displayed as \n"
        "\"1st input\", \"2nd input\", \"Sum of two inputs\", and \"difference of two inputs\" \n"
        "If the number on your card matches the number on the waitress's, 5 CP will be rewarded.  \n";
    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(3000);
    }

    int card[25],user[25];
    srand(time(NULL));
    for (int i = 0; i < 20; i++){
      int a = rand() % 50 + 1;
      card[i] = a;
    }

    int input1, input2, sum, diff;
    for (int i=0;i<5;i++){
        cout << endl << "\"1st input\" & \"2nd input\" of the " << i+1 << " Group: ";
        cin >> input1 >> input2;
        sum = input1 + input2;
        if (input1 > input2){
            diff = input1 - input2;
        }
        else {
            diff = input2 - input1;
        }
        user[4*i] = input1;
        user[4*i+1] = input2;
        user[4*i+2] = sum;
        user[4*i+3] = diff;
    }
    
    cout << endl << "This is the number on our card" << endl;
    for (int i=0;i<20;i++){
        if (i == 3 || i == 7 || i == 11 || i == 15 || i == 19){
            cout<<card[i]<<endl;
        }
        else{
            cout<<card[i]<<" ";
        }
    }

    cout<<endl<<endl;

    int count = 0;

    cout<<"This is the number on your card"<<endl;
    for (int i=0;i<20;i++){
        if (i == 3 || i == 7 || i == 11 || i == 15 || i == 19){
            cout<<user[i]<<endl;
        }
        else{
            cout<<user[i]<<" ";
        }
    }

    cout << endl;
    for (int i=0;i<20;i++){
        for (int j=0;j<20;j++){
            if (card[i]==user[j]){
                count += 1;
            }
        }
    }
    int bonus = count*5;
    life += bonus;
    cout << endl << "There are in total " << count << " match" << endl;
    cout << bonus << " bonus of CP will be rewarded." << endl;
}
