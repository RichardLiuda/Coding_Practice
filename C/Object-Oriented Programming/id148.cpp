#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long
map<int, int> mp{{0, 1}, {1, 0}, {2, -1}, {3, 9}, {4, 8}, {5, 7}, {6, 6}, {7, 5}, {8, 4}, {9, 3}, {10, 2}};
vector<int> v = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

class CID
{
private:
    string id;

public:
    CID(string _id)
    {
        id = _id;
        cout << "construct ID=" << id << endl;
    }
    void update()
    {
        id.insert(6, "19");
        int S = 0;
        for (int i = 0; i < v.size(); i++)
        {
            S += (id[i] - '0') * v[i];
        }
        char c;
        if (mp[S % 11] == -1)
            c = 'X';
        else
            c = mp[S % 11] + '0';
        id.push_back(c);
        cout << "upgrade ID=" << id << endl;
    }
    ~CID()
    {
        cout << "destruct ID=" << id.substr(14, 4) << endl;
    }
};

void QAQ()
{
    string s;
    cin >> s;
    CID cid(s);
    cid.update();
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
    while (t--)
    {
        QAQ();
    }
    return 0;
}