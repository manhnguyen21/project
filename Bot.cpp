#include "Bot.h"

using namespace std;

std::vector<std::pair<int,int> >  stk;
int bOke[11][11];
int bCount = 0;

bool _shot(int x, int y) {
    if(rButton[_ID(x,y)]._lock){
        rcnt++;
        rButton[_ID(x,y)].fire = 2;
        return true;
    }
    else {
        rButton[_ID(x,y)].renderCenter("circle");
        return false;
    }
}

void _rand_shot() {
    while(true) {
        int x = (rand() * rand())%10 + 1;
        int y = (rand() * rand())%10 + 1;
        if(bOke[x][y]) continue;
        _shot(x,y);
        bOke[x][y] = true;
//        cout<<" ranshot" <<x <<' '<<y <<endl;
        break;
    }
}
void dfs(int x,int y) {
//    cout << " dfs " <<x << ' ' <<y <<endl;
    if(bOke[x][y]) return;
    bOke[x][y] = true;
    bCount++;
    if(bCount <= 17) stk.push_back({x,y});
    if(x - 1 > 0 && rButton[_ID(x - 1,y)]._lock) { dfs(x - 1, y);}
    if(x + 1 > 0 && rButton[_ID(x + 1,y)]._lock) { dfs(x + 1, y);}
    if(y - 1 > 0 && rButton[_ID(x,y - 1)]._lock) { dfs(x, y - 1);}
    if(y + 1 > 0 && rButton[_ID(x,y + 1)]._lock) { dfs(x, y + 1);}
    return;
}
void _bot_shot() {
    while(bCount < 17) {
        int x = ((rand()*rand()) % 10 ) + 1;
        int y = ((rand()*rand()) % 10 ) + 1;
        if(bOke[x][y]) continue;
//        cout <<bCount <<  " xy " <<x <<' ' << y <<' '<< endl;
        if(rButton[_ID(x,y)]._lock) {
            dfs(x,y);
        }
        else {
            stk.push_back({x,y});
            bOke[x][y] = true;
        }
    }
}
