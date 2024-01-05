#include <bits/stdc++.h>
using namespace std;

vector<int> v;

struct ans
{
    float ave;
    int lar;
    int sma;
    int pos;
    int neg;
    int max;
    int min;
} ans[11451];

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        cin >> n;
        v.clear();
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }

        int sum = 0;
        ans[i].pos = 0;
        ans[i].neg = 0;
        for (auto it : v)
        {
            sum += it;
            if (it > 0)
                ans[i].pos++;
            else if (it < 0)
                ans[i].neg++;
        }
        ans[i].ave = (float)sum / n;
        sort(v.begin(), v.end());
        for (auto it : v)
        {
            if (it > ans[i].ave)
                ans[i].lar++;
            if (it < ans[i].ave)
                ans[i].sma++;
        }
        ans[i].max = v[n - 1];
        ans[i].min = v[0];
    }
    for (int i = 0; i < T; i++)
    {
        printf("%.2f %d %d\n", ans[i].ave, ans[i].lar, ans[i].sma);
        printf("%d %d\n", ans[i].pos, ans[i].neg);
        printf("max=%d min=%d\n\n", ans[i].max, ans[i].min);
    }
    return 0;
}