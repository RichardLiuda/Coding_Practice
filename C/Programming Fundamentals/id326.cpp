#include <bits/stdc++.h>
using namespace std;

//先偶后奇，数组从小号到大号遍历，遇到奇数就从大号到小号遍历，找到偶数来跟遇到的奇数交换。

vector<vector<int>> ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int sum[n];
    ans.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> sum[i];
        for (int j = 0; j < sum[i]; j++)
        {
            int a;
            cin >> a;
            ans[i].push_back(a);
        }
        for (int k = 0; k < sum[i]; k++)
        {
            if (ans[i][k] % 2)
            {
                for (int j = sum[i] - 1; j >= 0; j--)
                {
                    if (ans[i][j] % 2 == 0 && j > k)
                    {
                        swap(ans[i][j], ans[i][k]);
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << sum[i];
        for (auto it : ans[i])
        {
            cout << " " << it;
        }
        cout << endl;
    }
    return 0;
}