#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

static int TVnum = 0, DVDnum = 0;

class Remote;

class Tv
{
    int vol, type, channel;
    static int TVnum, DVDnum;
    friend void remote(Tv &tv, int type, int v, int channel);

public:
    Tv(int v, int type, int channel)
    {
        vol = v;
        this->type = type;
        this->channel = channel;
    }
    void print()
    {
        cout << (type == 1 ? "TV模式" : "DVD模式") << "--频道" << channel << "--音量" << vol << endl;
    }
};

void remote(Tv &tv, int type, int v, int channel)
{
    if (tv.vol + v < 0)
        tv.vol = 0;
    else if (tv.vol + v > 100)
        tv.vol = 100;
    else
        tv.vol += v;
    if (type == 1)
    {
        tv.channel = channel;
        if (tv.type == 2)
        {
            TVnum++;
            DVDnum--;
        }
    }
    else
    {
        tv.channel = 99;
        if (tv.type == 1)
        {
            TVnum--;
            DVDnum++;
        }
    }
    tv.type = type;
    tv.print();
}

// class Remote
// {

// public:
//     void change_vol(Tv &tv, int v);
// };

// void change_vol(Tv &tv, int v)
// {
//     if (tv.vol + v < 0)
//         tv.vol = 0;
//     else if (tv.vol + v > 100)
//         tv.vol = 100;
//     else
//         tv.vol += v;
// }

void QAQ()
{
    int num;
    cin >> num;
    vector<Tv> tvs;
    for (int i = 1; i <= num; i++)
    {
        Tv tv(50, 1, i);
        TVnum++;
        tvs.push_back(tv);
    }
    int n;
    cin >> n;
    while (n--)
    {
        int i, k, x, v;
        cin >> i >> k >> x >> v;
        cout << "第" << i << "号电视机--";
        remote(tvs[i], k, v, x);
    }
    cout << "播放电视的电视机数量为" << TVnum << endl;
    cout << "播放DVD的电视机数量为" << DVDnum << endl;
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