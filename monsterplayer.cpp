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

int ballotpos(int &p,int &q,int &r,int &s,int &c,int &d){
    int sizeofballot=50;
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

int main(){
  int c,d;
  cin>>c>>d;
  monsterpos(mp.minx, mp.miny, mp.maxx, mp.maxy);
  ballotpos(bp.mina, bp.minb, bp.maxa, bp.maxb,c,d);
  cout<<IsOverlap(mp,bp)<<endl;
  cout<<mp.minx<<' '<<mp.miny<<endl;
  cout<<mp.maxx<<' '<<mp.maxy<<endl;
  cout<<bp.mina<<' '<<bp.minb<<endl;
  cout<<bp.maxa<<' '<<bp.maxb<<endl;
}
