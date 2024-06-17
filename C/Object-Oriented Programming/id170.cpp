#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

// int CCow::num = 0;

class CCow
{
    // static int num;
    static deque<int> year;
    static vector<int> num;

public:
    CCow() {}
    static void calNum()
    {
        for (int j = 0; j < 30; j++)
        {
            int cnt = 0;
            for (auto &y : year)
            {
                y++;
                if (y == 11)
                {
                    year.pop_front();
                    continue;
                }
                if (y >= 4)
                {
                    cnt++;
                }
            }
            for (int i = 0; i < cnt; i++)
            {
                year.push_back(1);
            }
            num[j] = year.size();
            // cout << "num[" << j + 1 << "]" << num[j] << endl;
        }
    }
    static vector<int> getNum()
    {
        return num;
    }
};

deque<int> CCow::year{0};
vector<int> CCow::num(30);

void QAQ()
{
    int t, y;
    cin >> t;
    CCow::calNum();
    for (int i = 0; i < t; i++)
    {
        cin >> y;
        cout << CCow::getNum()[y - 1] << endl;
    }
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
    // cin >> t;
    while (t--)
    {
        QAQ();
    }
    return 0;
}