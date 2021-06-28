#pragma once
#include <string>
using namespace std;

constexpr char title[] = "PokerGame";

class Poker {
public:
    const static int Card_front_NUM = 52;
    static int now;
    static int vis[Card_front_NUM];
    static void initPoker();
    static int randPoker();
    static string getPokerResPath(int no);
};

constexpr int rows = 5;
constexpr int cols = 4;
const string st_res = "Resources/start.png";
const string ex_res = "Resources/exit.png";
const string re_res = "Resources/return.png";
const string bg_res = "Resources/backgroud.png";
const string bk_res = "Resources/Back.png";
const string sp_res = "Resources/space.png";
const string win_sound = "Resources/win.ogg";
const string st_sound = "Resources/start.ogg";
const string wy_sound = "Resources/wrong.ogg";
const string rt_sound = "Resources/right.ogg";
const string ps_sound = "Resources/press.ogg";
