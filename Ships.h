#ifndef SHIPS_H_
#define SHIPS_H_
#include "Common_Func.h"
class Ships
{
public:
    int x, y, posX, posY, stackShip;
    bool Roratory,_set,fire;
    void SetPosition(int u,int v);
    void onFire(int mark);
} ;

#endif
