#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Tasks
{
    string PID, username;
    char right;
    int time;
    static int rtotal;
    static int wtotal;
    static int lwtime;
    static int crnum;
    static int crans;

public:
    Tasks(string p, string u, char r, int t) : PID(p), username(u), right(r), time(t) {}
    void display()
    {
        cout << "PID-" << PID << " User-" << username << " as a " << (right == 'R' ? "reader" : "writer") << " used time-" << time << endl;
    }
    static void rcnt(Tasks &t);
    // {
    //     if (t.right == 'R')
    //         rtotal += t.time;
    // }
    static void wcnt(Tasks &t);
    // {
    //     if (t.right == 'W')
    //         wtotal += t.time;
    // }
    static void lwcnt(Tasks &t);
    // {
    //     if (t.right == 'W' && t.time > lwtime)
    //         lwtime = t.time;
    // }
    static void crcnt(Tasks &t);
    // {
    //     if (t.right == 'W')
    //     {
    //         crnum = 0;
    //     }
    //     else
    //     {
    //         crnum++;
    //     }
    // }
    static int getrtotal()
    {
        return rtotal;
    }
    static int getwtotal()
    {
        return wtotal;
    }
    static int getlwtime()
    {
        return lwtime;
    }
    static int getcrans()
    {
        return crans;
    }
};

int Tasks::rtotal = 0;
int Tasks::wtotal = 0;
int Tasks::lwtime = 0;
int Tasks::crnum = 0;
int Tasks::crans = 0;

void Tasks::rcnt(Tasks &t)
{
    if (t.right == 'R')
        rtotal += t.time;
}
void Tasks::wcnt(Tasks &t)
{
    if (t.right == 'W')
        wtotal += t.time;
}
void Tasks::lwcnt(Tasks &t)
{
    if (t.right == 'W' && t.time > lwtime)
        lwtime = t.time;
}
void Tasks::crcnt(Tasks &t)
{
    if (t.right == 'W')
    {
        if (crans < crnum)
            crans = crnum;
        crnum = 0;
    }
    else
    {
        crnum++;
    }
}

void QAQ()
{
    while (1)
    {
        string p;
        cin >> p;
        if (p == "0")
            break;
        string u;
        char r;
        int t;
        cin >> u >> r >> t;
        Tasks ta(p, u, r, t);
        Tasks::crcnt(ta);
        Tasks::lwcnt(ta);
        Tasks::rcnt(ta);
        Tasks::wcnt(ta);
        ta.display();
    }
    cout << endl;
    cout << "Total readers' time-" << Tasks::getrtotal() << " with maximum " << Tasks::getcrans() << " readers at the same time" << endl;
    cout << "Total writers' time-" << Tasks::getwtotal() << " with maximum writing time " << Tasks::getlwtime() << endl;
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