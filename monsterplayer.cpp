#include <iostream>

using namespace std;

struct monsterposition{
    int minx;
    int miny;
    int maxx;
    int maxy;
};

monsterposition mp;

struct ballotposition{
    int mina;
    int minb;
    int maxa;
    int maxb;
};

ballotposition bp;


int monsterpos(int &p, int &q, int &r, int &s)
{
    int sizeofmonster=90;
    srand(time(NULL));
    int a=rand()%100, b=rand()%100;
    p=a;
    q=b;
    r=a+sizeofmonster;
    s=b+sizeofmonster;
    return 0;
}
void ballotpos(int &p,int &q,int &r,int &s,int &c,int &d){
    int sizeofballot=30;
    p=c;
    q=d;
    r=c+sizeofballot;
    s=d+sizeofballot;
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
    cout<<"Now a monster bird is in front of you. This monster bird is invisible but its body is big. "<<endl;
    cout<<"You have a cannon and you can use it to shoot to any position"<<endl;
    cout<<"The monster is 90cm x 90cm while your ballot is 50cm x 50cm"<<endl;
    cout<<"Imagine there is a grid in front of you with x-axis (0-100) and y-axis (0-100)"<<endl;
    cout<<"Please input a pair of numbers indicating x-axis and y-axis to show you location of your shooting target"<<endl;
    int c,d;
    cout << "x-axis: ";
    cin >> c;
    cout << endl << "y-axis: ";
    cin >> d;
    monsterpos(mp.minx, mp.miny, mp.maxx, mp.maxy);
    ballotpos(bp.mina, bp.minb, bp.maxa, bp.maxb,c,d);
    if (IsOverlap(mp,bp))
        cout<<"You win! "<<endl;

  while (!IsOverlap(mp,bp)){
    cout<<"You fail to hit the monster! Please try again."<<endl;
    cout << "x-axis: ";
    cin >> c;
    cout << endl << "y-axis: ";
    cin >> d;
    monsterpos(mp.minx, mp.miny, mp.maxx, mp.maxy);
    ballotpos(bp.mina, bp.minb, bp.maxa, bp.maxb,c,d);
    if (IsOverlap(mp,bp)){
      cout<<"You win! "<<endl;
    }
  }
  cout<<"These numbers indicate the position of the monster bird"<<endl;
  cout<<mp.minx<<' '<<mp.miny<<endl;
  cout<<mp.maxx<<' '<<mp.maxy<<endl;
  cout<<"These number are the explosion range of your cannon"<<endl;
  cout<<bp.mina<<' '<<bp.minb<<endl;
  cout<<bp.maxa<<' '<<bp.maxb<<endl;
}
int main(){
  shoot();
}
