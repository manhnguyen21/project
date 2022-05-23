#include "Ships.h"
using namespace std;
void Ships::onFire(int mark)
{
    std::string ss = "tau";
    ss = "image/" + ss + char('0' + mark) + ".png";
    SDL_Texture* tau = loadTexture(ss);
    if(Roratory)
    {
        FOR(i,x,x + SHIP_SIZE[mark] - 1)
        {
            renderTexture(table,gRenderer,lButton[_ID(i,y)].posX,lButton[_ID(i,y)].posY,BUTTON_SIZE,BUTTON_SIZE);
        }
        SDL_Point point = {0,0};
        renderTextureRotate(tau,gRenderer,point,posY + BUTTON_SIZE,posX,BUTTON_SIZE*SHIP_SIZE[mark],BUTTON_SIZE);
        FOR(i,x,x + SHIP_SIZE[mark] - 1)
        {
            SDL_Rect* currentClip = &gSpriteClips[ frame / 4 ];
            fire_render( lButton[_ID(i,y)].posX, lButton[_ID(i,y)].posY, currentClip );
        }
    }
    else
    {
        FOR(i,y,y + SHIP_SIZE[mark] - 1)
        {
            renderTexture(table,gRenderer,lButton[_ID(x,i)].posX,lButton[_ID(x,i)].posY,BUTTON_SIZE,BUTTON_SIZE);
        }
        renderTexture(tau,gRenderer,posY,posX,BUTTON_SIZE*SHIP_SIZE[mark],BUTTON_SIZE);
        FOR(i,y,y + SHIP_SIZE[mark] - 1)
        {
            SDL_Rect* currentClip = &gSpriteClips[ frame / 4 ];
            fire_render( lButton[_ID(x,i)].posX, lButton[_ID(x,i)].posY, currentClip );
        }
    }
}
void Ships::SetPosition(int u,int v)
{
    x = u;
    y = v;
    posX = 140 + (x - 1) * BUTTON_SIZE;
    posY = 67 + (y - 1) * BUTTON_SIZE;
}

