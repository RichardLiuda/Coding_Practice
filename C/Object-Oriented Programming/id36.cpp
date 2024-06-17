#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

int func1(int x)
{
    return x * x;
}

float func2(float x)
{
    return sqrt(x);
}

void func3(char *x)
{
    for (char p = 0; p < strlen(x); p++)
    {
        if (x[p] <= 'z' && x[p] >= 'a')
            x[p] = x[p] - 32;
    }
}

void QAQ()
{
    int (*f1)(int) = func1;
    float (*f2)(float) = func2;
    void (*f3)(char *) = func3;
    char op;
    cin >> op;
    if (op == 'S')
    {
        char *s = new char[N];
        cin >> s;
        f3(s);
        cout << s << endl;
    }
    else if (op == 'F')
    {
        float x;
        cin >> x;
        cout << f2(x) << endl;
    }
    else if (op == 'I')
    {
        int x;
        cin >> x;
        cout << f1(x) << endl;
    }
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