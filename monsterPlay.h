// monsterPlay.h
#ifndef MONSTERPLAY_H
#define MONSTERPLAY_H

struct monsterposition;
struct ballotposition;
void monsterpos(int &p, int &q, int &r, int &s);
void ballotpos(int &p,int &q,int &r,int &s,int &c,int &d);
bool IsOverlap(monsterposition p, ballotposition q);
void shoot();

#endif