#include <bits/stdc++.h>
using namespace std;

int f[514114];

int a[514114], lfa[514114], rfa[514114];
int ans[514114];

int row(int a)
{
    int ans = 0, i = 1;
    while (a > 0)
    {
        a -= i;
        i++;
        ans++;
    }
    return ans;
}

int column(int a)
{
    return a - (row(a) - 1) * row(a) / 2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    f[0] = 0;
    int C;
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        int n;
        cin >> n;
        int N = n * (n + 1) / 2;
        for (int j = 1; j <= N; j++)
        {
            cin >> a[j];
            if (j == 1)
                f[j] = a[j];
            if (column(j) == 1)
                lfa[j] = 0;
            else
                lfa[j] = j - row(j);
            if (column(j) == row(j))
                rfa[j] = 0;
            else
                rfa[j] = j - row(j) + 1;
        }
        for (int j = 2; j <= N; j++)
        {
            f[j] = (max(f[lfa[j]], f[rfa[j]]) + a[j]);
        }
        // for (int j = 1; j <= N; j++)
        // {
        //     cout << "lfa" << j << " = " << lfa[j] << endl;
        //     cout << "rfa" << j << " = " << rfa[j] << endl;
        //     cout << "row" << j << " = " << row(j) << endl;
        //     cout << "column" << j << " = " << column(j) << endl;
        //     cout << "f" << j << " = " << f[j] << endl;
        // }
        int max = 0;
        for (int j = N - n; j <= N; j++)
        {
            if (max < f[j])
                max = f[j];
        }
        ans[i] = max;
    }
    for (int i = 0; i < C; i++)
        cout << ans[i] << endl;
}