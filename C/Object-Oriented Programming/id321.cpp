#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
// #define int long long

class CXGraph
{
    int n;

public:
    CXGraph(int n) : n(n) {}
    CXGraph operator++(int)
    {
        if (n == 21)
            return *this;
        CXGraph tmp = *this;
        n += 2;
        return tmp;
    }
    CXGraph &operator++()
    {
        if (n == 21)
            return *this;
        n += 2;
        return *this;
    }
    CXGraph operator--(int)
    {
        if (n == 1)
            return *this;
        CXGraph tmp = *this;
        n -= 2;
        return tmp;
    }
    CXGraph &operator--()
    {
        if (n == 1)
            return *this;
        n -= 2;
        return *this;
    }
    friend ostream &operator<<(ostream &out, const CXGraph &rhs);
};

ostream &operator<<(ostream &out, const CXGraph &rhs)
{
    for (int i = 1; i <= rhs.n; i++)
    {
        for (int j = 1; j <= rhs.n; j++)
        {
            if (i <= (rhs.n + 1) / 2)
            {
                if (j > rhs.n - i + 1)
                    break;
                out << ((j < i) ? ' ' : 'X');
            }
            else
            {
                if (j > i)
                    break;
                out << ((j < rhs.n - i + 1) ? ' ' : 'X');
            }
        }
        out << endl;
    }
    return out;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t, n;
    string command;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--)
    {
        cin >> command;
        if (command == "show++")
            cout << xGraph++ << endl;
        else if (command == "++show")
            cout << ++xGraph << endl;
        else if (command == "show--")
            cout << xGraph-- << endl;
        else if (command == "--show")
            cout << --xGraph << endl;
        else if (command == "show")
            cout << xGraph << endl;
    }
    return 0;
}
