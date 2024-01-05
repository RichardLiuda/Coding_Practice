#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int flag[n];
    ans.resize(n, vector<int>(10));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int x;
            cin >> x;
            ans[i][j] = x;
        }
        int a;
        cin >> a;
        if (a % 2 && find(ans[i].begin(), ans[i].end(), a) != ans[i].end())
        {
            ans[i].erase(find(ans[i].begin(), ans[i].end(), a));
            flag[i] = 1;
        }
        else if (a % 2 == 0 && find(ans[i].begin(), ans[i].end(), a) == ans[i].end())
        {
            ans[i].resize(11);
            ans[i][10] = a;
            flag[i] = 2;
        }
        else
            flag[i] = 3;
    }
    for (int i = 0; i < n; i++)
    {
        if (flag[i] == 1)
        {
            sort(ans[i].begin(), ans[i].end(), less<int>());
            for (auto it : ans[i])
            {
                if (it == ans[i].back())
                    cout << it << endl;
                else
                    cout << it << " ";
            }
        }
        else if (flag[i] == 2)
        {
            sort(ans[i].begin(), ans[i].end(), greater<int>());
            for (auto it : ans[i])
            {
                if (it == ans[i].back())
                    cout << it << endl;
                else
                    cout << it << " ";
            }
        }
        else
        {
            sort(ans[i].begin(), ans[i].end(), greater<int>());
            int cnt = 0;
            for (auto it : ans[i])
            {
                if (it % 2)
                {
                    cnt++;
                    cout << it << " ";
                    if (cnt == ans[i].size())
                        cout << endl;
                }
            }
            for (auto it : ans[i])
            {
                if (it % 2 == 0)
                {
                    cnt++;
                    cout << it << " ";
                    if (cnt == ans[i].size())
                        cout << endl;
                }
            }
        }
    }
    return 0;
}