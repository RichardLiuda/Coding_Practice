#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

int main()
{
    int T;
    cin >> T;
    ans.resize(T);
    for (int i = 0; i < T; i++)
    {
        int a;
        int cnt = 8;
        while (cnt--)
        {
            cin >> a;
            ans[i].push_back(a);
        }
    }
    for (int i = 0; i < T; i++)
    {
        for (auto it : ans[i])
        {
            if (it < 0)
            {
                cout << it << " ";
            }
        }
        for (auto it : ans[i])
        {
            if (it == 0)
            {
                cout << it << " ";
            }
        }
        for (auto it : ans[i])
        {
            if (it > 0)
            {
                cout << it << " ";
            }
        }
        cout << endl;
    }
    return 0;
}