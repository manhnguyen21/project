#ifndef COMMON_FUNC_H_
#define COMMON_FUNC_H_
#define _ID(i,j) (i - 1)*10 + j
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#include <random>
#include <chrono>
#include <iostream>
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "SDL_untils.h"
#include "Menu.h"
#include "Ships.h"
#include "Buttons.h"
#include "Bot.h"
#include "Rematch.h"

extern Mix_Chunk *sFire ;
static int iMark[11][11];
extern bool _fired;
extern int rcnt ;
extern int lcnt ;
extern int bOke[11][11];
extern int bCount;
extern int _pre[6];
extern int _count ;
extern int frame ;
extern bool _rotate[6];
extern std::vector<std::pair<int,int> >  stk;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 770;
const int BUTTON_SIZE = 50;
const int SHIP_SIZE[6] = {0,2,3,3,4,5};
extern SDL_Rect gSpriteClips[4];
extern SDL_Texture* aim;
extern SDL_Texture* table;
extern SDL_Texture* redtable;
extern SDL_Texture* intro;
extern SDL_Texture* paper;
extern SDL_Texture* yourteam;
extern SDL_Texture* enemyteam;
extern SDL_Texture* tau1;
extern SDL_Texture* tau2;
extern SDL_Texture* tau3;
extern SDL_Texture* tau4;
extern SDL_Texture* tau5;
extern SDL_Texture* playButton1;
extern SDL_Texture* playButton2;
extern SDL_Texture* quitButton1;
extern SDL_Texture* quitButton2;
extern SDL_Texture* fire1;
static SDL_Texture* gTexture = NULL;
extern SDL_Renderer *gRenderer ;
static SDL_Window *gWindow = NULL;

SDL_Texture* loadTexture(std::string file);
void renderTexture(SDL_Texture *gTexture, SDL_Renderer *gRenderer, int x, int y, int w, int h);
void renderTextureRotate(SDL_Texture *gTexture, SDL_Renderer *gRenderer,SDL_Point point,int x, int y, int w, int h);
void _event(int i,SDL_Event e);
int dice(int a,int b);
void fire_render( int x, int y, SDL_Rect* clip );
#endif
