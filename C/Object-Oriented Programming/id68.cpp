#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef double db;
#define int long long

void QAQ()
{
    char op;
    int len;
    cin >> op >> len;
    if (op == 'I')
    {
        int *p = new int[len];
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            cin >> p[i];
            sum += p[i];
        }
        cout << (float)sum / len << endl;
        delete[] p;
    }
    else if (op == 'C')
    {
        char *p = new char[len];
        char *maxx;
        int m = 0;
        for (int i = 0; i < len; i++)
        {
            cin >> p[i];
            if (p[i] > m)
            {
                maxx = p + i;
                m = max(m, (int)p[i]);
            }
        }
        cout << *maxx << endl;
        delete[] p;
    }
    else if (op == 'F')
    {
        float *p = new float[len];
        float minn = 0x3f3f3f;
        for (int i = 0; i < len; i++)
        {
            cin >> p[i];
            if (p[i] < minn)
            {
                minn = min(minn, p[i]);
            }
        }
        cout << minn << endl;
        delete[] p;
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