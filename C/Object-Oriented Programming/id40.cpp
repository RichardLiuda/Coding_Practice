#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

struct page
{
    int id;
    string ans1, ans2, ans3;
    int rank;
};

struct cheat
{
    int id1, id2, num;
    int rank;
};

int cmp(page *a, page *b)
{
    int len1 = a->ans1.size(), len2 = a->ans2.size(), len3 = a->ans3.size();
    int same = 0;
    for (int i = 0; i < len1; i++)
        if (a->ans1[i] == b->ans1[i])
            same++;
    if (same >= len1 * 0.9)
        return 1;
    same = 0;
    for (int i = 0; i < len2; i++)
        if (a->ans2[i] == b->ans2[i])
            same++;
    if (same >= len2 * 0.9)
        return 2;
    same = 0;
    for (int i = 0; i < len3; i++)
        if (a->ans3[i] == b->ans3[i])
            same++;
    if (same >= len3 * 0.9)
        return 3;
    return 0;
}

bool comp(cheat &a, cheat &b)
{
    return a.rank < b.rank;
}

signed main()
{
    //#ifndef ONLINE_JUDGE
    //    freopen("in.in", "r", stdin);
    //    freopen("out.out", "w", stdout);
    //#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    vector<page> p(t);
    for (int i = 0; i < t; i++)
    {
        cin >> p[i].id >> p[i].ans1 >> p[i].ans2 >> p[i].ans3;
        p[i].rank = i + 1;
    }
    vector<cheat> ans;
    for (int i = 0; i < t; i++)
    {
        for (int j = i + 1; j < t; j++)
        {
            if (cmp(&p[i], &p[j]))
            {
                ans.push_back({p[i].id, p[j].id, cmp(&p[i], &p[j]), p[i].rank});
            }
        }
    }
    sort(ans.begin(), ans.end(), comp);
    for (auto i : ans)
    {
        cout << i.id1 << ' ' << i.id2 << ' ' << i.num << endl;
    }
    return 0;
}