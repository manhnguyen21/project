#ifndef SDL_UNTILS_H_
#define SDL_UNTILS_H_
#include "Common_Func.h"
extern class Button lButton[101];
extern class Button rButton[101];
extern class menuButton mButton[3];
extern class rematchButton reButton[3];
extern class Ships rShip[6];
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void close();
void randShip(int i);
bool checkShip(int i);
void createLeftMap();
void loadMedia();
void loadMenu();
void newGame();
void loadRematch(bool win);
#endif
