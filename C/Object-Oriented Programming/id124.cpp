#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

class huh
{
private:
    int a;

public:
    huh()
    {
        a = 0;
        cout << "Constructed by default, value = " << a << endl;
    }
    huh(int x)
    {
        a = x;
        cout << "Constructed using one argument constructor, value = " << a << endl;
    }
    huh(huh &obj)
    {
        a = obj.a;
        cout << "Constructed using copy constructor, value = " << a << endl;
    }
};

void QAQ()
{
    int op;
    cin >> op;
    if (!op)
        huh a;
    else
    {
        int x;
        cin >> x;
        huh a(x);
        if (op == 2)
            huh b(a);
    }
}

signed main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("in.in", "r", stdin);
    //     freopen("out.out", "w", stdout);
    // #endif
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