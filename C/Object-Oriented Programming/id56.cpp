#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

struct mark
{
    string name;
    int age, mark;
};

bool cmp(mark a, mark b)
{
    if (a.mark == b.mark)
    {
        if (a.name[0] == b.name[0])
            return a.age < b.age;
        return a.name[0] > b.name[0];
    }
    return a.mark < b.mark;
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
    vector<mark> m(t);
    for (int i = 0; i < t; i++)
    {
        cin >> m[i].name >> m[i].age >> m[i].mark;
    }
    sort(m.begin(), m.end(), cmp);
    for (auto i : m)
        cout << i.name << ' ' << i.age << ' ' << i.mark << endl;
    return 0;
}