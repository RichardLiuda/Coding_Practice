#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Song
{
    string singer, title;
    int length;

public:
    Song() { cout << "constructor" << endl; }
    Song(string s, string t, int l) : singer(s), title(t), length(l)
    {
        cout << "constructor" << endl;
    }
    void setSinger(string s)
    {
        singer = s;
    }
    void setTitle(string t)
    {
        title = t;
    }
    void setLength(int l)
    {
        length = l;
    }
    void print()
    {
        cout << singer << "'s song-" << title << " lasts for " << length << " minutes" << endl;
    }
    int getLength()
    {
        return length;
    }
    ~Song() { cout << "destructor" << endl; }
};

int Select(Song s[], int n)
{
    int maxx = 0, ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i].getLength() > maxx)
        {
            maxx = s[i].getLength();
            ans = i;
        }
    }
    return ans;
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
    cin >> t;
    Song *s = new Song[t];
    for (int i = 0; i < t; i++)
    {
        string si, t;
        int l;
        cin >> si >> t >> l;
        s[i].setSinger(si);
        s[i].setTitle(t);
        s[i].setLength(l);
    }
    s[Select(s, t)].print();
    delete[] s;
    return 0;
}