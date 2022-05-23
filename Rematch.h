#ifndef REMATCH_H__
#define REMATCH_H__
#include "Common_Func.h"

class rematchButton
{
public:
    int w,h;
    int posX,posY;
    bool quit;
    int id;
    void handleEvent(SDL_Event* e);
    void render(std::string s);
    void setPosition(int u, int v, int hi, int we)
    {
        posX = u;
        posY = v;
        w = we;
        h = hi;
    }
};

#endif
