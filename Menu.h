#ifndef MENU_H_
#define MENU_H_
#include "Common_Func.h"

class menuButton
{
    int w,h;
    int posX,posY;
public:
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
