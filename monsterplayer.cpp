#include <iostream>

using namespace std;

struct monsterposition{
    int minx;
    int miny;
    int maxx;
    int maxy;
}

monsterposition mp;

struct ballotposition{
    int mina;
    int minb;
    int maxa;
    int maxb;
}

ballotposition bp;


int monsterposition(&mp.minx, &mp.miny, &mp.maxx, &mp.maxy)
{
    int sizeofmonster=10;
    srand(time(NULL));
    int a=rand()%100, b=rand()%100;
   mp.minx=a;
   mp.miny=b;
   mp.maxx=a+sizeofmonster;
   mp.miny=b+sizeofmonster;
   return 0;
}

int ballotposition(&bp.mina, &bp.minb, &bp.maxa, &bp.maxb,&c,&d){
    int sizeofballot=1;
    srand(time(NULL));
   bp.mina=c;
   bp.minb=d;
   bp.maxa=c+sizeofmonster;
   bp.minb=d+sizeofmonster;
   return 0;
}

bool IsOverlap(AABB p, AABB q) {
  if ( p.min[X] > q.max[X] || p.min[Y] > q.max[Y] || q.min[X] > p.max[X] || q.min[Y] > p.max[Y]){
    return false;
  }
  else{
    return true;
  }
}
