#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Remote;

class Tv
{
private:
    int state; // 0=off,1=on
    int volume;
    int maxchannel;
    int channel;
    int mode;  // 0=Cable,1=Antenna
    int input; // 0=VCR,1=TV

public:
    Tv(int s, int v, int c, int mc, int m, int i)
    {
        state = s;
        volume = v;
        channel = c;
        maxchannel = mc;
        mode = m;
        input = i;
    }
    void onoff()
    {
        state = !state;
    }
    bool ison() const
    {
        if (state)
            return 1;
        else
            return 0;
    }
    bool volup()
    {
        if (volume < 20)
        {
            volume++;
            return 1;
        }
        else
            return 0;
    }
    bool voldown()
    {
        if (volume > 0)
        {
            volume--;
            return 1;
        }
        else
            return 0;
    }
    void chanup() { channel++; }
    void chandown() { channel--; }
    void set_mode() { mode = !mode; }
    void set_input() { input = !input; }
    void settings() const
    {
        cout << (state ? "on" : "off") << " " << volume << " " << channel << " " << (mode ? "Antenna" : "Cable") << " " << (input ? "TV" : "VCR") << endl;
    }
    friend Remote;
};

class Remote // 遥控器类
{
public:
    bool volup(Tv &t) { return t.volup(); }
    bool voldown(Tv &t) { return t.voldown(); }
    void onoff(Tv &t) { t.onoff(); }
    void chanup(Tv &t) { t.chanup(); }
    void chandown(Tv &t) { t.chandown(); }
    void set_chan(Tv &t, int c) { t.channel = c; }
    void set_mode(Tv &t) { t.set_mode(); }
    void set_input(Tv &t) { t.set_input(); }
};

map<string, int> mp{{"volup", 0}, {"voldown", 1}, {"onoff", 2}, {"chanup", 3}, {"chandown", 4}, {"set_chan", 5}, {"set_mode", 6}, {"set_input", 7}};

void QAQ()
{
    string onf, mode, input;
    int volume, channel;
    cin >> onf >> volume >> channel >> mode >> input;
    Tv tv(onf[1] == 'n', volume, channel, 100, mode[0] == 'A', input[0] == 'T');
    Remote r;
    string op;
    while (cin >> op)
    {
        switch (mp[op])
        {
        case 0:
            if (tv.ison())
                r.volup(tv);
            break;
        case 1:
            if (tv.ison())
                r.voldown(tv);
            break;
        case 2:
            r.onoff(tv);
            break;
        case 3:
            if (tv.ison())
                r.chanup(tv);
            break;
        case 4:
            if (tv.ison())
                r.chandown(tv);
            break;
        case 5:
            if (tv.ison())
            {
                int c;
                cin >> c;
                r.set_chan(tv, c);
            }
            break;
        case 6:
            if (tv.ison())
                r.set_mode(tv);
            break;
        case 7:
            if (tv.ison())
                r.set_input(tv);
            break;
        default:
            break;
        }
    }
    tv.settings();
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    //    cin>>t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}