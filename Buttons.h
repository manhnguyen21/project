#ifndef BUTTONS_H_
#define BUTTONS_H_
#include "Common_Func.h"
class Button
{
public:
    int posX, posY;
    bool checked;
    int mark,x,y,fire,ship;
    bool _right,_lock;
    void renderCenter(std::string s);
    void handleEvent (SDL_Event* e);
    void setPosition(int u,int v)
    {
        posX = u;
        posY = v;
    }
    void onFire(int id) ;
    void renderShip();
} ;

#endif
