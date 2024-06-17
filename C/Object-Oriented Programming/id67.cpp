#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

const float *rate = new float[4]{6.2619, 6.6744, 0.0516, 0.8065};

void QAQ()
{
    char op;
    cin >> op;
    int i;
    switch (op)
    {
    case 'D':
        i = 0;
        break;
    case 'E':
        i = 1;
        break;
    case 'Y':
        i = 2;
        break;
    case 'H':
        i = 3;
        break;
    default:
        break;
    }
    float x;
    cin >> x;
    cout << fixed << setprecision(4) << x * (*(rate + i)) << endl;
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