#include "Common_Func.h"
using namespace std;
SDL_Rect gSpriteClips[4];
SDL_Renderer *gRenderer;
SDL_Texture* fire1;
class Button lButton[101];
class Button rButton[101];
class menuButton mButton[3];
class rematchButton reButton[3];
class Ships rShip[6];
int rcnt,lcnt,frame;
void fire_render( int x, int y, SDL_Rect* clip )
{
    SDL_Rect renderQuad = { x, y, 50, 50 };

    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopy( gRenderer, fire1, clip, &renderQuad );
}
SDL_Texture* loadTexture(string file)
{
    SDL_Texture *texture = nullptr;
    SDL_Surface *loadedImage = IMG_Load(file.c_str());
    texture = SDL_CreateTextureFromSurface(gRenderer, loadedImage);
    SDL_FreeSurface(loadedImage);
    return texture;
}
void _event(int i,SDL_Event e)
{
    lButton[i].handleEvent(&e);
    rButton[i].handleEvent(&e);
}
void renderTexture(SDL_Texture *gTexture, SDL_Renderer *gRenderer, int x, int y, int w, int h)
{
    // Set toa do hinh chu nhat
    SDL_Rect _rect;
    _rect.x = x;
    _rect.y = y;
    _rect.w = w;
    _rect.h = h;
    SDL_RenderCopy(gRenderer, gTexture, NULL, &_rect);
}
void renderTextureRotate(SDL_Texture *gTexture, SDL_Renderer *gRenderer,SDL_Point point,int x, int y, int w, int h)
{
    // Set toa do hinh chu nhat
    SDL_Rect _rect;
    _rect.x = x;
    _rect.y = y;
    _rect.w = w;
    _rect.h = h;
    SDL_RenderCopyEx(gRenderer, gTexture, NULL, &_rect, 90, &point, SDL_FLIP_NONE);
}
