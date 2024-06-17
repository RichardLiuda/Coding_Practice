#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class Cat
{
private:
    string name;
    int weigh;

public:
    string getName() { return name; }
    int getWeigh() { return weigh; }
    void set(string name, int weigh)
    {
        this->name = name;
        this->weigh = weigh;
    }
};

signed main()
{
    //#ifndef ONLINE_JUDGE
    //    freopen("in.in", "r", stdin);
    //    freopen("out.out", "w", stdout);
    //#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    Cat *c = new Cat[n];
    for (int i = 0; i < n; i++)
    {
        string name;
        int weigh;
        cin >> name >> weigh;
        c[i].set(name, weigh);
    }
    sort(c, c + n, [](Cat &a, Cat &b)
         { return a.getWeigh() < b.getWeigh(); });
    for (int i = 0; i < n; i++)
    {
        cout << c[i].getName() << " ";
    }
    return 0;
}