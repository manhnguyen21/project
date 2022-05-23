#include "SDL_untils.h"
extern Ships rShip[6];
SDL_Texture* aim;
SDL_Texture* table;
SDL_Texture* redtable;
SDL_Texture* intro;
SDL_Texture* paper;
SDL_Texture* yourteam;
SDL_Texture* enemyteam;
SDL_Texture* tau1;
SDL_Texture* tau2;
SDL_Texture* tau3;
SDL_Texture* tau4;
SDL_Texture* tau5;
SDL_Texture* playButton1;
SDL_Texture* playButton2;
SDL_Texture* quitButton1;
SDL_Texture* quitButton2;
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0;
    window = SDL_CreateWindow("Ban Tau", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void close()
{
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;

    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;
    IMG_Quit();
    SDL_Quit();
}
void randShip(int i)
{
    int randX = ((rand()*rand()) % 10 ) + 1;
    int randY = ((rand()*rand()) % 10 ) + 1;
    int randRotate = rand() % 2;
    if(randRotate)
        randX = std::max(1,randX - (SHIP_SIZE[i] - 1));
    else
        randY = std::max(1,randY - (SHIP_SIZE[i] - 1));
    rShip[i].Roratory = randRotate;
    rShip[i].SetPosition(randX,randY);
}
bool checkShip(int i) // xem co bi de len tau khac hay khong
{
    if(!rShip[i].x)
        return false;
    int u = rShip[i].x;
    int v = rShip[i].y;
    if(rShip[i].Roratory)
    {
        FOR(j,0,SHIP_SIZE[i] - 1) if(iMark[u + j][v])
            return false;
        FOR(j,0,SHIP_SIZE[i] - 1) iMark[u + j][v] = i;
    }
    else
    {
        FOR(j,0,SHIP_SIZE[i] - 1) if(iMark[u][v + j])
            return false;
        FOR(j,0,SHIP_SIZE[i] - 1) iMark[u][v + j] = i;
    }
    return true;
}

void createLeftMap()
{
    for(int i = 5; i >= 1; i--)
    {
        randShip(i);
        while(!checkShip(i))
        {
            randShip(i);
        }
    }
    FOR(i,1,10)
    FOR(j,1,10)
    {
        lButton[_ID(i,j)].mark = iMark[i][j];
    }
//    FOR(i,1,10)
//    {
//        FOR(j,1,10)
//        std::cout << iMark[i][j]<<' ';
//        std::cout<<std::endl;
//    }
}
void loadMedia()
{
    SDL_Texture *backGround = loadTexture("image/background.png");
    table = loadTexture("image/table.png");
    redtable = loadTexture("image/redtable.png");
    aim = loadTexture("image/aim.png");
    tau1 = loadTexture("image/tau1.png");
    tau2 = loadTexture("image/tau2.png");
    tau3 = loadTexture("image/tau3.png");
    tau4 = loadTexture("image/tau4.png");
    tau5 = loadTexture("image/tau5.png");
    fire1 = loadTexture("image/fire1.png");
    yourteam = loadTexture("image/yourteam.png");
    enemyteam = loadTexture("image/enemyteam.png");
    renderTexture(backGround,gRenderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
    renderTexture(yourteam,gRenderer,700,600,400,170);
    renderTexture(enemyteam,gRenderer,100,630,400,130);
    gSpriteClips[ 0 ].x = 0;
    gSpriteClips[ 0 ].y = 0;
    gSpriteClips[ 0 ].w = 50;
    gSpriteClips[ 0 ].h = 50;

    gSpriteClips[ 1 ].x = 50;
    gSpriteClips[ 1 ].y = 0;
    gSpriteClips[ 1 ].w = 50;
    gSpriteClips[ 1 ].h = 50;

    gSpriteClips[ 2 ].x = 0;
    gSpriteClips[ 2 ].y = 50;
    gSpriteClips[ 2 ].w = 50;
    gSpriteClips[ 2 ].h = 50;

    gSpriteClips[ 3 ].x = 50;
    gSpriteClips[ 3 ].y = 50;
    gSpriteClips[ 3 ].w = 50;
    gSpriteClips[ 3 ].h = 50;
    FOR(i,1,10)
    FOR(j,1,10)
    {
        renderTexture(table,gRenderer,67+(i-1)*BUTTON_SIZE,140+(j-1)*BUTTON_SIZE,BUTTON_SIZE,BUTTON_SIZE);
        renderTexture(table,gRenderer,634+(i-1)*BUTTON_SIZE,140+(j-1)*BUTTON_SIZE,BUTTON_SIZE,BUTTON_SIZE);
    }
    SDL_RenderPresent(gRenderer);
    FOR(i,1,10)
    FOR(j,1,10)
    {
        lButton[(i - 1)*10 + j].setPosition(67+(j-1)*BUTTON_SIZE,140+(i-1)*BUTTON_SIZE);
        rButton[(i - 1)*10 + j].setPosition(634+(j-1)*BUTTON_SIZE,140+(i-1)*BUTTON_SIZE);
        rButton[(i - 1)*10 + j].x = i;
        rButton[(i - 1)*10 + j].y = j;
        rButton[(i - 1)*10 + j]._right = true;
    }
}
void newGame()
{
    stk.clear();
    _fired = false;
    FOR(i,1,10)
    FOR(j,1,10)
    {
        iMark[i][j] = 0;
        bOke[i][j] = 0;
    }
    bCount = 0;
    _count = 5;
    FOR(i,1,100)
    {
        rButton[i].checked = false;
        lButton[i].checked = false;
        rButton[i]._right = false;
        lButton[i]._right = false;
        rButton[i]._lock = false;
        lButton[i]._lock = false;
        rButton[i].fire = 0;
        lButton[i].fire = 0;
        rButton[i].ship = 0;
        lButton[i].ship = 0;
        rButton[i]._right = true;
    }
    FOR(i,1,5)
    {
        _rotate[i] = false;
        _pre[i] = false;
        rShip[i].stackShip = 0;
        rShip[i].Roratory = false;
        rShip[i]._set = false;
        rShip[i].fire = false;
    }
    SDL_Texture *backGround = loadTexture("image/background.png");
    renderTexture(backGround,gRenderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
    renderTexture(yourteam,gRenderer,700,600,400,170);
    renderTexture(enemyteam,gRenderer,100,630,400,130);
    FOR(i,1,10)
    FOR(j,1,10)
    {
        renderTexture(table,gRenderer,67+(i-1)*BUTTON_SIZE,140+(j-1)*BUTTON_SIZE,BUTTON_SIZE,BUTTON_SIZE);
        renderTexture(table,gRenderer,634+(i-1)*BUTTON_SIZE,140+(j-1)*BUTTON_SIZE,BUTTON_SIZE,BUTTON_SIZE);
    }
}
void loadMenu()
{
    SDL_Texture *backGroundMenu = loadTexture("image/background_menu.png");
    playButton1 = loadTexture("image/playbutton1.png");
    playButton2 = loadTexture("image/playbutton2.png");
    quitButton1 = loadTexture("image/quitbutton1.png");
    quitButton2 = loadTexture("image/quitbutton2.png");
    intro = loadTexture("image/intro.png");
    paper = loadTexture("image/paper1.png");
    renderTexture(backGroundMenu,gRenderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
    mButton[1].setPosition(220,650,300,80);
    mButton[2].setPosition(700,650,300,80);
    mButton[1].id = 1;
    mButton[1].quit = false;
    mButton[2].id = 2;
    SDL_RenderPresent(gRenderer);
}
void loadRematch(bool win)
{
    SDL_Texture *game;
    if(win)
        game = loadTexture("image/victory.png");
    else
        game = loadTexture("image/defeat.png");
    playButton1 = loadTexture("image/playbutton1.png");
    playButton2 = loadTexture("image/playbutton2.png");
    quitButton1 = loadTexture("image/quitbutton1.png");
    quitButton2 = loadTexture("image/quitbutton2.png");
    renderTexture(game,gRenderer,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
    reButton[1].setPosition(220,650,300,80);
    reButton[2].setPosition(700,650,300,80);
    reButton[1].id = 1;
    reButton[1].quit = false;
    reButton[2].quit = false;
    reButton[2].id = 2;
    SDL_RenderPresent(gRenderer);
}

