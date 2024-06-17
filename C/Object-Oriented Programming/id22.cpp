#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

struct prop
{
    bool isint = 0;
    bool sym = 0;
    int x, y;
};

int getGCD(int a, int b)
{
    return b == 0 ? a : getGCD(b, a % b);
}

prop addFS(prop &a, prop &b)
{
    if ((a.x * b.y + a.y * b.x) % (a.y * b.y) == 0)
        return {1, 0, (a.x * b.y + a.y * b.x) / (a.y * b.y), 0};
    else if ((a.x * b.y + a.y * b.x) < (a.y * b.y))
        return {0, 0, (a.x * b.y + a.y * b.x), (a.y * b.y)};
    else if (getGCD(a.x * b.y + a.y * b.x, a.y * b.y) == 1)
        return {0, 0, (a.x * b.y + a.y * b.x), (a.y * b.y)};
    return {0, 0, (a.x * b.y + a.y * b.x) / getGCD(a.x * b.y + a.y * b.x, a.y * b.y), (a.y * b.y) / getGCD(a.x * b.y + a.y * b.x, a.y * b.y)};
}

prop subFS(prop &a, prop &b)
{
    bool sym = 0;
    int x = a.x * b.y - a.y * b.x;
    int y = a.y * b.y;
    if (x < 0)
    {
        sym = 1;
        x *= -1;
    }
    int gcd = getGCD(x, y);
    if (x % y == 0)
        return {1, sym, x / y, 0};
    if (gcd != 1)
    {
        x /= gcd;
        y /= gcd;
    }
    return {0, sym, x, y};
}

prop mulFS(prop &a, prop &b)
{
    int x = a.x * b.x;
    int y = a.y * b.y;
    int gcd = getGCD(x, y);
    if (gcd != 1)
    {
        x /= gcd;
        y /= gcd;
    }
    if (y == 1)
        return {1, 0, x, 0};
    return {0, 0, x, y};
}

prop divFS(prop &a, prop &b)
{
    return mulFS(a, {0, 0, b.y, b.x});
}

void printFS(prop &a)
{
    if (a.sym)
        cout << '-';
    if (a.isint)
        cout << a.x << endl;
    else
        cout << a.x << '/' << a.y << endl;
}

istream &separator(istream &is) { return is.ignore(); }

void QAQ()
{
    prop p1, p2;
    cin >> p1.x >> separator >> p1.y;
    cin >> p2.x >> separator >> p2.y;
    printFS(addFS(p1, p2));
    printFS(subFS(p1, p2));
    printFS(mulFS(p1, p2));
    printFS(divFS(p1, p2));
    cout << endl;
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
    while (t--)
    {
        QAQ();
    }
    return 0;
}