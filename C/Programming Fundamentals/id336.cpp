#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main()
{
    int a;
    while (1)
    {
        cin >> a;
        if (a == -1)
            break;
        int temp = a;
        while (temp)
        {
            if (temp % 10 % 2)
                break;
            temp /= 10;
        }
        if (!temp)
            v.push_back(a);
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    cout.width(4);
    cout.fill('0');
    for (auto i : v)
        cout << i << endl;
    return 0;
}