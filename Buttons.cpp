#include "Buttons.h"
int _pre[6],_count = 5;
bool _rotate[6];
bool _fired;

using namespace std;

bool check_lock(int x,int y)
{
    FOR(i,1,SHIP_SIZE[_count])
    if(rButton[_ID(x,y + i - 1)]._lock)
        return false;
    return true;
}
bool check_lock_rotate(int x,int y)
{
    FOR(i,1,SHIP_SIZE[_count])
    if(rButton[_ID(x + i - 1,y)]._lock)
        return false;
    return true;
}
void Button::renderCenter(std::string s)
{
    std::string ss = "image/" + s + ".png";
    SDL_Texture* curTexture = loadTexture(ss);
    renderTexture(curTexture,gRenderer,posX,posY,BUTTON_SIZE,BUTTON_SIZE);
}
void Button::onFire(int id)
{
    if(id == 1)
        renderTexture(table,gRenderer,posX,posY,BUTTON_SIZE,BUTTON_SIZE);
    SDL_Rect* currentClip = &gSpriteClips[ frame / 4 ];
    fire_render( posX, posY, currentClip );
}
void Button::renderShip()
{
    if(ship == 0)
        return;
    if(_rotate[ship])
    {
        FOR(i,1,SHIP_SIZE[ship])
        renderTexture(table,gRenderer,rButton[_ID(x + i - 1,y)].posX,rButton[_ID(x + i - 1,y)].posY,BUTTON_SIZE,BUTTON_SIZE);
        SDL_Point point = {0,0};
        if(ship == 1)
        {
            renderTextureRotate(tau1,gRenderer,point,posX + BUTTON_SIZE,posY,BUTTON_SIZE*SHIP_SIZE[ship],BUTTON_SIZE);
            return;
        }
        if(ship == 2)
        {
            renderTextureRotate(tau2,gRenderer,point,posX + BUTTON_SIZE,posY,BUTTON_SIZE*SHIP_SIZE[ship],BUTTON_SIZE);
            return;
        }
        if(ship == 3)
        {
            renderTextureRotate(tau3,gRenderer,point,posX + BUTTON_SIZE,posY,BUTTON_SIZE*SHIP_SIZE[ship],BUTTON_SIZE);
            return;
        }
        if(ship == 4)
        {
            renderTextureRotate(tau4,gRenderer,point,posX + BUTTON_SIZE,posY,BUTTON_SIZE*SHIP_SIZE[ship],BUTTON_SIZE);
            return;
        }
        if(ship == 5)
        {
            renderTextureRotate(tau5,gRenderer,point,posX + BUTTON_SIZE,posY,BUTTON_SIZE*SHIP_SIZE[ship],BUTTON_SIZE);
            return;
        }
    }
    else
    {
        FOR(i,1,SHIP_SIZE[ship])
        renderTexture(table,gRenderer,rButton[_ID(x,y + i - 1)].posX,rButton[_ID(x,y + i - 1)].posY,BUTTON_SIZE,BUTTON_SIZE);
        if(ship == 1)
        {
            renderTexture(tau1,gRenderer,posX,posY,BUTTON_SIZE*SHIP_SIZE[ship],BUTTON_SIZE);
            return;
        }
        if(ship == 2)
        {
            renderTexture(tau2,gRenderer,posX,posY,BUTTON_SIZE*SHIP_SIZE[ship],BUTTON_SIZE);
            return;
        }
        if(ship == 3)
        {
            renderTexture(tau3,gRenderer,posX,posY,BUTTON_SIZE*SHIP_SIZE[ship],BUTTON_SIZE);
            return;
        }
        if(ship == 4)
        {
            renderTexture(tau4,gRenderer,posX,posY,BUTTON_SIZE*SHIP_SIZE[ship],BUTTON_SIZE);
            return;
        }
        if(ship == 5)
        {
            renderTexture(tau5,gRenderer,posX,posY,BUTTON_SIZE*SHIP_SIZE[ship],BUTTON_SIZE);
            return;
        }
    }
}
void Button::handleEvent (SDL_Event* e)
{
    if(e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN)
    {
        int u,v;
        SDL_GetMouseState(&u,&v);
        bool inside = true;
        if(u <= posX )
            inside = false;
        else if (u >= posX + BUTTON_SIZE)
            inside = false;
        else if (v <= posY )
            inside = false;
        else if (v >= posY + BUTTON_SIZE)
            inside = false;
        if(inside && !checked)
        {
            if(e->type == SDL_MOUSEMOTION)
            {
//                cout <<" MOOO" <<endl;
                if(_right)
                {
                    if(_rotate[_count])
                    {
                        if(x + SHIP_SIZE[_count] < 12 && check_lock_rotate(x,y))
                        {
                            SDL_Point point = {0,0};
                            FOR(i,1,SHIP_SIZE[_count])
                            {
                                if(_pre[i] != 0 && !rButton[_pre[i]]._lock)
                                    renderTexture(table,gRenderer,rButton[_pre[i]].posX,rButton[_pre[i]].posY,BUTTON_SIZE,BUTTON_SIZE);
                            }
                            FOR(i,1,SHIP_SIZE[_count])
                            renderTexture(redtable,gRenderer,rButton[_ID(x + i - 1,y)].posX,rButton[_ID(x + i - 1,y)].posY,BUTTON_SIZE,BUTTON_SIZE);
                            if(_count == 1)
                                renderTextureRotate(tau1,gRenderer,point,posX + BUTTON_SIZE,posY,BUTTON_SIZE*SHIP_SIZE[_count],BUTTON_SIZE);
                            else if(_count == 2)
                                renderTextureRotate(tau2,gRenderer,point,posX + BUTTON_SIZE,posY,BUTTON_SIZE*SHIP_SIZE[_count],BUTTON_SIZE);
                            else if(_count == 3)
                                renderTextureRotate(tau3,gRenderer,point,posX + BUTTON_SIZE,posY,BUTTON_SIZE*SHIP_SIZE[_count],BUTTON_SIZE);
                            else if(_count == 4)
                                renderTextureRotate(tau4,gRenderer,point,posX + BUTTON_SIZE,posY,BUTTON_SIZE*SHIP_SIZE[_count],BUTTON_SIZE);
                            else if(_count == 5)
                                renderTextureRotate(tau5,gRenderer,point,posX + BUTTON_SIZE,posY,BUTTON_SIZE*SHIP_SIZE[_count],BUTTON_SIZE);
                            FOR(i,1,SHIP_SIZE[_count])
                            {
                                _pre[i] = _ID(x + i - 1,y);
                            }
                        }
                    }
                    else
                    {
                        if(y + SHIP_SIZE[_count] < 12 && check_lock(x,y))
                        {
                            FOR(i,1,SHIP_SIZE[_count])
                            {
                                if(_pre[i] != 0 && !rButton[_pre[i]]._lock)
                                    renderTexture(table,gRenderer,rButton[_pre[i]].posX,rButton[_pre[i]].posY,BUTTON_SIZE,BUTTON_SIZE);
                            }
                            FOR(i,1,SHIP_SIZE[_count])
                            renderTexture(redtable,gRenderer,rButton[_ID(x,y + i - 1)].posX,rButton[_ID(x,y + i - 1)].posY,BUTTON_SIZE,BUTTON_SIZE);
                            if(_count == 1)
                                renderTexture(tau1,gRenderer,posX,posY,BUTTON_SIZE*SHIP_SIZE[_count],BUTTON_SIZE);
                            else if(_count == 2)
                                renderTexture(tau2,gRenderer,posX,posY,BUTTON_SIZE*SHIP_SIZE[_count],BUTTON_SIZE);
                            else if(_count == 3)
                                renderTexture(tau3,gRenderer,posX,posY,BUTTON_SIZE*SHIP_SIZE[_count],BUTTON_SIZE);
                            else if(_count == 4)
                                renderTexture(tau4,gRenderer,posX,posY,BUTTON_SIZE*SHIP_SIZE[_count],BUTTON_SIZE);
                            else if(_count == 5)
                                renderTexture(tau5,gRenderer,posX,posY,BUTTON_SIZE*SHIP_SIZE[_count],BUTTON_SIZE);
                            FOR(i,1,SHIP_SIZE[_count])
                            {
                                _pre[i] = _ID(x,y + i - 1);
                            }
                        }
                    }
                }
                else
                    renderTexture(aim,gRenderer,posX,posY,BUTTON_SIZE,BUTTON_SIZE);
            }
            else if(e->type == SDL_MOUSEBUTTONDOWN)
            {
//                cout <<" LCICK" <<endl;

                if(e->button.button == SDL_BUTTON_LEFT)
                {
                    if(_right)
                    {
                        if(_rotate[_count])
                        {
                            if(_count > 0 && check_lock_rotate(x,y) && x + SHIP_SIZE[_count] < 12 )
                            {
                                FOR(i,1,SHIP_SIZE[_count])
                                {
                                    rButton[_ID(x + i - 1,y)]._lock = true;
                                }
                                if(_count >= 1)
                                {
                                    ship = _count;
                                    _count--;
                                }
                            }
                        }
                        else
                        {
                            if(_count > 0 && check_lock(x,y) && y + SHIP_SIZE[_count] < 12)
                            {
                                FOR(i,1,SHIP_SIZE[_count])
                                {
                                    rButton[_ID(x,y + i - 1)]._lock = true;
                                }
                                if(_count >= 1)
                                {
                                    ship = _count;
                                    _count--;
                                }
                            }
                        }
                    }
                    else
                    {
                        if(_count == 0)
                        {
                            checked = true;
                            renderTexture(table,gRenderer,posX,posY,BUTTON_SIZE,BUTTON_SIZE);
                            if(!mark)
                            {
                                renderCenter("circle");
                            }
                            else
                            {
                                Mix_PlayChannel( -1, sFire, 0);
                                renderCenter("fire");
                                fire = 1;
                                lcnt++;
                                if(++rShip[mark].stackShip == SHIP_SIZE[mark])
                                {
                                    rShip[mark].fire = true;
                                }
                            }
                            _fired = true;
                        }
                    }
                }
                //
            }
        }
        else
        {
            if(!checked && !_right)
                renderTexture(table,gRenderer,posX,posY,BUTTON_SIZE,BUTTON_SIZE);
        }
    }
}
