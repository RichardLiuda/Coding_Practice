#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

map<string, int> mp{{"PG", 0}, {"SG", 1}, {"SF", 2}, {"PF", 3}, {"C", 4}};
vector<string> v{"PG", "SG", "SF", "PF", "C"};

class Player
{
private:
    string name, pos;
    int rate;
    static int count[5];

public:
    Player(string name, string pos, int rate)
    {
        this->name = name;
        this->pos = pos;
        this->rate = rate;
        count[mp[pos]]++;
    }
    void show()
    {
        cout << "Name:" << name << " "
             << "Position:" << pos << " "
             << "Rate:" << rate << endl;
    }
    static void showcnt()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Total " << v[i] << " Player:" << count[i] << endl;
        }
    }
};

int Player::count[5] = {0};

void QAQ()
{
    string name, pos;
    int rate;
    while (cin >> name)
    {
        if (name == "0")
            break;
        cin >> pos >> rate;
        Player p(name, pos, rate);
        p.show();
    }
    cout << endl;
    Player::showcnt();
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