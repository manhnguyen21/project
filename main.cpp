#include "Common_Func.h"

using namespace std;
int dem = -1;
const int TOTAL_BUTTONS = 100;
Mix_Music *sMusic = NULL;
Mix_Chunk *sButton = NULL;
Mix_Chunk *sCannon = NULL;
Mix_Chunk *sFire ;
int main( int argc, char* args[] )
{

    srand(time(NULL));
    initSDL(gWindow, gRenderer);
    bool quit = false;
    SDL_Event e;
    createLeftMap();
    loadMenu();
    sMusic = Mix_LoadMUS( "sound/music.wav" );
    sButton = Mix_LoadWAV( "sound/button.wav" );
    sCannon = Mix_LoadWAV( "sound/cannon.wav" );
    sFire = Mix_LoadWAV( "sound/fire.wav" );
    Mix_PlayMusic( sMusic, -1 );
    while(!quit)
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT || mButton[2].quit)
            {
                quit = true;
                close();
            }
            FOR(i,1,2) mButton[i].handleEvent(&e);
            if(mButton[1].quit) {
                Mix_PlayChannel( -1, sButton, 0);
                quit = true;
            }
        }
        SDL_RenderPresent(gRenderer);
    }
    quit = false;
    while(!quit)
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            if(e.type == SDL_QUIT)
            {
                quit = true;
                close();
            }
            if( e.type == SDL_MOUSEBUTTONUP)
            {
                Mix_PlayChannel( -1, sButton, 0);
                quit = true;
            }
        }
        renderTexture(intro,gRenderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        renderTexture(paper,gRenderer,150,50,900,600);
        SDL_RenderPresent(gRenderer);
    }
    quit = false;
    while(!quit)
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            if(e.type == SDL_QUIT)
            {
                quit = true;
                close();
            }
            if( e.type == SDL_MOUSEBUTTONUP)
            {
                Mix_PlayChannel( -1, sButton, 0);
                quit = true;
            }
        }
        renderTexture(intro,gRenderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
        SDL_RenderPresent(gRenderer);
    }
    loadMedia();
    quit = false;
    frame = 1;
    while(!quit)
    {
         if( Mix_PlayingMusic() == 0 )
        {
            //Play the music
            Mix_PlayMusic( sMusic, -1 );
        }
        while( SDL_PollEvent( &e )  )
        {
            if( e.type == SDL_KEYDOWN  && e.key.keysym.sym == SDLK_SPACE)
            {
                Mix_PlayChannel( -1, sButton, 0);
                _rotate[_count] = (1 - _rotate[_count]);
//                cout<< " ROTETE " <<endl;
                continue;
            }
            if(_fired && rcnt != -1)
            {
                Mix_PlayChannel( -1, sCannon, 0);
                if(dem == -1)
                {
                    _bot_shot();
                }
                _fired = false;
                dem++;
                if(dem > stk.size() - 1)
                    _rand_shot();
                else
                    _shot(stk[dem].first,stk[dem].second);
            }
        }
        if(rcnt == 17 || lcnt == 17)
        {
            dem = -1;
            if(rcnt == 17)
                loadRematch(false);
            else
                loadRematch(true);
            rcnt = lcnt = -1;
            SDL_RenderPresent(gRenderer);
            continue;
        }
        if(rcnt == -1 || lcnt == -1)
        {
            FOR(i,1,2)
            {
                reButton[i].handleEvent(&e);
            }
            if(reButton[2].quit)
            {
                quit = true;
                close();
            }
            if(reButton[1].quit)
            {
                rcnt = lcnt = 0;
                reButton[1].quit = false;
                newGame();
                createLeftMap();
            }
            SDL_RenderPresent(gRenderer);
            continue;
        }
        FOR(i,1,100)
        {
            lButton[i].handleEvent(&e);
            rButton[i].handleEvent(&e);
            rButton[i].renderShip();
            if(lButton[i].fire)
            {
                lButton[i].onFire(lButton[i].fire);
            }
            if(rButton[i].fire)
            {
                rButton[i].onFire(rButton[i].fire);
            }
        }
        FOR(i,1,5)
        {
            if(rShip[i].fire)
                rShip[i].onFire(i);
        }
        frame++;
        if( frame / 4 >= 4 )
        {
            frame = 0;
        }
        if( e.type == SDL_QUIT )
        {
            quit = true;
            break;
        }
        SDL_RenderPresent(gRenderer);
    }
    close();

    return 0;
}

