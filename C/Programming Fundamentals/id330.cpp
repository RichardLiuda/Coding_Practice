#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main()
{
    int m, n;
    cin >> m;
    int a[m];
    for (int i = 0; i < m; i++)
        cin >> a[i];
    cin >> n;
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int c[m + n];
    int p = 0, q = 0, cnt = 0;
    while (p < m && q < n)
    {
        if (a[p] < b[q])
            c[cnt++] = a[p++];
        else
            c[cnt++] = b[q++];
    }
    while (p < m)
        c[cnt++] = a[p++];
    while (q < n)
        c[cnt++] = b[q++];
    for (int i = 0; i < cnt; i++)
        cout << c[i] << " ";
    cout << endl;
    return 0;
}
