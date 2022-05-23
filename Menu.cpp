#include "menu.h"

using namespace std;

void menuButton::handleEvent(SDL_Event* e)
{
    int u,v;
    SDL_GetMouseState(&u,&v);
    bool inside = true;
    if(u <= posX )
        inside = false;
    else if (u >= posX + h)
        inside = false;
    else if (v <= posY )
        inside = false;
    else if (v >= posY + w)
        inside = false;
    if(e->type == SDL_MOUSEMOTION )
    {
        if(inside)
        {
            if(id == 1)
                renderTexture(playButton2,gRenderer,posX,posY,h,w);
            else
                renderTexture(quitButton2,gRenderer,posX,posY,h,w);
        }
        else
        {
            if(id == 1)
                renderTexture(playButton1,gRenderer,posX,posY,h,w);
            else
                renderTexture(quitButton1,gRenderer,posX,posY,h,w);
        }
    }
    if(e->type == SDL_MOUSEBUTTONUP && inside)
    {
        quit = true;
    }
};

