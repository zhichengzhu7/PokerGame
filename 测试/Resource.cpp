#include "Resource.h"
int Poker::now = 0;
int Poker::vis[Poker::Card_front_NUM] = { 0 };
void Poker::initPoker()
{
    now = 0;
    memset(vis, 0, sizeof(vis));
}

int Poker::randPoker()
{
    if (now) {
        int tmp = now;
        now = 0;
        return tmp;
    }
    do {
        now = rand() % Card_front_NUM + 1;
    } while (vis[now - 1]);
    vis[now - 1] = 1;
    return now;
}

string Poker::getPokerResPath(int no) {
    return "Resources/"+to_string(no)+".jpg";
}
