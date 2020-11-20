#include <iostream>
#include <unistd.h>
#include <string>
#include <vector>
#include "monsterPlay.h"
#include "show.h"
#include "castle.h"
using namespace std;

vector<string> bag;
int life = 100;
//Assume that the monster is a rectangle
//The rectangle has 4 vertices
//Create a structure to store the maximum and minimum x-coordinate and y-coordinates of the 4 vertices of the rectangle respectively 
struct monsterposition{
    int minx, miny, maxx, maxy;
};
monsterposition mp;

//Assume that the ballot is a rectangle
//The rectangle has 4 vertices
//Create a structure to store the maximum and minimum x-coordinate and y-coordinates of the 4 vertices of the rectangle respectively 
struct ballotposition{
    int mina, minb, maxa, maxb;
};
ballotposition bp;

//randomly generate the midpoint of the monster and 
//compute the maximum and minimum x-coordinate and y-coordinates of the 4 vertices of the monster respectively
void monsterpos(int &p, int &q, int &r, int &s)
{
    int sizeofmonster = 50;
    srand(time(NULL));
    int a=rand()%100, b=rand()%100;
    p = a - (sizeofmonster/2);
    q = b - (sizeofmonster/2);
    r = a + (sizeofmonster/2);
    s = b + (sizeofmonster/2);
}

//accept the inputs of the player which indicate the midpoint of the ballot and 
//compute the maximum and minimum x-coordinate and y-coordinates of the 4 vertices of the ballot respectively
void ballotpos(int &p,int &q,int &r,int &s,int &c,int &d){
    int sizeofballot=30;
    p = c - (sizeofballot/2);
    q = d - (sizeofballot/2);
    r = c + (sizeofballot/2);
    s = d + (sizeofballot/2);
}

//To check whether the minimum x-coordiates of one rectangle is higher than the corresponding maximum x-coordinates of another rectangle
//To check whether the minimum y-coordiates of one rectangle is higher than the corresponding maximum y-coordinates of another rectangle
//If yes, it indicate that the two rectangle is not overlapped
//If no, it indicate that the two rectangle is overlapped
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
    "The monster is 50cm x 50cm while your ballot is 30cm x 30cm.\n"
    "Imagine there is a grid in front of you with x-axis (0-100) and y-axis (0-100).\n"
    "Please input a pair of numbers indicating x-axis and y-axis of the center to show you location of your shooting target.\n";

    for (int i = 0; i < sizeof(word); i++) {
        cout << word[i];
        usleep(10000);
    }
    
    int c,d;
    cout << "x-axis: ";
    cin >> c;
    cout << endl << "y-axis: ";
    cin >> d;
    monsterpos(mp.minx, mp.miny, mp.maxx, mp.maxy);
    ballotpos(bp.mina, bp.minb, bp.maxa, bp.maxb,c,d);
    //The player has 5 ballots. 
    //If the 5 ballots all cannot hit the monster, the player will lose
    //If any one of the ballots hit the monster, the player win
    //Tell the player also the position of the ballot and position of the monster
    if (IsOverlap(mp,bp))
        cout << "You win! You get a key on the hand of the monster. " << endl;

    int trial = 1;
    while (!IsOverlap(mp,bp)){
        cout << "You fail to hit the monster! You lose 10 CP. Please try again." << endl;
        life -= 10;
        cout << "x-axis: ";
        cin >> c;
        cout << endl << "y-axis: ";
        cin >> d;
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
    castleIn();
}
